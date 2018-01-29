#include <iostream>
#include "ConfigPckgRequest.h"
#include "MeasurementReport.h"
#include "Events.h"
#include "ServiceStartEvent.h"
#include "AMReportPackage.h"
#include "ClientSocket.h"
#include "XmlDomDocument.h"
#include <iostream>
#include "ConfigurationPckgRequestResponse.h"
#include "stdio.h"
#include "stdlib.h"
#include "Algoritmos.h"
#include "EventTrigger.h"
#include <pthread.h>
#include "include/rapidjson/document.h"
#include <unistd.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <net/if.h>
#include "XmlDomDocument.h"

        // std::mutex
using namespace std;
ConfigurationPckgRequestResponse *config = NULL;

std::string localAddress = "127.0.0.1";
std::string serverAddress;

ChannelStop *channelStop = new ChannelStop();
ChannelStart *channelStart = new ChannelStart();
AudioVolume *audioVolume = new AudioVolume();
VideoResize *videoResize = new VideoResize();
VoDEvent *vodEvent = new VoDEvent();

/**evento de serviços**/
LinearChannelStart *linearChannelStart = new LinearChannelStart();
InteractiveApplicationStart *iappStart = new InteractiveApplicationStart();
NativeApplicationStart *natappStart = new NativeApplicationStart();
ServiceRunning *serviceRunning  = new ServiceRunning("none");

std::vector<Events*> commomEvents;
std::vector<ChannelPlaying*> channelsPlaying;
std::vector<VoDPlaying*> videosPlaying;
pthread_mutex_t lock, lock_events, lock_report;

void *clientHandler(void *arg);
void *XmlXchange(void *arg);
void timer();
void *countDown(void *time);
void *midwareCommunication(void *arg);
void MeasurementScheduleControl(const char *json);
void verififyEvents(rapidjson::Document& doc, MeasurementSchedule *msched, int i, int j,AMReportPackage *amr);
void sendReport(AMReportPackage *amreport);
void updateEvents(const char *json);
bool verifyPeriod(MeasurementSchedule *msched);

typedef struct countdown{
    int time;
    int i, j, k;
}Count;

void readConfigs(){
    std::ifstream config;
    config.open("server.conf");
    config >> serverAddress;
    std::cout<<"serveraddress "<<serverAddress<<std::endl;
}
void *clientHandler(void *args){
    int sock = *(int*)args;
    char buffer[1];
    std::string json="";
    while(1){
        memset(buffer ,0 , 1);
        int tamanho = recv(sock, buffer, 1    , 0);
        if(tamanho <= 0 || buffer[0] == '\0'){
            close(sock);
            break;
        }else{

            json += buffer;

        }

    }
    std::cout<<json<<std::endl;



    //std::cout<<json<<std::endl;
    /*int i = 0;

    while(buffer[i] != '\0'){
        //std::cout<<buffer[i]<<std::flush;
        std::string str{buffer[i]};


        i++;
    }
    delete [] buffer;*/
    //json.append('\0');
    //char *json = (char*)malloc(sizeof(char)*(i));
   /* i = 0;
    while(buffer[i] != '\0'){
        json[i] = buffer[i];
        std::cout<<json[i];
        i++;
    }*/
    pthread_mutex_lock(&lock_events);
    updateEvents(json.c_str());
    MeasurementScheduleControl(json.c_str());
    pthread_mutex_unlock(&lock_events);



}
void sendReport(AMReportPackage *amreport){
    pthread_mutex_lock(&lock_report);
    amreport->writeXML();
    ClientSocket *s = new ClientSocket();
    int sock = s->createSocket("8009",serverAddress);
    s->sendFile("AMReportPackage.xml", sock);
    pthread_mutex_unlock(&lock_report);
}

void updateEvents(const char *json){
    rapidjson::Document doc;
    doc.Parse(json);
    if(doc["Events"].HasMember("AudioVolume")){
        if(doc["Events"]["AudioVolume"]["VolumeDirection"].IsString()){
            std::string direction = doc["Events"]["AudioVolume"]["VolumeDirection"].GetString();
            audioVolume->setServiceInstanceID(1);
            if(strcmp(direction.c_str(), "up") == 0){
                audioVolume->setVolumeDirection(AudioVolume::up);
            }else if(strcmp(direction.c_str(), "down") == 0){
                audioVolume->setVolumeDirection(AudioVolume::down);
            }
            audioVolume->setServiceInstanceID(doc["Events"]["AudioVolume"]["ServiceInstanceID"].GetInt());
        }
    }
    if(doc["Events"].HasMember("ChannelStart")){
        int controlDev = doc["Events"]["ChannelStart"]["ControlDevice"].GetInt();
        switch(controlDev){
            case AMFCapabilityProfile::ControlDevice::STB:
                channelStart->setControlDevice(AMFCapabilityProfile::ControlDevice::STB);
                break;
            case AMFCapabilityProfile::ControlDevice::STBKeyboard:
                channelStart->setControlDevice(AMFCapabilityProfile::ControlDevice::STBKeyboard);
                break;
            case AMFCapabilityProfile::ControlDevice::STBRemoteControl:
                channelStart->setControlDevice(AMFCapabilityProfile::ControlDevice::STBRemoteControl);
                break;
            case AMFCapabilityProfile::ControlDevice::TABLET:
                channelStart->setControlDevice(AMFCapabilityProfile::ControlDevice::TABLET);
                break;
            case AMFCapabilityProfile::ControlDevice::MOBILEPHONE:
                channelStart->setControlDevice(AMFCapabilityProfile::ControlDevice::MOBILEPHONE);
                break;
            case AMFCapabilityProfile::ControlDevice::OTHER:
                channelStart->setControlDevice(AMFCapabilityProfile::ControlDevice::OTHER);
                break;
            case AMFCapabilityProfile::ControlDevice::PC:
                channelStart->setControlDevice(AMFCapabilityProfile::ControlDevice::PC);
                break;
        }
        channelStart->setServiceIdentifer(doc["Events"]["ChannelStart"]["ServiceIdentifier"].GetString());
        channelStart->setServiceInstanceID(doc["Events"]["ChannelStart"]["ServiceInstanceID"].GetInt());
        channelStart->setPreviousServiceInstanceID(doc["Events"]["ChannelStart"]["PreviousServiceInstanceID"].GetInt());
        ChannelPlaying *c = new ChannelPlaying();
        c->setServiceIdentifier(channelStart->getServiceIdentifer());
        c->setServiceInstanceID(channelStart->getServiceInstanceID());
        channelsPlaying.push_back(c);
        std::cout<< "tamanho : "<<channelsPlaying.size()<<std::endl;
        int startNavMethod = doc["Events"]["ChannelStart"]["StartNavMethod"].GetInt();
        switch(startNavMethod){
            case ChannelStart::StartNavMethod::channelSurfing:
                channelStart->setStartNavMethod(ChannelStart::StartNavMethod::channelSurfing);
                break;
            case ChannelStart::StartNavMethod::EPG:
                channelStart->setStartNavMethod(ChannelStart::StartNavMethod::EPG);
                break;
            case ChannelStart::StartNavMethod::Favourite:
                channelStart->setStartNavMethod(ChannelStart::StartNavMethod::Favourite);
                break;
            case ChannelStart::StartNavMethod::Last_previous:
                channelStart->setStartNavMethod(ChannelStart::StartNavMethod::Favourite);
                break;
            case ChannelStart::StartNavMethod::numberEntry:
                channelStart->setStartNavMethod(ChannelStart::StartNavMethod::numberEntry);
                break;
            case ChannelStart::StartNavMethod::other:
                channelStart->setStartNavMethod(ChannelStart::StartNavMethod::other);
                break;
            case ChannelStart::StartNavMethod::scheduledChannelChange:
                channelStart->setStartNavMethod(ChannelStart::StartNavMethod::scheduledChannelChange);
                break;
            case ChannelStart::StartNavMethod::unknown:
                channelStart->setStartNavMethod(ChannelStart::StartNavMethod::unknown);
                break;
            case ChannelStart::StartNavMethod::UpdownArrow:
                channelStart->setStartNavMethod(ChannelStart::StartNavMethod::unknown);
                break;
        }
            channelStart->setObscuration(doc["Events"]["ChannelStart"]["Obscuration"].GetFloat());
            channelStart->setViewMode(doc["Events"]["ChannelStart"]["ViewMode"].GetString());
    }
    if(doc["Events"].HasMember("ChannelStop")){
        ChannelPlaying *channelPlay = channelsPlaying.at(0);
        channelsPlaying.erase(channelsPlaying.begin());
        std::cout<< "tamanho after remove: "<<channelsPlaying.size()<<std::endl;
        delete channelPlay;
        channelStop->setServiceInstanceID(doc["Events"]["ChannelStop"]["ServiceInstanceID"].GetInt());
        int controlDev = doc["Events"]["ChannelStop"]["ControlDevice"].GetInt();
        switch(controlDev){
            case AMFCapabilityProfile::ControlDevice::STB:
                channelStop->setControlDevice(AMFCapabilityProfile::ControlDevice::STB);
                break;
            case AMFCapabilityProfile::ControlDevice::STBKeyboard:
                channelStop->setControlDevice(AMFCapabilityProfile::ControlDevice::STBKeyboard);
                break;
            case AMFCapabilityProfile::ControlDevice::STBRemoteControl:
                channelStop->setControlDevice(AMFCapabilityProfile::ControlDevice::STBRemoteControl);
                break;
            case AMFCapabilityProfile::ControlDevice::TABLET:
                channelStop->setControlDevice(AMFCapabilityProfile::ControlDevice::TABLET);
                break;
            case AMFCapabilityProfile::ControlDevice::MOBILEPHONE:
                channelStop->setControlDevice(AMFCapabilityProfile::ControlDevice::MOBILEPHONE);
                break;
            case AMFCapabilityProfile::ControlDevice::OTHER:
                channelStop->setControlDevice(AMFCapabilityProfile::ControlDevice::OTHER);
                break;
            case AMFCapabilityProfile::ControlDevice::PC:
                channelStop->setControlDevice(AMFCapabilityProfile::ControlDevice::PC);
                break;
        }
        int stopNavMethod = doc["Events"]["ChannelStop"]["StopNavMethod"].GetInt();
        switch(stopNavMethod){
            case ChannelStop::StopNavMethod::channel_surfing:
                channelStop->setStopNavMethod(ChannelStop::StopNavMethod::channel_surfing);
                break;
            case ChannelStop::StopNavMethod::EPG:
                channelStop->setStopNavMethod(ChannelStop::StopNavMethod::EPG);
                break;
            case ChannelStop::StopNavMethod::Favourite:
                channelStop->setStopNavMethod(ChannelStop::StopNavMethod::Favourite);
                break;
            case ChannelStop::StopNavMethod::Last_previous:
                channelStop->setStopNavMethod(ChannelStop::StopNavMethod::Last_previous);
                break;
            case ChannelStop::StopNavMethod::number_entry:
                channelStop->setStopNavMethod(ChannelStop::StopNavMethod::number_entry);
                break;
            case ChannelStop::StopNavMethod::other:
                channelStop->setStopNavMethod(ChannelStop::StopNavMethod::other);
                break;
            case ChannelStop::StopNavMethod::scheduled_channel_change:
                channelStop->setStopNavMethod(ChannelStop::StopNavMethod::scheduled_channel_change);
                break;
            case ChannelStop::StopNavMethod::unknown:
                channelStop->setStopNavMethod(ChannelStop::StopNavMethod::unknown);
                break;
            case ChannelStop::StopNavMethod::UpDownArrow:
                channelStop->setStopNavMethod(ChannelStop::StopNavMethod::UpDownArrow);
                break;
            case ChannelStop::StopNavMethod::turn_off_terminal_device:
                channelStop->setStopNavMethod(ChannelStop::StopNavMethod::turn_off_terminal_device);
                break;

        }


    }
    if(doc["Events"].HasMember("VideoResize")){
        videoResize->setServiceInstanceID(doc["Events"]["VideoResize"]["ServiceInstanceID"].GetInt());
        videoResize->setImageHeight(doc["Events"]["ImageHeight"].GetInt());
        videoResize->setImageWidth(doc["Events"]["ImageWidth"].GetInt());
    }

    if(doc["Events"].HasMember("VoDEvents")){
        std::string name = doc["Events"]["VoDEvents"]["Name"].GetString();
        if(videosPlaying.size() == 0){
            if(name.compare("Videostart") == 0 || name.compare("Videoplay") == 0){
                VoDPlaying *vod = new VoDPlaying();
                vod->setServiceIdentifier(doc["Events"]["VoDEvents"]["ServiceIdentifier"].GetString());
                vod->setServiceInstanceID(doc["Events"]["VoDEvents"]["ServiceInstanceID"].GetInt());
                videosPlaying.push_back(vod);
            }
        }else if(name.compare("Videopause") == 0 || name.compare("Videostop") == 0 || name.compare("Videoexit") == 0){
            VoDPlaying *vod = videosPlaying.at(0);
            videosPlaying.erase(videosPlaying.begin());


        }
        vodEvent->setEventName(name);
        vodEvent->setServiceIdentifier(doc["Events"]["VoDEvents"]["ServiceIdentifier"].GetString());
        vodEvent->setServiceInstanceID(doc["Events"]["VoDEvents"]["ServiceInstanceID"].GetInt());

    }

    if(doc["Events"].HasMember("ServiceStart"))){
        std::string name = doc["Events"]["ServiceStart"]["Name"].GetString();
        serviceRunning->setServiceName(name)
        if(name.compare("TVLinear") == 0){
            linearChannelStart->setStatus(true);
            natappStart->setStatus(false);
            iappStart->setStatus(false);

        }else if(name.compare("InteractivityApp") == 0){
            linearChannelStart->setStatus(false);
            natappStart->setStatus(false);
            iappStart->setStatus(true);
        }else if(name.compare("NativeApp") == 0){
            linearChannelStart->setStatus(false);
            natappStart->setStatus(true);
            iappStart->setStatus(false);
        }else{
             linearChannelStart->setStatus(false);
             natappStart->setStatus(false);
             iappStart->setStatus(false);
             serviceRunning->setServiceName("none");
        }

    }

}

void verififyEvents(rapidjson::Document& doc, MeasurementSchedule *msched, int i, int j, AMReportPackage *amr){
    MeasurementReport *mreport = new MeasurementReport();
    mreport->setMeasurementRequestID(config->getImmediateMeasurement()->getAMFConfigPckg()
                    ->getMeasurementSet().at(i)->getMeasurementRequests().at(j)->getMeasurementRequestID());
    amr->getMeasurementReports().push_back(mreport);
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    mreport->setMeasurementReportTriggerTime(now);
    int events_sz = msched->getEventTrigger().size();
    for(int z = 0; z < events_sz; z++){
        EventTrigger *et = msched->getEventTrigger().at(z);
        int triggerEvent_sz = et->getTriggerEvent().size();
        for(int y = 0; y < triggerEvent_sz; y++){
            TriggerEvent *te = et->getTriggerEvent().at(y);
            if((strcmp(te->events, "AudioVolume") == 0) && (doc["Events"].HasMember("AudioVolume"))){
                mreport->setAudioVolume(audioVolume);
            }
            if((strcmp(te->events, "ChannelStart") == 0) && (doc["Events"].HasMember("ChannelStart"))){
                mreport->setChannelStart(channelStart);
            }
            if((strcmp(te->events, "ChannelStop") == 0) && (doc["Events"].HasMember("ChannelStart"))){
                mreport->setChannelStop(channelStop);
            }
            if((strcmp(te->events, "VideoResize") == 0) && (doc["Events"].HasMember("VideoResize"))){
               mreport->setVideoResize(videoResize);
            }

            if((strcmp(te->events, "VoDEvents") == 0) && (doc["Events"].HasMember("VoDEvents"))){
               mreport->setVodEvents(vodEvent);
            }



        }
    }
}

bool verifyPeriod(MeasurementSchedule *msched){
    struct tm *current_date;
    struct tm *startTime;
    struct tm *endTime;
    time_t t = time(0);
    current_date = localtime(&t);
    bool diaValido = false;
    int currentWday = current_date->tm_wday;
    int dayoftheweek;
    for(int j = 0; j < msched->getMeasurementPeriod().size(); j++){
        MeasurementPeriod *mp = msched->getMeasurementPeriod().at(j);
        for(int i = 0; i < mp->getDayOfTheWeek().size(); i++){
            dayoftheweek = mp->getDayOfTheWeek().at(i);
            switch(dayoftheweek){
                case 0 :
                    diaValido = true;
                    break;
                case 1 :
                    if(currentWday == 1)
                        diaValido = true;
                    break;
                case 2 :
                    if(currentWday == 2)
                        diaValido = true;
                    break;
                case 3 :
                    if(currentWday == 3)
                        diaValido = true;
                    break;
                case 4 :
                    if(currentWday == 4)
                        diaValido = true;
                    break;
                case 5 :
                    if(currentWday == 5)
                        diaValido = true;
                    break;
                case 6 :
                    if(currentWday == 6)
                        diaValido = true;
                    break;
                case 7 :
                    if(currentWday == 0){
                        diaValido = true;
                    }
                    break;
                case 8 :
                    if(currentWday == 1 || currentWday == 2 || currentWday == 3 ||
                        currentWday == 4 || currentWday == 5)
                        diaValido = true;
                    break;
                case 9 :
                    if(currentWday == 6 || currentWday == 7)
                        diaValido = true;
                    break;
            }
        }
        if(diaValido){
            for(int i = 0; i < mp->getStartTimes().size(); i++){
                startTime = mp->getStartTimes().at(i);
                endTime = mp->getEndTimes().at(i);
                std::cout<<"hora atual :"<<current_date->tm_hour<<" hora tm : "<<startTime->tm_hour<<std::endl;
                if(current_date->tm_hour > startTime->tm_hour && current_date->tm_hour < endTime->tm_hour){
                    return true;
                }else if(current_date->tm_hour == startTime->tm_hour || current_date->tm_hour == endTime->tm_hour){
                    if(current_date->tm_min > startTime->tm_min && current_date->tm_min < endTime->tm_min){
                        return true;
                    }else if(current_date->tm_min == startTime->tm_min || current_date->tm_min == endTime->tm_min){
                        if(current_date->tm_sec > startTime->tm_sec && current_date->tm_sec < endTime->tm_sec)
                            return true;
                    }
                }

            }
        }
    }

    return false;
}

void MeasurementScheduleControl(const char *json){
    rapidjson::Document doc;
    AMReportPackage *amr = new AMReportPackage();
    amr->setSubscriberID("12345");
    amr->setTerminalDeviceID("I3E56");
    doc.Parse(json);
    int tam_i = config->getImmediateMeasurement()->getAMFConfigPckg()->getMeasurementSet().size();
    if(doc["Events"].IsObject()){
        for(int i = 0; i < tam_i; i++){
            MeasurementSet *ms = config->getImmediateMeasurement()->getAMFConfigPckg()->getMeasurementSet().at(i);
            int tam_j = ms->getMeasurementRequests().size();
            for(int j = 0; j < tam_j; j++){
                MeasurementRequest *mr = ms->getMeasurementRequests().at(j);
                int tam_k = mr->getMeasurementSched().size();
                for(int k = 0; k < tam_k; k++){
                    MeasurementSchedule *mschedule = mr->getMeasurementSched().at(k);
                    int events_sz = mschedule->getEventTrigger().size();
                    if(verifyPeriod(mschedule)){
                        verififyEvents(doc, mschedule, i, j, amr);
                    }
                }
            }
        }
    }

    sendReport(amr);
    delete amr;


}
void *countDown(void *timer){
    Count *a = ((Count *) timer);
    while(true){
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        std::cout<<"sleeping for "<<a->time<<"seconds..."<<std::flush;
        sleep(a->time);
        bool have_to_report = false;
        if(verifyPeriod(config->getImmediateMeasurement()->getAMFConfigPckg()->
            getMeasurementSet().at(a->i)->getMeasurementRequests().at(a->j)->getMeasurementSched().at(a->k))){

            MeasurementReport *mreport = new MeasurementReport();
            mreport->setMeasurementReportTriggerTime(now);
            MeasurementSet *ms = config->getImmediateMeasurement()->getAMFConfigPckg()->getMeasurementSet().at(a->i);
            MeasurementRequest *mr = ms->getMeasurementRequests().at(a->j);
            mreport->setMeasurementRequestID(mr->getMeasurementRequestID());
            MeasurementSchedule *msched = mr->getMeasurementSched().at(a->k);
            TimeTrigger *timeTrigger = msched->getTimeTrigger();
            AMReportPackage *amreport = new AMReportPackage();
            amreport->setSubscriberID("12345");
            amreport->setTerminalDeviceID("I3E56");
            for(int x = 0; x < timeTrigger->getSampleSet().size(); x++){
                if(strcmp(timeTrigger->getSampleSet().at(x)->getSampleSetId().c_str(), "ChannelPlaying") == 0){
                    std::cout<<"size : " <<channelsPlaying.size()<<std::endl;
                    for (std::vector<ChannelPlaying*>::iterator it = channelsPlaying.begin() ; it != channelsPlaying.end(); ++it){
                        mreport->getChannelPlaying().push_back(*it);
                        have_to_report = true;
                    }
                }
                if(strcmp(timeTrigger->getSampleSet().at(x)->getSampleSetId().c_str(), "VideoPlaying") == 0){
                    std::cout<<"size : " <<videosPlaying.size()<<std::endl;
                    for (std::vector<VoDPlaying*>::iterator it = videosPlaying.begin() ;
                        it != videosPlaying.end(); ++it){
                        mreport->getVodPlaying().push_back(*it);
                        have_to_report = true;

                    }
                }
            }

            std::cout<<"id :"<<mreport->getMeasurementRequestID()<<std::flush;
            amreport->getMeasurementReports().push_back(mreport);

            if(have_to_report)
                sendReport(amreport);

            delete amreport;
        }

    }
    free(a);
}
int main()
{
    readConfigs();
    if ((pthread_mutex_init(&lock, NULL) != 0) && (pthread_mutex_init(&lock_events, NULL)!= 0)&& (pthread_mutex_init(&lock_report, NULL)) != 0){
        printf("\n mutex init failed\n");
        return 1;
    }
    pthread_t inc_x_thread, comm_thread;

    if(pthread_create(&inc_x_thread, NULL, XmlXchange,NULL) != 0)
        exit(0);

    if(pthread_create(&comm_thread, NULL, midwareCommunication, NULL) != 0)
        exit(0);


    //midwareCommunication(NULL);
    int signal = 0;
    pthread_join(inc_x_thread, nullptr);
    timer();
    pthread_join(comm_thread, nullptr);



}
void timer(){
    int num_requests = 0;
    MeasurementSet *ms = NULL;
    MeasurementRequest *measurementRequest = NULL;
    MeasurementSchedule *measurementSched = NULL;
    pthread_t ***thread =  NULL;
    int tam_i, tam_j, tam_k = 0;
    tam_i = config->getImmediateMeasurement()->getAMFConfigPckg()->getMeasurementSet().size();
    thread = (pthread_t***)malloc(tam_i*sizeof(pthread_t***));

    for(int i = 0; i < tam_i; i++){
        ms = config->getImmediateMeasurement()->getAMFConfigPckg()->getMeasurementSet().at(i);
        tam_j = ms->getMeasurementRequests().size();

        thread[i] = (pthread_t**)malloc(tam_j*sizeof(pthread_t**));
        for(int j = 0 ; j < tam_j;j++){
            measurementRequest =  ms->getMeasurementRequests().at(j);
            tam_k = measurementRequest->getMeasurementSched().size();
            thread[i][j] = (pthread_t*)malloc(sizeof(pthread_t*)*tam_k);
            for(int k = 0; k < tam_k ;k++){
                measurementSched = measurementRequest->getMeasurementSched().at(k);
                thread[i][j][k] = (pthread_t)malloc(sizeof(pthread_t));
                //int *time = (int*)malloc(sizeof(*time));
                //*time = measurementSched->getTimeTrigger()->getPeriodicity();
                Count *c = new Count[1];
                c->i = i;
                c->j = j;
                c->k = k;
                c->time = measurementSched->getTimeTrigger()->getPeriodicity();
                if(pthread_create(&thread[i][j][k], NULL, &countDown, c) != 0){
                    exit(0);
                }

            }
        }
    }
    tam_i = config->getImmediateMeasurement()->getAMFConfigPckg()->getMeasurementSet().size();
    for(int i = 0; i < tam_i; i++){
        ms = config->getImmediateMeasurement()->getAMFConfigPckg()->getMeasurementSet().at(i);
        tam_j = ms->getMeasurementRequests().size();
        for(int j = 0; j < tam_j; j++){
            measurementRequest =  ms->getMeasurementRequests().at(j);
            tam_k = measurementRequest->getMeasurementSched().size();
            for(int k = 0; k < tam_k; k++){
                pthread_join(thread[i][j][k],nullptr);
                free(&thread[i][j][k]);
            }
            //free(thread[i][j]);
        }
        free(thread[i]);
    }
    free(thread);

}
void *XmlXchange(void *arg){

    /* na realidadade fará a descoberta através do deamon, ip-fixo para testar*/


    char buf[32];
    std::string response ="";
    ClientSocket *s = new ClientSocket();

    std::string port = "8009";
    int socket = s->createSocket(port,serverAddress);

    /*//getting mac address
    struct ifreq buffer;

    memset(&buffer, 0x00, sizeof(buffer));

    strcpy(buffer.ifr_name, "eth0");

    ioctl(socket, SIOCGIFHWADDR, &buffer);
    for( int i = 0; i < 6; i++ )
    {
        printf("%.2X ", (unsigned char)buffer.ifr_hwaddr.sa_data[i]);
    }
    printf("\n");*/


    if (!std::ifstream("ConfigurationRequestResponse.xml")){
        if(socket != 0){
            s->sendFile("ConfigurationRequest.xml", socket);
            while(true){
                memset(buf ,0 , 32);
                int num = recv(socket, buf, 32, 0);
                if(num <= 0){
                    close(socket);
                    break;
                }else{
                    response += buf;
                }


            }
            std::cout<<response<<std::endl;
            int i = 0;
            while(buf[i] != '\0'){
                std::cout<<buf[i]<<std::endl;
                i++;
            }

            std::ofstream out("ConfigurationRequestResponse.xml");
            out << response;

        }else{
            pthread_exit(0);
        }
    }

    XmlDomDocument* doc = new XmlDomDocument("ConfigurationRequestResponse.xml");
    config = new ConfigurationPckgRequestResponse();
    pthread_mutex_lock(&lock);
    config->parsingConfigurationPckgRequestResponse(doc);
    pthread_mutex_unlock(&lock);
    delete doc;
    std::cout<<config->getImmediateMeasurement()->getAMFConfigPckg()->getMeasurementSet().at(0)->getMeasurementRequests().size()<<std::flush;
    //delete config;

}

void *midwareCommunication(void *arg){
   int sockfd, newsockfd;
   pthread_t connectionHandler;
   std::string port = "6666";
   std::string address = localAddress;
   socklen_t clilen;
   char buffer[4096];
   struct sockaddr_in serv_addr, cli_addr;
   int n, pid;


   /* First call to socket() function */
   sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);



   /* Initialize socket structure */
    struct addrinfo* ai;
    struct addrinfo hints;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    getaddrinfo(address.c_str(), port.c_str(), &hints, &ai);
    sockfd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
    if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
   /* Now bind the host address using bind() call.*/
   if (bind(sockfd, ai->ai_addr, ai->ai_addrlen) < 0) {
      perror("ERROR on binding");
      exit(1);
   }

   /* Now start listening for the clients, here
      * process will go in sleep mode and will wait
      * for the incoming connection
   */

   listen(sockfd,5);
   clilen = sizeof(cli_addr);

   while (1) {
        newsockfd =  accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        if(pthread_create(&connectionHandler, NULL, clientHandler, &newsockfd) !=0){
            perror("Error on create thread");
            exit(0);
        }
        pthread_join(connectionHandler, NULL);

        //close(newsockfd);


   } /* end of while */

}

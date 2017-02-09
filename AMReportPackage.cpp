#include "AMReportPackage.h"
#include <fstream>
#include "eventDefs.h"
using namespace std;
void AMReportPackage::setSubscriberID(string subscriberID)
{
    this->subscriberID = subscriberID;
}

void AMReportPackage::setTerminalDeviceID(string terminalDevID)
{
    this->terminalDeviceID = terminalDevID;
}

void AMReportPackage::setMeasurementReports(vector<MeasurementReport*> m)
{
    this->measurementReports = m;
}

void AMReportPackage::setStorageCongestionImpactedService(vector<StorageCongestionImpactedService* > s)
{
    this->storageImpactedServID = s;
}

string AMReportPackage::getSubscriberID()
{
    return this->subscriberID;
}

string AMReportPackage::getTerminalDevID()
{
    return this->terminalDeviceID;
}

vector<StorageCongestionImpactedService*>& AMReportPackage::getStorageCongestionImpacted()
{
    return this->storageImpactedServID;
}

vector<MeasurementReport*>& AMReportPackage::getMeasurementReports()
{
    return this->measurementReports;
}

void AMReportPackage::writeXML()
{
    ofstream xml("AMReportPackage.xml");
    if(xml.is_open()){
        xml<<"<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n"<<endl;
        xml<<"<AMReportPackage>"<<endl;
        xml<<"<SubscriberID>"<<this->subscriberID<<"</SubscriberID>"<<endl;
        xml<<"<TerminalDeviceID>"<<this->terminalDeviceID<<"</TerminalDeviceID>"<<endl;
        for(int i = 0; i < this->storageImpactedServID.size(); i++){
            xml<<"<StorageCongestionImpactedService>"<<endl;
            StorageCongestionImpactedService *s = this->storageImpactedServID.at(i);
            xml<<"<ServiceInstanceID>"<<s->getImpactedServiceID()<<"</ServiceInstanceID>"<<endl;
            xml<<"<ServiceStopDropped>";
            if(s->getServiceStopDropped()){
                xml<<"true";
            }else{
                xml<<"false";
            }
            xml<<"</ServiceStopDropped>"<<endl;
            xml<<"</StorageCongestionImpactedService>"<<endl;


        }
        for(int i = 0; i < this->measurementReports.size(); i++){

            xml<<"<MeasurementReport>"<<endl;
            MeasurementReport *m = this->measurementReports.at(i);
            xml<<"<MeasurementRequestID>"<<m->getMeasurementRequestID()<<"</MeasurementRequestID>"<<endl;
            struct tm *t = m->getMeasurementReportTriggerTime();
            if(t != NULL){
                xml<<"<MeasurementReportTriggerTime>"<<t->tm_mday<<"/"<<t->tm_mon+1<<"/"<<t->tm_year+1900<<"  " <<t->tm_hour<<":"<<t->tm_min<<":"<<t->tm_sec<<"</MeasurementReportTriggerTime>";
            }
            string status;
            if(m->getDisplayStatus()){
                status = "turned on";
            }else{
                status = "turned off";
            }
            xml<<"<DisplayStatus>"<<status<<"</DisplayStatus>"<<endl;

            if(m->getAudioFocus() != NULL){
                xml<<"<AudioFocus>"<<endl;
                xml<<"<ServiceInstanceID>"<<m->getAudioFocus()->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                xml<<"<IPTVFocus>"<<m->getAudioFocus()->getIptvFocus()<<"</IPTVFocus>"<<endl;
                xml<<"</AudioFocus>"<<endl;
            }
            if(m->getCaptionChange() != NULL){
                xml<<"<CaptionLanguageChange>"<<endl;
                xml<<"<ServiceInstanceID>"<<m->getCaptionChange()->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                xml<<"<CaptionLanguage>"<<m->getCaptionChange()->getCaptionLanguage()<<"</CaptionLanguage>"<<endl;
                xml<<"</CaptionLanguageChange>"<<endl;
            }
            if(m->getAudioLanguageChange() != NULL){
                xml<<"<AudioLanguageChange>"<<endl;
                xml<<"<ServiceInstanceID>"<<m->getAudioLanguageChange()->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                xml<<"<AudioLanguage>"<<m->getAudioLanguageChange()->getAudioLang()<<"</AudioLanguage>"<<endl;
                xml<<"</AudioLanguageChange>"<<endl;
            }

            if(m->getAudioVolume() != NULL){
                xml<<"<AudioVolume>"<<endl;
                xml<<"<ServiceInstanceID>"<<m->getAudioVolume()->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                string direction;
                switch(m->getAudioVolume()->getVolumeDirection()){
                    case AudioVolume::up:
                        direction = "up";

                        break;
                    case AudioVolume::down:
                        direction = "down";
                        break;
                    case AudioVolume::mute:
                        direction = "mute";
                        break;
                    case AudioVolume::unmute:
                        direction = "unmute";
                        break;
                }
                xml<<"<VolumeDirection>"<<direction<<"</VolumeDirection>"<<endl;
                xml<<"</AudioVolume>"<<endl;
            }
            if(m->getConfigurationChange() != NULL){
                xml<<"<ConfigurationChange>"<<endl;
                if(m->getConfigurationChange()->getAMFCapab() != NULL)
                    m->getConfigurationChange()->getAMFCapab()->writeAMFCapab(xml);

                if(m->getConfigurationChange()->getTVInfo() != NULL)
                    m->getConfigurationChange()->getTVInfo()->writeTVInfo(xml);

                if(m->getConfigurationChange()->getAudioAmplifier() != NULL)
                    m->getConfigurationChange()->getAudioAmplifier()->writeAudioAmplifier(xml);

                xml<<"</ConfigurationChange>"<<endl;

            }

            if(m->getVideoObscure() != NULL){
                xml<<"<VideoObscure>"<<endl;
                xml<<"<ServiceInstanceID>"<<m->getVideoObscure()->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                xml<<"<Obscuration>"<<m->getVideoObscure()->getObscuration()<<"</Obscuration>"<<endl;
                xml<<"</VideoObscure>"<<endl;
            }

            if(m->getVideoZoom() != NULL){
                xml<<"<VideoZoom>"<<endl;
                xml<<"<ServiceInstanceID>"<<m->getVideoZoom()->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                xml<<"<ZoomFactor>"<<m->getVideoZoom()->getZoomFactor()<<"</ZoomFactor>"<<endl;
                xml<<"</VideoZoom>"<<endl;

            }
            if(m->getVideoResize() != NULL){
                xml<<"<VideoResize>"<<endl;
                xml<<"<ServiceInstanceID>"<<m->getVideoResize()->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                xml<<"<ImageWidth>"<<m->getVideoResize()->getImageWidth()<<"</ImageWidth>"<<endl;
                xml<<"<ImageHeight>"<<m->getVideoResize()->getImageHeight()<<"</ImageHeight>"<<endl;
                xml<<"</VideoResize>"<<endl;

            }

            for(int j = 0; j < m->getEventCount().size(); j++){
                EventCount *e = m->getEventCount().at(j);
                xml<<"<EventCount>"<<endl;
                xml<<"<EventCounted>"<<e->getEventsCounted()<<"</EventsCounted>"<<endl;
                xml<<"<ServiceInstanceID>"<<e->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                TimeStamp *time = e->getStartTime();
                xml<<"<StartTime>"<<time->day<<"/"<<time->month<<"/"<<time->year<<"  " <<time->hour<<":"<<time->minute<<":"<<time->seconds<<"  "<<time->mseconds<<"</StartTime>"<<endl;
            }
            if(m->getDeviceInformation() != NULL){
                xml<<"<DeviceInformation>"<<endl;
                if(m->getDeviceInformation()->getStbInfo() != NULL)
                    m->getDeviceInformation()->getStbInfo()->writeXML(xml);

                if(m->getDeviceInformation()->getAudioAmpliInfo() != NULL)
                    m->getDeviceInformation()->getAudioAmpliInfo()->writeAudioAmplifier(xml);

                if(m->getDeviceInformation()->getTvInfo() != NULL)
                    m->getDeviceInformation()->getTvInfo()->writeTVInfo(xml);

                if(m->getDeviceInformation()->getIptvInfo() != NULL)
                    m->getDeviceInformation()->getIptvInfo()->writeXML(xml);

                if(m->getDeviceInformation()->getMobileDevInfo() != NULL)
                    m->getDeviceInformation()->getMobileDevInfo()->writeXML(xml);

                if(m->getDeviceInformation()->getPcInfo() != NULL)
                    m->getDeviceInformation()->getPcInfo()->writeXML(xml);

                xml<<"</DeviceInformation>"<<endl;
            }

            if(m->getUserIdBioInfo().size() > 0){
                xml<<"<UserBiographicInfo>"<<endl;
                for(int j= 0; j < m->getUserIdBioInfo().size(); j++){
                    xml<<"<UserIdBioInfo>"<<endl;
                    UserIdBioInfo *u = m->getUserIdBioInfo().at(j);
                    xml<<"<UserId>"<<u->getUserID()<<"</UserId>"<<endl;
                    xml<<"<ControlledUserInfoTypeString>"<<endl;

                    for(int k = 0; k < u->getControlledUserInfoStrings().size(); k++){
                            ControlledUserInfoString *s = u->getControlledUserInfoStrings().at(k);
                            xml<<"<"<<s->controlledUserInfoTypeString<<">";
                            xml<<s->controlledUserInfoValueString;
                            xml<<"</"<<s->controlledUserInfoTypeString<<">";


                    }
                    xml<<"</ControlledUserInfoTypeString>"<<endl;

                    xml<<"<ControlledUserInfoTypeDate>"<<endl;

                    for(int k = 0; k < u->getControlledUserInfoDate().size(); k++){
                            ControlledUserInfoDate *d = u->getControlledUserInfoDate().at(k);
                            xml<<"<"<<d->controlledUserInfoTypeDate<<">";
                            xml<<d->controlledUserInfoTypeValue;
                            xml<<"</"<<d->controlledUserInfoTypeDate<<">";


                    }
                    xml<<"</ControlledUserInfoTypeDate>"<<endl;

                    xml<<"<ControlledUserInfoTypeAddress>"<<endl;
                    for(int k = 0; j < u->getControlledUserInfoAddresses().size(); k++){
                        controlledUserInfoAddress *a = u->getControlledUserInfoAddresses().at(k);
                        xml<<"<"<<a->controlledUserInfoAddressType<<">";
                        xml<<a->controlledUserInfoAddressValue;
                        xml<<"</"<<a->controlledUserInfoAddressType<<">";
                    }
                    xml<<"</ControlledUserInfoTypeAddress>"<<endl;

                    xml<<"</UserIdBioInfo>"<<endl;
                }
                xml<<"</UserBiographicInfo>"<<endl;
            }


            if(m->getTDLocation() != NULL){
                xml<<"<TDLocation>"<<endl;
                xml<<"<Latitude>"<<m->getTDLocation()->latitude<<"</Latitude>"<<endl;
                xml<<"<Longitude>"<<m->getTDLocation()->longitude<<"</Longitude>"<<endl;
                xml<<"</TDLocation>"<<endl;
            }

            if(m->getUserList() != NULL){
                xml<<"<UserList>"<<endl;
                for(int j = 0; j < m->getUserList()->getUserIdInfo().size(); j++){
                    UserIdInfo *u = m->getUserList()->getUserIdInfo().at(j);
                    xml<<"<UserIdInfo>"<<endl;
                    xml<<"<AnonUserID>"<<u->annonUserID<<"</AnnonUserID>"<<endl;
                    xml<<"<UserID>"<<u->userID<<"</UserID>"<<endl;
                    xml<<"<UserIDMethod>"<<u->userIDMethod<<"</UserIDMethod>"<<endl;
                    xml<<"<UserIDConfidence>"<<u->userIDConfidence<<"</UserIDConfidence>"<<endl;
                    xml<<"</UserIdInfo>"<<endl;;
                }
                xml<<"</UserList>"<<endl;
            }
            for(int j = 0 ; i < m->getUserPresent().size(); j++){
                UserPresent *p = m->getUserPresent().at(j);
                TimeStamp *t = p->presenceTime;
                xml<<"<UserPresent>"<<endl;
                xml<<"<PresenceMethod>"<<p->presenceMethod<<"</PresenceMethod>"<<endl;
                xml<<"<PresenceTime>"<<t->day<<"/"<<t->month<<"/"<<t->year<<"  " <<t->hour<<":"<<t->minute<<":"<<t->seconds<<"  "<<t->mseconds<<"</PresenceTime>"<<endl;
                xml<<"<PresenceConfidence>"<<p->presenceConfidence<<"</PresenceConfidence>"<<endl;
                xml<<"</UserPresent>"<<endl;
            }

            if(m->getGenericUserInfo() != NULL){
                xml<<"<GenericUserInfo>"<<endl;
                for(int j = 0; j < m->getGenericUserInfo()->getUserIdGenericInfo().size(); j++){
                    UserIDGenericInfo *u = m->getGenericUserInfo()->getUserIdGenericInfo().at(j);
                    xml<<"<UserIDGenericInfo>"<<endl;
                    xml<<"<AnonUserID>"<<u->annonUserID<<"</AnonUserID>"<<endl;
                    xml<<"<UserID>"<<u->userID<<"</UserID>"<<endl;
                    xml<<"<GenericUserInfoString>"<<endl;
                    for(int k = 0; k < u->genericUserInfos.size(); k++){
                        GenericUserInfos *g = u->genericUserInfos.at(k);
                        xml<<"<"<<g->genericUserInfoType<<">"<<g->genericUserInfoValue<<"</"<<g->genericUserInfoType<<">"<<endl;

                    }
                    xml<<"</GenericUserInfoString>"<<endl;
                    xml<<"</UserIDGenericInfo>"<<endl;
                }
                xml<<"</GenericUserInfo>"<<endl;
            }
            if(m->getUserInfoChange() != NULL){
                xml<<"<UserInfoChange>"<<endl;
                xml<<"<AnonUserID>"<<m->getUserInfoChange()->getAnnonUserID()<<"</AnnonUserID>"<<endl;
                xml<<"<UserID>"<<m->getUserInfoChange()->getUserID()<<"</UserID>"<<endl;
                UserInfoChange *infoChange = m->getUserInfoChange();
                xml<<"<ControlledUserInfoString>"<<endl;
                for(int j = 0; j < infoChange->getControlledUserInfoStrings().size(); j++){
                    ControlledUserInfoString *c = infoChange->getControlledUserInfoStrings().at(j);
                    xml<<"<"<<c->controlledUserInfoTypeString<<">";
                    xml<<c->controlledUserInfoValueString;
                    xml<<"</"<<c->controlledUserInfoValueString<<">"<<endl;
                }
                xml<<"</ControlledUserInfoString>"<<endl;

                xml<<"<ControlledUserInfoDate>"<<endl;
                for(int j = 0; j < infoChange->getControlledUserInfoDate().size(); j++){
                    ControlledUserInfoDate *d = infoChange->getControlledUserInfoDate().at(j);
                    xml<<"<"<<d->controlledUserInfoTypeDate<<">";
                    xml<<d->controlledUserInfoTypeValue;
                    xml<<"</"<<d->controlledUserInfoTypeValue<<">"<<endl;
                }
                xml<<"</ControlledUserInfoDate>"<<endl;

                xml<<"<ControlledUserInfoAddress>"<<endl;
                for(int k = 0; k < infoChange->getControlledUserInfoAddresses().size(); k++){
                    ControlledUserInfoAddress *a = infoChange->getControlledUserInfoAddresses().at(k);
                    xml<<"<"<<a->controlledUserInfoAddressType<<">";
                    xml<<a->controlledUserInfoAddressValue;
                    xml<<"</"<<a->controlledUserInfoAddressType<<">"<<endl;
                }
                xml<<"</ControlledUserInfoAddress>"<<endl;
                xml<<"<GenericUserInfoString>"<<endl;

                for(int j = 0; j < infoChange->getGenericUserInfo().size(); j++){
                    GenericUserInfos *g = infoChange->getGenericUserInfo().at(j);
                    xml<<"<"<<g->genericUserInfoType<<">"<<g->genericUserInfoValue<<"</"<<g->genericUserInfoType<<">"<<endl;
                }
                xml<<"</GenericUserInfoString>"<<endl;
                xml<<"</UserInfoChange>"<<endl;
            }
            if(m->getPermitBlockedInfo()!= NULL){
                xml<<"<PermitBlockedInfo>"<<endl;
                xml<<"<PermissionLevelFlag>"<<m->getPermitBlockedInfo()->getPermissionLevelFlag()<<"</PermissionLevelFlag>"<<endl;
                xml<<"<TerminalDeviceTypeFlag>"<<m->getPermitBlockedInfo()->getTerminalDeviceTypeFlag()<<"</TerminalDeviceTypeFlag>"<<endl;
                xml<<"<ChannelFlag>"<<m->getPermitBlockedInfo()->getChannelFlag()<<"</ChannelFlag>"<<endl;
                xml<<"<ContentClassFlag>"<<endl;
                xml<<"<AllContentClassExceptList>"<<endl;
                for(int j = 0; j < m->getPermitBlockedInfo()->getContentClassFlag()->getContentClass().size(); j++){
                    ContentClass *c = m->getPermitBlockedInfo()->getContentClassFlag()->getContentClass().at(j);
                    xml<<"<ContentClass>"<<endl;
                    xml<<"<ContentClassDomain>"<<c->contentClassDomain<<"</ContentClassDomain>"<<endl;
                    for(int k = 0; k <c->contentClassID.size(); k++){
                        xml<<"<ContentClassID>"<<c->contentClassID.at(k)<<"</ContentClassID>"<<endl;
                    }
                    xml<<"</ContentClass>"<<endl;
                }
                xml<<"</AllContentClassExceptList>"<<endl;
                xml<<"</ContentClassFlag>"<<endl;
                xml<<"</PermitBlockedInfo>"<<endl;
            }
            //LinearTV Extension

            if(m->getChannelStart() != NULL){
                xml<<"<ChannelStart>"<<endl;
                xml<<"<ControlDevice>"<<m->getChannelStart()->getControlDevice()<<"</ControlDevice>"<<endl;
                xml<<"<StartNavMethod>"<<m->getChannelStart()->getStartNavMethod()<<"</StartNavMethod>"<<endl;
                xml<<"<PreviousServiceInstanceID>"<<m->getChannelStart()->getPreviousServiceInstanceID()<<"</PreviousServiceInstanceID>"<<endl;
                xml<<"<ServiceInstanceID>"<<m->getChannelStart()->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                xml<<"<ServiceIdentifier>"<<m->getChannelStart()->getServiceIdentifer()<<"</ServiceIdentifier>"<<endl;
                xml<<"<ViewMode>"<<m->getChannelStart()->getViewMode()<<"</ViewMode>"<<endl;
                xml<<"<Obscuration>"<<m->getChannelStart()->getObscuration()<<"</Obscuration>"<<endl;
                xml<<"</ChannelStart>"<<endl;
            }

            if(m->getChannelStop() != NULL){
                xml<<"<ChannelStop>"<<endl;
                xml<<"<ControlDevice>"<<m->getChannelStop()->getControlDevice()<<"</ControlDevice>"<<endl;
                xml<<"<StopNavMethod>"<<m->getChannelStop()->getStopNavMethod()<<"</StopNavMethod>"<<endl;
                xml<<"<ServiceInstanceID>"<<m->getChannelStop()->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                xml<<"</ChannelStop>"<<endl;
            }
            if(m->getVodEvents() != NULL){
                xml<<"<VoDEvents>"<<endl;
                xml<<"<Name>"<<m->getVodEvents()->getEventName()<<"</Name>"<<endl;
                xml<<"<ServiceIdentifier>"<<m->getVodEvents()->getServiceIdentifier()<<"</ServiceIdentifier>"<<endl;
                xml<<"<ServiceInstanceID>"<<m->getVodEvents()->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                xml<<"</VoDEvents>"<<endl;
            }
            ChannelPlaying *channelP = NULL;
            for(int j = 0; j < m->getChannelPlaying().size(); j++){
                channelP = m->getChannelPlaying().at(j);
                xml<<"<ChannelPlaying>"<<endl;
                xml<<"<ServiceIdentifier>"<<channelP->getServiceIdentifier()<<"</ServiceIdentifier>"<<endl;
                xml<<"<ServiceInstanceID>"<<channelP->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                xml<<"</ChannelPlaying>"<<endl;

            }
            VoDPlaying *videoP = NULL;
            for(int j = 0; j < m->getVodPlaying().size(); j++){
                videoP = m->getVodPlaying().at(j);
                xml<<"<VideoPlaying>"<<endl;
                xml<<"<ServiceIdentifier>"<<videoP->getServiceIdentifier()<<"</ServiceIdentifier>"<<endl;
                xml<<"<ServiceInstanceID>"<<videoP->getServiceInstanceID()<<"</ServiceInstanceID>"<<endl;
                xml<<"</VideoPlaying>"<<endl;

            }



            xml<<"</MeasurementReport>"<<endl;

        }
        xml<<"</AMReportPackage>"<<endl;
    }
    xml.close();
}
AMReportPackage::~AMReportPackage()
{
    for(int i = 0; i < this->getMeasurementReports().size(); i++){
        delete this->getMeasurementReports().at(i);
    }

    for(int i = 0; i < this->getStorageCongestionImpacted().size(); i++){
        delete this->getStorageCongestionImpacted().at(i);
    }
}

AMReportPackage::AMReportPackage()
{

}




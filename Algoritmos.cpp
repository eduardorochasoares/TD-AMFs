#include "Algoritmos.h"

std::vector<std::string> splitStringx(std::string s, std::string delimiter)
{
    size_t pos = 0;
    std::string token;
    std::vector<std::string> str;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);

        str.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    str.push_back(s);

    return str;

}

void setTimeAndDate(struct tm* value, std::string s)
{
    std::vector<std::string> v = splitStringx(s, " ");
    if(v.size() > 1){
        std::vector<std::string> date = splitStringx(v.at(0), "-");
        value->tm_mday = stoi(date.at(0), nullptr, 10);
        value->tm_mon = stoi(date.at(1), nullptr,10);
        value->tm_year = stoi(date.at(2),nullptr,10);

        std::vector<std::string> time = splitStringx(v.at(1), ":");
        value->tm_hour = stoi(time.at(0), nullptr, 10);
        value->tm_min = stoi(time.at(1), nullptr,10);
        value->tm_sec = stoi(time.at(2), nullptr,10);
    }else{
        std::vector<std::string> time = splitStringx(v.at(0), ":");
        value->tm_hour = stoi(time.at(0), nullptr, 10);
        value->tm_min = stoi(time.at(1), nullptr,10);
        value->tm_sec = stoi(time.at(2), nullptr,10);

    }

}






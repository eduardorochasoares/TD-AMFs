#ifndef ALGORITMOS_H_INCLUDED
#define ALGORITMOS_H_INCLUDED
#include <string>
#include <vector>
#include <iostream>
#include <ctime>


std::vector<std::string> splitStringx(std::string s, std::string delimiter);

void setTimeAndDate(struct tm* value, std::string s);
#endif // ALGORITMOS_H_INCLUDED

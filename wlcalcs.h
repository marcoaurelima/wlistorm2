#ifndef WLCALCS_H
#define WLCALCS_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <memory>
#include <cmath>
#include <cstring>
#include "structs.h"

std::unique_ptr<WlistInfo> getWlistInfo(int argc, char* argv[]);
std::unique_ptr<WlistSize> getWlistSize(const WlistInfo& wlistInfo);
std::string arroundValue(std::string value, int decimalPoints);
void printInfo(const WlistInfo& wlistInfo);
void printSize(const WlistSize& wlistSize);
long unsigned fact(long unsigned n);
void maskIsValid(std::string mask, int min, int max);

#endif

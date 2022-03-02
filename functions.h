#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <cstring>
#include "structs.h"

void printLogo();
std::unique_ptr<WlistInfo> getWlistInfo(int argc, char* argv[]);

std::string arroundValue(std::string value, int decimalPoints);

long unsigned fact(long unsigned n);

void printInfo(const WlistInfo& wlistInfo);
void printSize(const WlistSize& wlistSize);
bool printContinue();

void makeWordlist(const WlistInfo& wlistInfo);

std::unique_ptr<WlistSize> getWlistSize(const WlistInfo& wlistInfo);

#endif

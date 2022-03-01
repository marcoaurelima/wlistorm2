#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <memory>
#include <cmath>
#include <cstring>
#include "structs.h"

void printLogo();
std::unique_ptr<WlistInfo> getWlistInfo(int argc, char* argv[]);

long unsigned fact(long unsigned n);

void printInfo(const WlistInfo& wlistInfo);
void printSize(const WlistSize& wlistSize);

std::unique_ptr<WlistSize> getWlistSize(const WlistInfo& wlistInfo);

#endif

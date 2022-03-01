#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <memory>
#include "structs.h"

void printLogo();

void printInfo(const WlistInfo& wlistInfo);
void printSize(const WlistSize& wlistSize);

std::unique_ptr<WlistSize> getWlistSize(const WlistInfo& wlistInfo);

#endif

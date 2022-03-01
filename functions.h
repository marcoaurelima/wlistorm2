#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <memory>
#include "structs.h"

void printLogo();

void printSize();

std::unique_ptr<WlistSize> getWlistSize(const WlistInfo& wlistInfo);

#endif

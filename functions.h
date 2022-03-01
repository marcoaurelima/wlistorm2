#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <memory>
#include "structs.h"

void print_logo();

std::unique_ptr<WlistSize> getWlistSize(WlistInfo* wlistInfo);

#endif

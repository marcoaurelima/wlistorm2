#ifndef WLGENERATE_H
#define WLGENERATE_H
#include "structs.h"
#include <iostream>
#include <vector>

void increment(WlistInfo& wlistInfo, std::vector<int>& indexes);

bool allowWord(WlistInfo& wlistInfo, const std::vector<int>& indexes);

void handleWord(WlistInfo& wlistInfo, WlistSize& wlistSize, const std::vector<int>& indexes, FILE* file2);

bool loop(WlistInfo& wlistInfo, const std::vector<int>& indexes);

void makeWordlist(WlistInfo& wlistInfo, WlistSize& wlistSize);

#endif

#ifndef WLGENERATE_H
#define WLGENERATE_H
#include "structs.h"
#include <iostream>
#include <vector>

bool loop(std::string& alphabet, const std::vector<int>& indexes);

bool allowWord(int repeatitions, const std::vector<int>& indexes);

void increment(std::string& alphabet, std::vector<int>& indexes);

void handleWord(std::string& alphabet, std::string& filename, const std::vector<int>& indexes, FILE* file2);


void makeWordlist(WlistInfo& wlistInfo);

#endif

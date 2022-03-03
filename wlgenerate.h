#ifndef WLGENERATE_H
#define WLGENERATE_H
#include "structs.h"
#include <iostream>
#include <sstream>
#include <vector>

bool loop(const int& alphabetSize, const std::vector<int>& indexes);

bool allowWord(const int& repeatitions, const int& max, const std::vector<int>& indexes);

void increment(std::string& alphabet, std::vector<int>& indexes);

void printWord(const std::string& alphabet, const std::string mask, const std::vector<int>& indexes);

void writeWord(const std::string& alphabet, const std::string mask, MASK_TYPE maskType,  const std::vector<int>& indexes, FILE* file);


void makeWordlist(WlistInfo& wlistInfo);

#endif

#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>

struct WlistInfo{
  int min;
  int max;
  int repeatitions;
  std::string mask;
  std::string alphabet;
  std::string filename;
};

struct WlistSize{
  long unsigned ln;
  long long unsigned by;
  long double kb;
  long double mb;
  double gb;
  double tb;
  double pb;
};

#endif

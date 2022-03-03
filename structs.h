#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>

enum class MASK_TYPE{
  NOT, // The word does not will use mask
  BEG, // Mask goes to beggining of the word
  END, // Mask goes to end of of word
  MIX  // Mask is mixed in the word
};

struct WlistInfo{
  int min;
  int max;
  int repeatitions;
  std::string alphabet;
  std::string filename;
  std::string mask;
  MASK_TYPE maskType;
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

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>

struct wl_info{
  int min;
  int max;
  int repeatitions;
  string alphabet;
  string filename;
};

struct wl_size{
  int b;
  int Mb;
  int Gb;
  int Tb;
};


void print_logo();

wl_size* get_wl_size(wl_info* info);

#endif

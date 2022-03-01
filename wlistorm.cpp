#include "functions.h"

int main(){
  print_logo();

  wl_size* size = get_wl_size();

  std::cout << ">> " << size->Mb << std::endl;
  std::cout << "teste3" << std::endl;
  return 0;
}

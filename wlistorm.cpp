#include "functions.h"

int main(){
  print_logo();


  auto wlistSize = getWlistSize(nullptr);

  std::cout << ">> " << wlistSize->Mb << std::endl;
  std::cout << "teste3" << std::endl;
  return 0;
}

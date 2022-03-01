#include "functions.h"

int main(){
  printLogo();

  WlistInfo wlistInfo{};

  auto wlistSize = getWlistSize(wlistInfo);

  std::cout << ">> " << wlistSize->Mb << std::endl;
  std::cout << "teste3" << std::endl;
  return 0;
}

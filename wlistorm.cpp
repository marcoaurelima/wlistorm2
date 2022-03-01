#include "functions.h"

int main(){
  print_logo();

  auto wlistInfo = std::make_shared<WlistInfo>();

  auto wlistSize = getWlistSize(wlistInfo);

  std::cout << ">> " << wlistSize->Mb << std::endl;
  std::cout << "teste3" << std::endl;
  return 0;
}

#include "functions.h"

int main(int argc, char* argv[]){
  printLogo();

  auto wlistInfo = getWlistInfo(argc, argv);
  printInfo(*wlistInfo);

  auto wlistSize = getWlistSize(*wlistInfo);
  printSize(*wlistSize);

  if(!printContinue()){ return 0; }


  std::cout << "\n Processando...\n\n";

  makeWordlist(*wlistInfo);

  return 0;
}

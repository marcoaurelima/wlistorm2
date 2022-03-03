#include "wlcalcs.h"
#include "wlgenerate.h"
#include "wlscreen.h"

void testes()
{

  std::string s = "...mob...";

  std::cout << "Test1 " << s.substr(0,3) << "\n";

  std::cout << "Test2 " << s.substr(s.size()-3, s.size()-1) << "\n";
}

int main(int argc, char* argv[]){
  printLogo();

  //testes();

  auto wlistInfo = getWlistInfo(argc, argv);
  printInfo(*wlistInfo);

  auto wlistSize = getWlistSize(*wlistInfo);
  //return 0;
  printSize(*wlistSize);

  //return 0;
  if(!printContinue()){ return 0; }

  makeWordlist(*wlistInfo);

  return 0;
}

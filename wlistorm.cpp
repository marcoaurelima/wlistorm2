#include "wlcalcs.h"
#include "wlgenerate.h"
#include "wlscreen.h"

int main(int argc, char* argv[]){
  printLogo();

  auto wlistInfo = getWlistInfo(argc, argv);
  printInfo(*wlistInfo);

  auto wlistSize = getWlistSize(*wlistInfo);
  printSize(*wlistSize);

  if(!printContinue()){ return 0; }

  makeWordlist(*wlistInfo, *wlistSize);

  return 0;
}

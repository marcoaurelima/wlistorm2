#include "functions.h"

int main(){
  printLogo();


  WlistInfo wlistInfo{2,3,4,"abcd","wordlist.txt"};
  printInfo(wlistInfo);

  auto wlistSize = getWlistSize(wlistInfo);
  printSize(*wlistSize);


  return 0;
}

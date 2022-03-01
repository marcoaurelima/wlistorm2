#include "functions.h"

int main(int argc, char* argv[]){
  printLogo();

/*
  int p = std::stoi(argv[1]);
  int n = std::stoi(argv[2]);
  std::cout << static_cast<long int>(powl(n, p)) << "\n";
*/

  auto wlistInfo = getWlistInfo(argc, argv);
  printInfo(*wlistInfo);

  auto wlistSize = getWlistSize(*wlistInfo);
  printSize(*wlistSize);

  return 0;
}

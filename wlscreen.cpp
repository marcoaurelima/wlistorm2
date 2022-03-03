#include "wlscreen.h"

void printLogo()
{
  std::cout << R"(
  __      __.__  .__          __
 /  \    /  \  | |__| _______/  |_  ___________  _____
 \   \/\/   /  | |  |/  ___/\   __\/  _ \_  __ \/     \
  \        /|  |_|  |\___ \  |  | (  <_> )  | \/  Y Y  \
   \__/\  / |____/__/____  > |__|  \____/|__|  |__|_|  /
        \/               \/     wordlist generator  \/)" << '\n';
};

bool printContinue()
{
  std::cout << " Continue? [y/n] ";
  std::string yn;
  std::getline(std::cin, yn);
  if(yn == "n")
  {
    std::cout << " -- Cancelado --\n\n";
    return false;
  }
  return true;
}

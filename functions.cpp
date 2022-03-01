#include "functions.h"

void print_logo()
{
  system("clear");
  std::cout << R"(
  __      __.__  .__          __
 /  \    /  \  | |__| _______/  |_  ___________  _____
 \   \/\/   /  | |  |/  ___/\   __\/  _ \_  __ \/     \
  \        /|  |_|  |\___ \  |  | (  <_> )  | \/  Y Y  \
   \__/\  / |____/__/____  > |__|  \____/|__|  |__|_|  /
        \/               \/      wordlist generator  \/)";
}

std::unique_ptr<WlistSize> getWlistSize(WlistInfo* wlistInfo)
{
  std::unique_ptr<WlistSize> wlistSize(new WlistSize{});
  
  return wlistSize;
}

#include "functions.h"

void printLogo()
{
  system("clear");
  std::cout << R"(
  __      __.__  .__          __
 /  \    /  \  | |__| _______/  |_  ___________  _____
 \   \/\/   /  | |  |/  ___/\   __\/  _ \_  __ \/     \
  \        /|  |_|  |\___ \  |  | (  <_> )  | \/  Y Y  \
   \__/\  / |____/__/____  > |__|  \____/|__|  |__|_|  /
        \/               \/      wordlist generator  \/)" << '\n';
}

std::unique_ptr<WlistSize> getWlistSize(const WlistInfo& wlistInfo)
{
  auto wlistSize = std::make_unique<WlistSize>();

  return wlistSize;
}

void printInfo(const WlistInfo& wlistInfo)
{
  std::cout << "\npass size: "<< wlistInfo.min << "-" << wlistInfo.max << "    ";
  std::cout << "max repeat: " << wlistInfo.repeatitions << "\n";
  std::cout << "alphabet:  "  << wlistInfo.alphabet << "\n";
  std::cout << "output:    "  << wlistInfo.filename << "\n\n";
}

void printSize(const WlistSize& wlistSize)
{
  std::cout << "Output file size:  ";
  std::cout << wlistSize.mb << "[MB]  " << wlistSize.gb << "[GB]  ";
  std::cout << wlistSize.tb << "[TB]  " << wlistSize.pb << "[PB] \n\n";
}

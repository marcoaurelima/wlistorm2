#include "functions.h"

/**
    Just print wlistorm logo.
*/
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

std::unique_ptr<WlistInfo> getWlistInfo(int argc, char* argv[])
{

  auto wlistInfo = std::make_unique<WlistInfo>();

  wlistInfo->min = atoi(argv[1]);
  wlistInfo->max = atoi(argv[2]);
  wlistInfo->alphabet = std::string(argv[3]);

  // Default values
  wlistInfo->repeatitions = 0;     // Zero means allow all repeatitions.
  wlistInfo->filename = "Terminal"; // If not was not defined a outputfile.
  wlistInfo->mask = "";

  for(int i=3;i<argc;i++)
  {
    if(strcmp(argv[i], "-r") == 0)
    {
      wlistInfo->repeatitions = atoi(argv[i+1]);
    } else
    if(strcmp(argv[i], "-f") == 0)
    {
      wlistInfo->filename = std::string(argv[i+1]);
    } else
    if(strcmp(argv[i], "-m") == 0)
    {
      wlistInfo->mask = std::string(argv[i+1]);
    }
  }

  return wlistInfo;
}

long unsigned fact(long unsigned n)
{
  int result = 1;
  for(long unsigned i=1;i<=n;i++)
  {
    result *= i;
  }
  return result;
}


/**
    Calculate word list size.
    @param Reference to a WlistInfo.
    @return Smart Pointer to a WlistSize that contains the size in MB, GB, Tb and PB.
*/
std::unique_ptr<WlistSize> getWlistSize(const WlistInfo& wlistInfo)
{
  long unsigned totalSize = 0;

  for(unsigned p=wlistInfo.min;p<=wlistInfo.max;p++)
  {
    int n = wlistInfo.alphabet.size();

    if(wlistInfo.repeatitions == 1)
    {
      totalSize += static_cast<long int>(powl(n, p));
    } else if(wlistInfo.repeatitions == p)
    {
      std::cout << "***\n";
      totalSize += static_cast<long int>(fact(n) / fact(n-p));
    }

  }

  auto wlistSize = std::make_unique<WlistSize>();

  wlistSize->mb = totalSize;

  return wlistSize;
}

void printInfo(const WlistInfo& wlistInfo)
{
  std::cout << "\npssw size: "<< wlistInfo.min << "-" << wlistInfo.max << "    ";
  std::cout << "max repeat: " << wlistInfo.repeatitions << "\n";
  std::cout << "alphabet:  "  << wlistInfo.alphabet << "\n";
  if(wlistInfo.mask.size() != 0)
  std::cout << "mask:      "  << wlistInfo.mask << "\n";
  std::cout << "output:    "  << wlistInfo.filename << "\n\n";
}

void printSize(const WlistSize& wlistSize)
{
  std::cout << "Output file size:  " << wlistSize.ln << "[LN]\n";
  std::cout << "                   ";
  std::cout << wlistSize.mb << "[MB]  " << wlistSize.gb << "[GB]  ";
  std::cout << wlistSize.tb << "[TB]  " << wlistSize.pb << "[PB] \n\n";
}

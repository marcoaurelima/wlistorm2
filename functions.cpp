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


/**
    Calculate the factorial of a number..
    @param Comand-line values.
    @return Smart point to a WlistInfo.
*/
std::unique_ptr<WlistInfo> getWlistInfo(int argc, char* argv[])
{

  auto wlistInfo = std::make_unique<WlistInfo>();

  wlistInfo->min = atoi(argv[1]);
  wlistInfo->max = atoi(argv[2]);
  wlistInfo->alphabet = std::string(argv[3]);

  // Default values
  wlistInfo->repeatitions = -1;     // -1 means allow all repeatitions.
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


/**
    Calculate the factorial of a number..
    @param Value.
    @return Factorial of value.
*/
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
  // For each value on range (params 1 and 2 of comand-line entry)
  std::vector<long unsigned> qtdLines;
  std::vector<long unsigned> sizeLines;

  for(unsigned p=wlistInfo.min;p<=wlistInfo.max;p++)
  {
    int n = wlistInfo.alphabet.size();

    if(wlistInfo.repeatitions == -1)
    {
      qtdLines.push_back(static_cast<long int>(powl(n, p)));
    } else if(wlistInfo.repeatitions == 1)
    {
      qtdLines.push_back(static_cast<long int>(fact(n) / fact(n-p)));
    }
  }

  // Calculate the size in bytes of a range:

  int realMaskSize = 0; // Size of mask without all '~'
  for(auto& i : wlistInfo.mask)
  {
    if(i != '~'){ realMaskSize++; }
  }

  for(auto& i : qtdLines)
  {
    sizeLines.push_back(i + realMaskSize);
  }


  auto wlistSize = std::make_unique<WlistSize>();

  for(unsigned i=0;i<=qtdLines.size();i++)
  {
    wlistSize->ln += qtdLines[i];
    wlistSize->by += (qtdLines[i] * sizeLines[i]);
  }

  wlistSize->mb = wlistSize->by / pow(1024, 1);
  wlistSize->gb = wlistSize->by / pow(1024, 2);
  wlistSize->tb = wlistSize->by / pow(1024, 3);
  wlistSize->pb = wlistSize->by / pow(1024, 4);

  return wlistSize;
}


/**
    Print information of comand-line entry.
    @param Reference to a WlistInfo.
    @return void.
*/
void printInfo(const WlistInfo& wlistInfo)
{
  std::cout << "\npssw size: "<< wlistInfo.min;
  if(wlistInfo.min != wlistInfo.max)
  std::cout << "-" << wlistInfo.max << "    ";

  if(wlistInfo.repeatitions != -1)
  std::cout << "char repeat: " << wlistInfo.repeatitions;
  std::cout << "\nalphabet:  "  << wlistInfo.alphabet << "\n";

  if(wlistInfo.mask.size() != 0)
  std::cout << "mask:      "  << wlistInfo.mask << "\n";
  std::cout << "output:    "  << wlistInfo.filename << "\n\n";
}


/**
    Print information of file size output.
    @param Reference to a WlistSize.
    @return void.
*/
void printSize(const WlistSize& wlistSize)
{
  std::cout << "Output file size:  " << wlistSize.ln << "[LN]\n";
  std::cout << "                   ";
  std::cout << (std::ceil(wlistSize.mb * 100.0) / 100.0) << "[MB]  ";
  std::cout << (std::ceil(wlistSize.gb * 1000.0) / 1000.0) << "[GB]  ";
  std::cout << (std::ceil(wlistSize.tb * 1000.0) / 1000.0) << "[TB]  ";
  std::cout << (std::ceil(wlistSize.pb * 1000.0) / 1000.0) << "[PB] \n\n";
}

bool printContinue()
{
  std::cout << "Continue? [y/n] ";
  std::string yn;
  std::getline(std::cin, yn);
  if(yn == "n")
  {
    std::cout << "-- Cancelado --\n\n";
    return false;
  }
  return true;
}

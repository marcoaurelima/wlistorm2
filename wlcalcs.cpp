#include "wlcalcs.h"
#include "wlscreen.h"

//Calculate the factorial of a number..
std::unique_ptr<WlistInfo> getWlistInfo(int argc, char* argv[])
{
  if(argc == 1){ help(); exit(0); }
  if(argc == 2 && strcmp(argv[1], "-h") == 0){ help(); exit(0); }
  if(argc < 4) { std::cout << "\n [error]\n Incomplete parameters. Type \"wlistorm -h for help.\n\n ***\n\n"; exit(0); }

  auto wlistInfo = std::make_unique<WlistInfo>();

  wlistInfo->min = atoi(argv[1]);
  wlistInfo->max = atoi(argv[2]);
  wlistInfo->alphabet = std::string(argv[3]);

  // Default values
  wlistInfo->repeatitions = atoi(argv[2]);     // -1 means allow all repeatitions.
  wlistInfo->filename = "Terminal"; // If not was not defined a outputfile.
  wlistInfo->mask = "";
  wlistInfo->maskType = MASK_TYPE::NOT;



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

      if(wlistInfo->mask.substr(wlistInfo->mask.size()-3, wlistInfo->mask.size()-1) == "...")
      {
        wlistInfo->maskType = MASK_TYPE::BEG;
      } else
      if(wlistInfo->mask.substr(0,3) == "...")
      {
        wlistInfo->maskType = MASK_TYPE::END;
      } else
      {
        wlistInfo->maskType = MASK_TYPE::MIX;
      }

    }
  }


  return wlistInfo;
}


// Calculate the factorial of a number..
long unsigned fact(long unsigned n)
{
  if(n == 1 || n == 2){ return 1; }

  long unsigned result = 1;
  for(long unsigned i=1;i<=n;i++) { result *= i; }
  return result;
}


// Calculate word list size.
std::unique_ptr<WlistSize> getWlistSize(const WlistInfo& wlistInfo)
{
  // For each value on range (params 1 and 2 of comand-line entry)
  std::vector<long unsigned> qtdTotalLines;
  std::vector<long unsigned> sizeLines;

  const int n = static_cast<int>(wlistInfo.alphabet.size());

  for(int p=wlistInfo.min;p<=wlistInfo.max;p++)
  {
    if(wlistInfo.repeatitions == wlistInfo.max)
    {
      qtdTotalLines.push_back(static_cast<long int>(powl(n, p)));
    } else if(wlistInfo.repeatitions == 1)
    {
      qtdTotalLines.push_back(static_cast<long int>(fact(n) / fact(n-p)));
    }
  }
  // Now, calculate the size in bytes of a range:

  int realMaskSize = 0; // Size of mask without all '~'
  for(auto& i : wlistInfo.mask)
  {
    if(i != '~'){ realMaskSize++; }
  }

  int i = 0;
  for(int p=wlistInfo.min;p<=wlistInfo.max;p++)
  {
    // (p+1) Because of \n in each line
    sizeLines.push_back((qtdTotalLines[i++] + realMaskSize) * (p+1));
  }

  auto wlistSize = std::make_unique<WlistSize>();

  for(unsigned i=0;i<=qtdTotalLines.size();i++)
  {
    wlistSize->ln += qtdTotalLines[i];
    wlistSize->by += sizeLines[i];
  }

  wlistSize->kb = wlistSize->by / pow(1024, 1);
  wlistSize->mb = wlistSize->by / pow(1024, 2);
  wlistSize->gb = wlistSize->by / pow(1024, 3);
  wlistSize->tb = wlistSize->by / pow(1024, 4);
  wlistSize->pb = wlistSize->by / pow(1024, 5);

  return wlistSize;
}


// Print information of comand-line entry.
void printInfo(const WlistInfo& wlistInfo)
{
  std::cout << "\n pssw size: "<< wlistInfo.min;
  if(wlistInfo.min != wlistInfo.max)
  std::cout << "-" << wlistInfo.max;

  if(wlistInfo.repeatitions != -1)
  std::cout << "    max repeat: " << wlistInfo.repeatitions;
  std::cout << "\n alphabet:  "  << wlistInfo.alphabet << "\n";

  if(wlistInfo.mask.size() != 0)
  std::cout << " mask:      "  << wlistInfo.mask << "\n";
  std::cout << " output:    "  << wlistInfo.filename << "\n\n";
}


// Arround double value in string
std::string arroundValue(std::string value, int decimalPoints)
{
  value += "000";
  return value.substr(0, value.find('.') + decimalPoints + 1);
}


// Print information of file size output.
void printSize(const WlistSize& wlistSize)
{
  std::cout << " Output file size (" << wlistSize.ln << " Lines)" << ":\n [";
  std::cout << wlistSize.by << "] Bytes\n";

  if(arroundValue(std::to_string(wlistSize.kb), 2) != "0.00")
  std::cout << " [" << arroundValue(std::to_string(wlistSize.kb), 2) << "] Kb\n";

  if(arroundValue(std::to_string(wlistSize.mb), 3) != "0.000")
  std::cout << " [" << arroundValue(std::to_string(wlistSize.mb), 3) << "] Mb\n";

  if(arroundValue(std::to_string(wlistSize.gb), 2) != "0.00")
  std::cout << " [" << arroundValue(std::to_string(wlistSize.gb), 2) << "] Gb\n";

  if(arroundValue(std::to_string(wlistSize.tb), 2) != "0.00")
  std::cout << " [" << arroundValue(std::to_string(wlistSize.tb), 2) << "] Tb\n";

  if(arroundValue(std::to_string(wlistSize.pb), 2) != "0.00")
  std::cout << " [" << arroundValue(std::to_string(wlistSize.pb), 2) << "] Pb\n";

  std::cout << "\n";
}

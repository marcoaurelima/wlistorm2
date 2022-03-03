#include "wlgenerate.h"

void increment(std::string& alphabet, std::vector<int>& indexes)
{
  indexes[indexes.size()-1]++;
  for(int i=indexes.size()-1;i>=1;i--)
  {
    if(indexes[i] == alphabet.size())
    {
      indexes[i] = 0;
      indexes[i-1]++;
    }
  }
};

// Verify if the quantity of repeatitions is OK in current word.
bool allowWord(const int& repeatitions, const int& max, const std::vector<int>& indexes)
{
  if(repeatitions == max){ return true; }

  for(unsigned i=0;i<indexes.size();i++)
  {
    int cont = 0;
    for(unsigned j=i;j<indexes.size();j++)
    {
      if(indexes[j] == indexes[i]){ cont++; }
    }
    if(cont > repeatitions) { return false; }
  }
  return true;
};



void printWord(const std::string& alphabet, const std::string mask, MASK_TYPE maskType, const std::vector<int>& indexes)
{
  static long unsigned cont = 1;

  std::cout << "[" << cont++ << "] ";
  for(auto& i : indexes)
  {
     std::cout << alphabet[i];
   }
  std::cout << "\n";
}

void writeWord(const std::string& alphabet, const std::vector<int>& indexes, FILE* file)
{
  std::string word;
  for(auto& i : indexes)
  {
    fputc(alphabet[i], file);
  }
  fputc('\n', file);
}

bool loop(const int& alphabetSize, const std::vector<int>& indexes)
{
    for(const auto& val : indexes)
    {
      if(val != alphabetSize){ return true; }
    }
    return false;
};


// Produce a wordlist in screen or file
void makeWordlist(WlistInfo& wlistInfo)
{
  // The combination will occur throung manipulating integer indexes.
  // A integer vector will be used.
  // To password of 5 chars, and alphabet '0123456789',
  // the vector start at [0,0,0,0,0] and ends at [9,9,9,9,9], where each]
  // integer value represents a index of alphabet.

  std::vector<std::vector<int>> indexes;
  for(unsigned i=wlistInfo.min;i<=wlistInfo.max;i++)
  {
    std::vector<int> item(i,0);
    indexes.push_back(item);
  }


  FILE* file = NULL;
  if(wlistInfo.filename != "Terminal")
  {
    file = fopen(wlistInfo.filename.c_str(), "w");
    fclose(file);
    file = fopen(wlistInfo.filename.c_str(), "a");
  }

  int alphabetSize = static_cast<int>(wlistInfo.alphabet.size()-1);

  if(wlistInfo.filename == "Terminal")
  {
    for(unsigned i=0;i<indexes.size();i++)
    {
        while(loop(alphabetSize, indexes[i]))
        {
          if(allowWord(wlistInfo.repeatitions, wlistInfo.max, indexes[i]))
          printWord(wlistInfo.alphabet, wlistInfo.mask, wlistInfo.maskType, indexes[i]);
          increment(wlistInfo.alphabet, indexes[i]);
        }
        if(allowWord(wlistInfo.repeatitions, wlistInfo.max, indexes[i]))
        printWord(wlistInfo.alphabet, wlistInfo.mask, wlistInfo.maskType, indexes[i]);
    }
  } else
  {
    for(unsigned i=0;i<indexes.size();i++)
    {
        while(loop(alphabetSize, indexes[i]))
        {
          if(allowWord(wlistInfo.repeatitions, wlistInfo.max, indexes[i]))
          writeWord(wlistInfo.alphabet, indexes[i], file);
          increment(wlistInfo.alphabet, indexes[i]);
        }
        if(allowWord(wlistInfo.repeatitions, wlistInfo.max, indexes[i]))
        writeWord(wlistInfo.alphabet, indexes[i], file);
    }
  }

  fclose(file);

  std::cout << "\n 100% Completed!\n ***\n\n";
}

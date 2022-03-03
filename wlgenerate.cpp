#include "wlgenerate.h"

void increment(std::string& alphabet, std::vector<int>& indexes)
{
  indexes[indexes.size()-1]++;
  for(int i=indexes.size()-1;i>=1;i--)
  {
    if(indexes[i] == static_cast<int>(alphabet.size()))
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

  std::string word;
  for(auto& i : indexes)
  {
      word += alphabet[i];
  }

  if(maskType == MASK_TYPE::NOT)
  {
   std::cout << word;
  } else
  if(maskType == MASK_TYPE::BEG)
  {
   std::cout << mask.substr(0, 3) << word;
  } else
  if(maskType == MASK_TYPE::END)
  {
   std::cout << word << mask.substr(3, mask.size()-1);
  } else
  if(maskType == MASK_TYPE::MIX)
  {
    std::string result;

    int j = 0;
    for(auto& i : mask){
        if(i != '~'){
            result += i;
        } else {
           result += word[j];
           ++j;
        }
    }
    std::cout << result;
  }

  std::cout << "\n";
}

void writeWord(const std::string& alphabet, const std::string mask, MASK_TYPE maskType,  const std::vector<int>& indexes, FILE* file)
{

  if(maskType == MASK_TYPE::NOT)
  {
    for(auto& i : indexes) { fputc(alphabet[i], file); }
  } else
  if(maskType == MASK_TYPE::BEG)
  {
    for(auto& i : mask.substr(0, 3)) { fputc(i, file); }
    for(auto& i : indexes) { fputc(alphabet[i], file); }
  } else
  if(maskType == MASK_TYPE::END)
  {
    for(auto& i : indexes) { fputc(i, file); }
    for(auto& i : mask.substr(3, mask.size()-1)) { fputc(alphabet[i], file); }
  } else
  if(maskType == MASK_TYPE::MIX)
  {
    std::stringstream ss;

    int j = 0;
    for(auto& i : mask){
        if(i != '~'){
            ss << i;
        } else {
           ss << alphabet[indexes[j]];
           ++j;
        }
    }
    for(auto& k : ss.str()) { fputc(k, file); }
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
  for(int i=wlistInfo.min;i<=wlistInfo.max;i++)
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
          writeWord(wlistInfo.alphabet, wlistInfo.mask, wlistInfo.maskType, indexes[i], file);
          increment(wlistInfo.alphabet, indexes[i]);
        }
        if(allowWord(wlistInfo.repeatitions, wlistInfo.max, indexes[i]))
        writeWord(wlistInfo.alphabet, wlistInfo.mask, wlistInfo.maskType, indexes[i], file);
    }
  }

  fclose(file);

  std::cout << "\n 100% Completed!\n ***\n\n";
}

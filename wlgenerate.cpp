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
bool allowWord(int repeatitions, int max, const std::vector<int>& indexes)
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


void handleWord(std::string& alphabet, std::string& filename, const std::vector<int>& indexes, FILE* file2)
{
  static long unsigned cont = 1;

/*
  if(filename == "Terminal")
  {
    std::cout << "[" << cont++ << "] ";
    for(auto& i : indexes){ std::cout << wlistInfo.alphabet[i]; }
    std::cout << "\n";
    return;
  }
*/
  cont++;

  std::string word;
  for(auto& i : indexes){ word += alphabet[i]; }

  fprintf(file2, "%s\n", word.c_str());

};

bool loop(std::string& alphabet, const std::vector<int>& indexes)
{
    for(const auto& val : indexes)
    {
      if(val != alphabet.size()-1){ return true; }
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


  
  std::ofstream file;
  if(wlistInfo.filename != "Terminal")
  {
    file = std::ofstream(wlistInfo.filename, std::ios::trunc);
    file.close();
    file = std::ofstream(wlistInfo.filename, std::ios::app);
  }

  FILE* file2 = NULL;
  if(wlistInfo.filename != "Terminal")
  {
    file2 = fopen(wlistInfo.filename.c_str(), "w");
    fclose(file2);
    file2 = fopen(wlistInfo.filename.c_str(), "a");
  }

  for(unsigned i=0;i<indexes.size();i++)
  {
      while(loop(wlistInfo.alphabet, indexes[i]))
      {
        if(allowWord(wlistInfo.repeatitions, wlistInfo.max, indexes[i]))
        handleWord(wlistInfo.alphabet, wlistInfo.filename, indexes[i], file2);
        increment(wlistInfo.alphabet, indexes[i]);
      }
      if(allowWord(wlistInfo.repeatitions, wlistInfo.max, indexes[i]))
      handleWord(wlistInfo.alphabet, wlistInfo.filename, indexes[i], file2);
  }

  //file.close();
  fclose(file2);

  std::cout << "\n 100% Completed!\n ***\n\n";
}

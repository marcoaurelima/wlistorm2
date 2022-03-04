#include "wlscreen.h"

void printLogo()
{
  std::cout << R"(
  __      __.__  .__          __
 /  \    /  \  | |__| _______/  |_  ___________  _____
 \   \/\/   /  | |  |/  ___/\   __\/  _ \_  __ \/     \
  \        /|  |_|  |\___ \  |  | (  <_> )  | \/  Y Y  \
   \__/\  / |____/__/____  > |__|  \____/|__|  |__|_|  /
        \/               \/ wordlist generator  v1.0 \/)" << '\n';
}

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
  std::cout << "\n Processing...\n";

  return true;
}

void help(){
    std::cout << "\n HOW TO USE:\n";
    std::cout << " wlistorm <min> <max> <alphabet> <(optional)>  \n\n";

    std::cout << " <min>         Minimum lenght of the generate words. \n\n";

    std::cout << " <max>         Maximum lenght of the generate words. \n\n";

    std::cout << " <alphabet>    Charactere list you will use in the wordlist generation. \n\n";

    std::cout << " -m <mask>     The mask you want use in the word. All the charactere ~ will \n";
    std::cout << "               be replaced to alphabet given. There's 3 ways to define mask:\n";
    std::cout << "               [1] ma~~s~k  [2] mask...  [3] ...mask\n";
    std::cout << "               Use type 1 if you want use the mask internally in word. \n";
    std::cout << "               Use type 2 if mask is in beginning and use 3 if is in the end. \n";
    std::cout << "               For performance reasons don't use type 1 in cases of type 3 or 3.\n\n";

    std::cout << " -f <filename> The name or path of file to save the wordlist. If you no set -f,  \n";
    std::cout << "               the generate words will be show in the screen.\n\n";

    std::cout << " -r            Define the max of characters repeatitions in genetated word.  \n";
    std::cout << "               If you not set -r, it will allow all repeatitions.   \n";
    std::cout << "               Ex.: \"-r 1\" allow word \"abcd\" but not \"abcdd\" \n";
    std::cout << "               Ex.: \"-r 2\" allow word \"abbccdd\" but not \"abbcddd\" \n";

    std::cout << "\n EXAMPLE: \n";
    std::cout << " wlistorm 8 8 abcd -m mask~~~~ -f wordlist.txt -r 1 \n\n";

    std::cout << "                                                       [github.com/marcaurelima]";
    std::cout << "\n -------------------------------------------------------------------------------";
    std::cout << "\n\n";
}

//      ¯\_(ツ)_/¯
// g++ main.cpp -o out.exe
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "heavy.cpp" // --
#include "light.cpp" // --



 // MAIN FUNCTION
int main() {


   print(compareWordContexts("dog", "car", "../../en_wiki_31M_token_196k_words.txt"));
    
    return 0;
}


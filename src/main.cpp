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

    print("reading text data...");
    std::vector<std::string> words = readWordsFromFile("../../en_wiki_31M_token_196k_words.txt");
    print("OK");

    compareWordContexts("dog", "car", words);
    compareWordContexts("dog", "cat", words);
    compareWordContexts("she", "he", words);

   /*  print(compareWordContexts("dog", "car", words));
    print(compareWordContexts("dog", "cat", words));
    print(compareWordContexts("she", "he", words)); */

    
    return 0;
}


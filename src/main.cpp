//      ¯\_(ツ)_/¯
// g++ main.cpp -o out.exe
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
#include <thread>

#include "heavy.cpp" // --
#include "light.cpp" // --



 // MAIN FUNCTION
int main() {

    print("reading text data...");
    std::vector<std::string> words = readWordsFromFile("../../en_wiki_31M_token_196k_words.txt");
    print("OK");

  /*   compareWordContexts("dog", "car", words);
    compareWordContexts("dog", "cat", words);
    compareWordContexts("she", "he", words); */


    std::vector<std::string> wrd = readWordsFromFile("../../wordlist10k.txt");


    // CREATE AN ARRAY OF float WITH SIZE OF 10K // stores similarity scored
    std::array<float, 10000> scores; // 

   

    print("Comparing... ");
    int range = wrd.size();
    size_t i1 = 0;
    size_t i2 = 0;
    for (i1; i1 < range; ++i1) {
        
        for (i2; i2 < range; ++i2) {

            //print(wrd[i1], wrd[i2]);

            float res = compareWordContexts(wrd[i1], wrd[i2], words);
            //print(wrd[i1], wrd[i2],res);

            if (i2 % 10 == 0)
            {
                print(wrd[i1], wrd[i2],res);
            }
            



        }

        //float res = compareWordContexts(wrd[i1], wrd[i2], words);
        print(wrd[i1], " OK");

    }


   /*  print(compareWordContexts("dog", "car", words));
    print(compareWordContexts("dog", "cat", words));
    print(compareWordContexts("she", "he", words)); */

    print("DONE");
    return 0;
}


#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_set> // Added for jaccardSimilarity function
#include <algorithm>
#include <thread>
#include <mutex>




// STUBBS
std::vector<std::string> readWordsFromFile(const std::string& filename);
float jaccardSimilarity(const std::unordered_set<std::string>& set1, const std::unordered_set<std::string>& set2);
float compareWordContexts(std::string comparison_word1, std::string comparison_word2, const std::vector<std::string>& words);



/*******************************************************************************
 * USAGE
 * std::string filename = "../../en_wiki_31M_token_196k_words.txt";
 * std::vector<std::string> words = readWordsFromFile(filename);
 ******************************************************************************/
std::vector<std::string> readWordsFromFile(const std::string& filename) {

    std::vector<std::string> words;
    std::ifstream file(filename);
    std::string word;

    if (file.is_open()) {
        while (file >> word) {
            words.push_back(word);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return words;
}


/*******************************************************************************
 * JACCARD SIMILARITY COEFFICIENT
 * Calculates the Jaccard similarity coefficient between two unordered_set list of strings.
 * Returns a float value between 0 and 1, where 1 indicates identical sets.
 ******************************************************************************/
float jaccardSimilarity(const std::unordered_set<std::string>& set1, const std::unordered_set<std::string>& set2) {
    std::unordered_set<std::string> intersection_set;

    // Find intersection
    for (const auto& elem : set1) {
        if (set2.find(elem) != set2.end()) {
            intersection_set.insert(elem);
        }
    }

    // Calculate union as the total unique elements in both sets
    std::unordered_set<std::string> union_set(set1);
    union_set.insert(set2.begin(), set2.end());

    // Calculate Jaccard similarity coefficient
    return static_cast<float>(intersection_set.size()) / union_set.size();
}



/*******************************************************************************
 * FUNCTION TO COMPARE CONTEXTS OF WORDS IN A TEXT DATA
 * Compares the context of two words and returns a Jaccard similarity score.
 * 
 * USAGE
 * std::vector<std::string> words = readWordsFromFile("../../en_wiki_31M_token_196k_words.txt");
 * compareWordContexts("dog", "car", words);
 ******************************************************************************/
float compareWordContexts(std::string comparison_word1, std::string comparison_word2, const std::vector<std::string>& words) {

    std::unordered_set<std::string> similar1;
    std::unordered_set<std::string> similar2;

    std::unordered_set<std::string> similar3;
    std::unordered_set<std::string> similar4;

    /* LOOP THROUGH WORDS */
    for (size_t i = 1; i < words.size() - 1; ++i) { // Avoid out-of-bounds access
        // CHECK IF THE WORD EQUALS comparison_word1
        if (words[i] == comparison_word1) {
            similar1.insert(words[i - 1]);  // Previous word
            similar2.insert(words[i + 1]);  // Next word
        }

        // CHECK IF THE WORD EQUALS comparison_word2
        if (words[i] == comparison_word2) {
            similar3.insert(words[i - 1]);  // Previous word
            similar4.insert(words[i + 1]);  // Next word
        }
    }

    // Calculate the Jaccard similarity for before and after contexts
    float res1 = jaccardSimilarity(similar1, similar3);
    float res2 = jaccardSimilarity(similar2, similar4);

    return (res1 + res2) / 2;
}

// Function to compare contexts in a separate thread
/* void threadCompare(const std::string& comparison_word1, const std::string& comparison_word2, 
                   const std::vector<std::string>& words, std::vector<float>& scores, size_t index, std::mutex& mtx) {
    float score = compareWordContexts(comparison_word1, comparison_word2, words);
    
    // Lock mutex to protect shared resource
    std::lock_guard<std::mutex> lock(mtx);
    scores[index] = score; // Update the score for this comparison
} */














































/*******************************************************************************
 * USAGE
 * std::vector<std::string> words = readWordsFromFile("../../en_wiki_31M_token_196k_words.txt");
 * compareWordContexts("dog", "car", words);
 ******************************************************************************/

/* float compareWordContexts(std::string comparison_word1, std::string comparison_word2, std::vector<std::string> words) {


    std::vector<std::string> similar1;
    std::vector<std::string> similar2;

    std::vector<std::string> similar3;
    std::vector<std::string> similar4;

    // LOOP THROUGH WORDS 
    for (size_t i = 0; i < words.size(); ++i) {
        // CHECK IF THE WORD EQUALS "word"
        if (words[i] == comparison_word1) {
            // PRINT THE PREVIOUS WORD (IF EXISTS) AND A SPECIAL MESSAGE

            // CHECK FOR UNIQUE WORDS BEFORE AND AFTER
            if (std::find(similar1.begin(), similar1.end(), words[i-1]) == similar1.end()) {
                similar1.push_back(words[i-1]);
            }

            if (std::find(similar2.begin(), similar2.end(), words[i+1]) == similar2.end()) {
                similar2.push_back(words[i+1]);
            }

        }

        if (words[i] == comparison_word2) {

            // CHECK FOR UNIQUE WORDS BEFORE AND AFTER
            if (std::find(similar3.begin(), similar3.end(), words[i-1]) == similar3.end()) {
                similar3.push_back(words[i-1]);
            }

            if (std::find(similar4.begin(), similar4.end(), words[i+1]) == similar4.end()) {
                similar4.push_back(words[i+1]);
            }

            
        }

    }

    float res1 = jaccardSimilarity(similar1, similar3);
    float res2 = jaccardSimilarity(similar2, similar4);

    return (res1+res2)/2;


} */



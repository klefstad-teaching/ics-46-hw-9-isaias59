#include "ladder.h"

int main() {
    set<string> word_list;
    load_words(word_list, "words.txt"); // Load dictionary words

    cout << "Running automated tests..." << endl;
    verify_word_ladder();  // Call function to run test cases

    cout << "\nNow running interactive mode...\n";

    string start_word, end_word;


    return 0;
}

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include "Hashset.h"
using namespace std;
int main() {

    HashSet <string> words;
    string filename="/home/lex/Downloads/Bible/Bible.txt";
    string word;

    ifstream input;
    input.open(filename);
    while(input>>word)
    {
        word=boost::algorithm::to_lower_copy(word);
        words.add(word);
    }

    int count=0;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

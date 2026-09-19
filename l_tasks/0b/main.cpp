#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    ifstream input(argv[1]);

    list<string> lines;
    string line;

    while (getline(input, line)) {
        lines.push_back(line);
    }

    map<string, int> frequency;
    int wordCount = 0;

    for (const string& currentLine : lines) {
        string word;

        for (char symbol : currentLine) {
            if (isalnum(static_cast<unsigned char>(symbol))) {
                word += symbol;
            } else if (!word.empty()) {
                ++frequency[word];
                ++wordCount;
                word.clear();
            }
        }

        if (!word.empty()) {
            ++frequency[word];
            ++wordCount;
        }
    }

    list<pair<string, int>> words;

    for (const auto& item : frequency) {
        words.push_back(item);
    }

    words.sort([](const auto& left, const auto& right) {
        return left.second > right.second;
    });

    ofstream output(argv[2]);

    output << "word,frequency,frequency_percent\n";

    for (const auto& item : words) {
        double percent = 100.0 * item.second / wordCount;
        output << item.first << ',' << item.second << ',' << percent << '\n';
    }

    return 0;
}

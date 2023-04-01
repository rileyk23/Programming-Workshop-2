//Riley King
//100873828
//this code creates a word count system for a text file.
//Jan 19th 2023

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isFound(vector<string> v, string word);
void printReport(vector<string> words, vector<int> counts);
string LowerCase(string str);

int main() {
    ifstream data("data.txt");
    vector<string> unique;
    vector<int> count;
    string word;

    while (data >> word) {
        word = LowerCase(word);
        if (isFound(unique, word)) {
            // if in vector
            for (int i = 0; i < unique.size(); i++) {
                if (unique[i] == word) {
                    count[i]++;
                }
            }
        } else {
            // if not in vector
            unique.push_back(word);
            count.push_back(1);
        }
    }

    printReport(unique, count);

    return 0;
}

bool isFound(vector<string> v, string word) {
    for (string s : v) {
        if (s == word) {
            return true;
        }
    }
    return false;
}

void printReport(vector<string> words, vector<int> count) {
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << ": " << count[i] << endl;
    }
}

string LowerCase(string str) {
    for (int i = 0; i < str.length(); i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    return str;
}


//Riley King
//100873828
//LAB #2
//Purpose:
//
//  The purpose of thise code it to act as a word count for different files
//
//How does it work:
//
//  This code reads in a text file called "data.txt" which contains an excerpt 
//  from Ontario Tech University’s history. It uses a vector to store each word 
//  and the number of times it appears in the file. The program also converts 
//  all words to lowercase and prints out a report of each word with its count in 
//  the format given.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Wordcounter class
class WordCounter{
    private:
        string word; // word string
        int count;   // count intager
    public:
    WordCounter(string word){ // constructor
        this->word = word; 
        this->count = 1;
    }

    //function to increment the count of the words
    void incrementWordCount() { count++; }
    //function to get the word
    string getWord() { return word; }
    //function to get the count
    int getCount() { return count; }
};

//check if in vector
bool isFound(vector<WordCounter> &v, string word);
//increament the count if fount in vector
void incrementWordCount(vector<WordCounter> &v, string word);
//print the report
void printReport(vector<WordCounter> &v);
//convert to lowercase
string LowerCase(string word);

int main(){
    ifstream data("data.txt");
    vector<WordCounter> words;
    string word;

    while(data >> word) {
        word = LowerCase(word);
        if (isFound(words, word)) {
            incrementWordCount(words,word); //add to count if found
        } else {
            words.push_back(WordCounter(word)); // add to vector
        }
    }
    printReport(words);
    return 0;
}

bool isFound(vector<WordCounter> &v, string word){
    //loop through the vector to check if the word is there
    for(int i = 0; i < v.size(); i++){
        if (v[i].getWord() == word){
            return true;
        }
    }
    return false;
}

void incrementWordCount(vector<WordCounter>&v, string word){
    //loop through the vector to find the word and add to count
    for(int i = 0; i < v.size(); i++){
        if(v[i].getWord() == word){
            v[i].incrementWordCount();
            return;
        }
    }
}

void printReport(vector<WordCounter> &v) {
    //loop through vector and print each part
    for (int i = 0; i < v.size(); i++){
        WordCounter cur = v[i];
        cout << cur.getWord() << " : " << cur.getCount() << endl;
    }
}

string LowerCase(string word) {
    //converts everything to lowercase
    for (int i = 0; i < word.length(); i++)
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] = word[i] + 32;
    return word;
}





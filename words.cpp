/*
 Nigel Lipps
 Tree's Tree's
 */

#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include "WordTree.h"
using namespace std;



int main() {
    ifstream fin;
    ofstream fout;
    string filename;
    
    cout << "Enter name of file with text to analyze: ";
    cin >> filename;
    fin.open(filename.c_str());
    if (fin.fail()) {
        cout << "Error opening file.\n";
        exit(1);
    }
    cout << "\nAnalyzing " << filename << ".\n";
    
    WordTree myTree;
    string word;
    string line;
    //goes through line by line
    while(fin.peek()!=EOF){
        getline(fin, line);
        string word;
        int count = 0;
        //goes through each character in the line
        for(int i=0; i < line.length(); i++){
            //adds to word
            if((90 >= line[i] && line[i] >= 65) || (122 >= line[i] && line[i] >= 97)){
                putchar(tolower(line[i]));
                word += line[i];
                count++;
            }else if(line[i-1] <= 90 && line[i-1] >= 65 && line[i] == 45
                     && line[i+1] <= 90 && line[i+1] >= 65 && count > 0){
                word += line[i];
                count++;
            }
            //adds word to tree and resets all the variables
            else{
                myTree.add(word);
                word = "";
                count = 0;
            }
        }
    }
    
    fin.close();
    fout.open("results.txt");
    cout << "\nWord counts:\n\n";
    cout << myTree;
    fout << myTree;
    cout << "\nTotal number of words in text: " << myTree.totalWords() << ".\n";
    fout << "\nTotal number of words in text: " << myTree.totalWords() << ".\n";
    cout << "Number of distinct words appearing in text: "
    << myTree.distinctWords() << ".\n";
    fout << "Number of distinct words appearing in text: "
    << myTree.distinctWords() << ".\n";
    fout.close();
    return 0;
}

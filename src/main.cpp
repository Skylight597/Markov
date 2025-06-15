#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Markov model tasks:


// 1. identify the source file to read: user specified?  Dropped into a folder? Character limit?
// 2. Read the file
// 3. Get the size of the file based on the number of characters
// 4. Get user input seed size (a number 0-10)
// 5. Store the character seeds as specified by the seed size along with the following character.
// 6. Define the starting seed.
// 7. Take the seed string and review the stored data.  Calculate the probability of the next character based on the stored data.
// 8. Generate the next character.  Continue generating until the end of the original text is reached
// 9. Store the generated text and characters.
// 10. Return the generated text to the user.
// 11. Write unit tests
// 12. Handle errors.
vector<char> findNextChar(string key, vector<char> text){

    int len = key.size();
    int endPos = len - 1;
    int loops = text.size() - endPos;
    text.push_back('\0');
    vector<char> nextLetters;
    
    for(int i = 0; i < loops; i++){

        string compString(text.begin() + i, text.begin()+endPos);
        if(key == compString){
            
            char letter = text[len];
            nextLetters.push_back(letter);

        }

        endPos++;
        len++;

    }

    return nextLetters;

}


vector<char> readFile(string fileName){

    ifstream file (fileName);
    char character;
    vector<char> fileData;

    while(file){

        character = file.get();
        fileData.push_back(character);
        
    }
    
    return fileData;
}


void mapFile (vector<char> content, int seed){

    int correctseed = seed - 1;

    map<string, vector<char>> fileMap;
    
    if(correctseed < 1){

        correctseed++;

    }
    
    int loopcount = content.size() - correctseed;

   for(int i=0; i < loopcount; i++){
        string key(content.begin()+i, content.begin()+correctseed);
        vector<char> value = findNextChar(key, content);
        
   }
    
}



int main(){

    string filePath;
    int seed;

    cout << "This program autogenerates text using a Markov model.  To begin, please input the path to your seed file." << endl;

    cin >> filePath;

    cout << "Thanks!  Now please indicate how many characters the model should use for analysis (specify a number 1-10)." << endl;

    cin >> seed;

    vector<char> printOut = readFile("textFile.txt");

    string subvector(printOut.begin()+0, printOut.begin() + 3);

    vector<char>::iterator values;
    values = search(printOut.begin(), printOut.end(), subvector.begin(), subvector.end());

    for(int i=0; i < subvector.size(); i++){

        cout << values[i];

    }

}

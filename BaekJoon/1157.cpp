#include <iostream>
#include <string>
using namespace std;

int alphabet[26];
int maxium = -1;
int index = -1;

int main(){
    string input;
    cin >> input;

    
    for(int i = 0; i < input.length(); i++){
        if(input[i] < 97)
            alphabet[input[i] - 65]++;
        else
            alphabet[input[i] - 97]++;
    }

    for(int i = 0; i < 26; i++){
        if(maxium < alphabet[i]){
            maxium = alphabet[i];
            index = i;
        }
    }

    for(int i = 0; i < 26; i++){
        if(index == i)
            continue;
        if(maxium == alphabet[i]){
            cout << "?\n";
            return 0;
        }
    }

    cout << (char)(index+65);
}
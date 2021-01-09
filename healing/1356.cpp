#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

bool yes = false;
string num;

int main(){
    cin >> num;
    for(int i = 1; i <= num.size()-1; i++){
        long long left= 1;
        long long right = 1;
        for(int j = 0; j < i; j++)
            left *= num[j] - '0';
        for(int k = i; k < num.size(); k++)
            right *= num[k] - '0';

        if(left == right){
            yes = true;
            break;
        }
    }

    if(yes)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}
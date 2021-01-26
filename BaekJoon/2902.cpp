#include <iostream>
#include <string>
using namespace std;

int main(){
    string name;
    cin >> name;
    
    cout << name[0];
    for(int i = 0; i < name.length(); i++){
        if(name[i] == '-')
            cout << name[i+1];
    }
}
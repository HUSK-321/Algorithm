#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int num = 0;
    int x = 0;

    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == '1'){
           num += (1 << x); 
        }
        x++;
    }

    cout << num << '\n';

    cin >> hex >> num;
    cout << num << oct << num << '\n';
}
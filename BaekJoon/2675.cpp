#include <iostream>
#include <string>
using namespace std;
int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        int r;
        cin >> r >> s;
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < r; j++)
                cout << s[i];
        }
        cout << '\n';
    }
    
}
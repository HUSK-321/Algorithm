#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    string all = "abcdefghijklmnopqrstuvwxyz";
    cin >> s;
    for(int i = 0; i < all.length(); i++)
        cout << (int)s.find(all[i]) << " ";
}
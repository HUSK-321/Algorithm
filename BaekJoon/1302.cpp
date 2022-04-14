#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int n, maxCount = -1;
string input;
int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<string, int> books;
    // input
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input;
        books[input]++;
    }


    string maxKey;
    for(const auto &book : books){
        if(book.second > maxCount){
            maxCount = book.second;
            maxKey = book.first;  
        }
    }

    cout << maxKey << '\n';
}
#include <iostream>
#include <string>
using namespace std;

int main(){
    string arr = {};
    getline(cin,arr);
    int count = 0;

    // 문자열이 없음
    if(arr.empty()){
        cout << count << '\n';
        return 0;
    }
    // 문자열이 있음
    count = 1;
    for(int i = 0; i < arr.length(); i++){
        if(arr[i] == ' ')
            count++;
    }
    
    // 앞 뒤 공백 정리
    if(arr[0] == ' ')
        count--;
    if(arr[arr.length() -1] == ' ')
        count--;

    cout << count << '\n';
    return 0;
}
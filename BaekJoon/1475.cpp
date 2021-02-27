#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string str;
    int num[10] = {0, };
    cin >> str;
    int n = str.length();
    for(int i = 0; i < n; i++){
        int temp = str[i] - 48;
        num[temp]++;
    }
    int result = 0;
    for(int i = 0; i < 10; i++){
        if(i != 6 && i != 9){
            result = max(num[i], result);
        }
    }
    int temp = (num[6] + num[9] + 1) / 2;
    result = max(temp, result);
    cout << result << '\n';
}
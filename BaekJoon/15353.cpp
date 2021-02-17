#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string a, b;
    string result = "";
    int toNext = 0;
    cin >> a >> b;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while(a.length() < b.length()){
        a += '0';
    }
    while(b.length() < a.length()){
        b += '0';
    }

    for(int i = 0; i < a.length(); i++){
        int temp = ((a[i] - '0') + (b[i] - '0') + toNext) % 10;
        result += to_string(temp);
        toNext = ((a[i] - '0') + (b[i] - '0') + toNext) / 10;
    }
    // 나머지 toNext는 최대 9 + 9에서 나오는 1이다 (그냥 더해도 된다)
    if(toNext > 0){
        result += to_string(toNext);
    }

    reverse(result.begin(), result.end());
    cout << result << '\n';
}
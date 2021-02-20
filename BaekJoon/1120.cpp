#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string a,b;
    cin >> a >> b;

    int result = 100;

    for(int i = 0; i <= b.length() - a.length(); i++){
        int count = 0;
        for(int j = 0; j < a.length(); j++){
            if(a[j] != b[j+i])
                count ++;
        }
        result = min(result, count);
    }

    cout << result << '\n';
}
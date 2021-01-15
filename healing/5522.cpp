#include <iostream>
using namespace std;
int main(){
    int result = 0;
    for(int i = 0; i < 5; i++){
        int ai;
        cin >> ai;
        result += ai;
    }
    cout << result << '\n';
}
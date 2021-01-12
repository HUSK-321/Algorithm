#include <iostream>
#include <string>
using namespace std;
int main(){
    int T, sum, plus;
    char result[81];
    cin >> T;
    for(int i = 0; i < T; i++){
        sum = 0; plus = 1;
        cin >> result[i];
        if(result[i] == 'O'){
            sum += plus;
            plus++;
        } else {
            plus = 1;
        }
        cout << sum << '\n';
    }
}
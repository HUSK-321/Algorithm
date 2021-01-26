#include <iostream>
using namespace std;
int main(){
    int A;
    int sum = 0;
    char C;
    cin >> A;
    for (int i = 0; i < A; i++){
        cin >> C;
        sum += C-48;
    }
    cout << sum;
}
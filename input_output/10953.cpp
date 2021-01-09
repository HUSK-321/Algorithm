#include <iostream>
using namespace std;
int main(){
    int A, B, T;
    char c;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> A >> c >> B;
        cout << A+B << endl;
    }
    return 0;
}


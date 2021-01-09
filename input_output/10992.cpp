#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for(int j = 0; j < n-i; j++)
            cout << " ";
        if(i == 1)
            cout << "*";
        else if(i == n){
            for (int k = 0; k < 2*n-1; k++)
                cout << "*";
        }
        else{
            cout << "*";
            for(int k = 0; k < 2*i-3; k++)
                cout << " ";
            cout << "*";
        }
        cout << endl;
    }
}
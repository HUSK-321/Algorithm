#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n+1; i++){
        for(int j = i; j < n-1; i++)
            cout << " ";

        for(int j = 0; j <= 2*i; j++){
            if(j % 2 == 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl; 
    }
}

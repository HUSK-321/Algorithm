#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if (0<n && n<10){
        for(int i = 1; i < 10; i++)
            cout << n << " * " << i << " = " << n*i << endl;
    }
    return 0;
}
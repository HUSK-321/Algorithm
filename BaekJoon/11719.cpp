#include <iostream>
#include <string>
using namespace std;
int main(){
    string C[100];
    for(int i = 0; i < 100; i++)
        getline(cin, C[i]);
    for(int i = 0; i < 100; i++)
        cout << C[i] << endl;
}
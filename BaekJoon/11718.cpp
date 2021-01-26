#include <iostream>
#include <string>
using namespace std;
int main(){
    string C;
    while(1){
        getline(cin, C);
        if(C=="")
            break;
        cout << C << endl;
    }
}
#include <iostream>
using namespace std;
int main(){
    int year;
    cin >> year;
    //4의 배수, 100의 배수는 안되지만 400의 배수는 가능
    if((year%4 == 0 && year%100 != 0) || year%400 == 0){
        cout << "1" << '\n';
    } else {
        cout << "0" << '\n';
    }
}
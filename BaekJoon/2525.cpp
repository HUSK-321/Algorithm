#include <iostream>
using namespace std;

const int HOUR = 24;
const int MIN = 60;

int main(){
    int a, b;
    cin >> a >> b;

    int c;
    cin >> c;

    a += c / MIN;
    b += c % MIN;

    if(b >= MIN)
        a++;

    cout << a % HOUR << " " << b% MIN << '\n';
}
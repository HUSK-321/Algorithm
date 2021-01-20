#include <iostream>
using namespace std;
int main(){
    int count = 5;
    int l, p, area, num;
    cin >> l >> p;
    area = l*p;
    while(count--){
        cin >> num;
        cout << num - area << '\n';
    }
}
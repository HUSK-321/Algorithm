#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int i = 2;
    while(1){
        if(n == 1)
            break;
        if(n % i == 0){
            cout << i << "\n";
            n /= i;
        } else{
            i++;
        }
    }
    return 0;
}
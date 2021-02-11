#include <iostream>
using namespace std;
int main(){
    int a,b, count = 1;
    cin >> a >> b;
    while(true){
        if(b < a){
            count = -1;
            break;
        }
        if(a==b){
            break;
        } else {
            if(b%2 == 0){
                b /= 2;
            }else {
                if(b%10 == 1){
                    b /= 10;
                } else{
                    count = -1;
                    break;
                }
            }
        }
        count++;
    }
    cout << count << "\n";
}
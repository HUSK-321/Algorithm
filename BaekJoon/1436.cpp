#include <iostream>
using namespace std;
int main(){
    int n;
    int i = 0, count = 0, temp = 0;
    scanf("%d", &n);
    while(count != n){
        i++;
        temp = i;
        while(temp){
            if(temp%1000 == 666){
                count++;
                break;
            } else
                temp /= 10;
        }
    }
    printf("%d\n", i);
}
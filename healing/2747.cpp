#include <iostream>
using namespace std;
int number[46];
int main(){
    int n, result = 0;
    number[0] = 0;
    number[1] = 1;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        number[i] = number[i-1] + number[i-2];
    }
    printf("%d\n", number[n]);
}
// 0 1 1 2 3 5
// i = i -1   +   i -2
// 배열로 넣으면 될 듯 하다
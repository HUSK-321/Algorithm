#include <iostream>
using namespace std;
int main(){
    int n;
    int coin[6] = {500, 100, 50, 10, 5, 1};
    scanf("%d", &n);
    // 1000 - n 을 동전으로
    // 동전은 500, 100, 50, 10, 5, 1
    int result = 0;
    n = 1000 - n;
    for(int i = 0; i < 6; i++){
        while(n-coin[i] >= 0){
            n -= coin[i];
            result++;
        }
    }
    printf("%d\n", result);
}
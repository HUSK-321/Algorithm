#include <iostream>
#include <cstring>
using namespace std;

bool isprime[1000];
int N, temp;
int main(){
    memset(isprime, true, sizeof(isprime));     // 초기화
    isprime[1] = false;
    // 에라토스테네스의 채
    for(int i = 2; i*i < 1000; i++) {
        for(int j = i*i; j < 1000; j += i){
            isprime[j] = false;
        }
    }

    int count = 0;

    scanf("%d", &N);
    while(N--){
        scanf("%d", &temp);
        if(isprime[temp])
            count++;
    }
    printf("%d", count);
}
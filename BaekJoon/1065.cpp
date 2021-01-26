#include <iostream>
int main(){
    int N;
    scanf("%d", &N);
    if( N < 100 ){
        printf("%d", N);
    } else {
        int temp = 99;

        for(int i = 100; i <= N; i++){
            int hundred = i / 100;  // 백의 자리수 - 210 / 100 = 2
            int ten = i / 10 % 10;  // 십의 자리수 - 210 / 10 = 21이니 다시 10으로 나누기
            int one = i % 10;       // 일의 자리수
            if((hundred - ten) == (ten - one))
                temp++;
        }
        printf("%d", temp);
    }
}
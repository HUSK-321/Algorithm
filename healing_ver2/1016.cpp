#include <iostream>
using namespace std;
// max - min <= 1,000,000
long long arr[1000001];
int main(){
    // 입력값을 받고 for문에서 min~max만큼 돔
    // for문에서 제곱수를 검사
    long long min, max;
    int count = 0;
    scanf("%lld %lld", &min, &max);

    for(long long i = 2; i*i <= max; i++){
        long long num = min/(i*i);

        if(min % (i * i)) //안나눠짐
            num++;  // 그럼 다음꺼부터

        while(num*i*i <= max){
            //이후 i*i의 배수들 다 삭제
            arr[num*i*i - min] = 1;
            num++;
        }

    }


    for(int i = 0; i <= max - min; i++){
        if(arr[i] == 0) count++;
    }
    printf("%d", count);
}
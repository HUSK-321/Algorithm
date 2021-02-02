#include <iostream>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int input, temp, num, reverse = 0;
        int arr[10];
        bool isRight = true;
        num = 0;
        scanf("%d", &input);
        temp = input;
        // 뒤집기
        while(temp) {
            reverse *= 10;
            reverse += temp % 10;
            temp /= 10;
        }
        input += reverse;
        // 배열에 넣기
        while(input){
            arr[num] = input % 10;
            num++;
            input /= 10;
        }
        // 배열에서 비교, num = 자리수
        for(int i = 0; i < num/2; i++){
            if(arr[i] != arr[num - 1 - i]){
                isRight = false;
            }
        }
        // 출력
        if(isRight){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
    }
}
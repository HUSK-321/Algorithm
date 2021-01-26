#include <iostream>
using namespace std;
int T, a, b;
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &a, &b);
         // a ^ b 를 케이크처럼 쉽게 구하는 방법
         // a를 10으로 나눈 나머지는 a의 일의자리 숫자임
         // 그럼 a, b의 1의 자리 숫자를 계속 구하면 되는 것 아니겠나?
         // 2^4이라면 2를 4번 곱하게 된다
         // 그러니 for문을 b만큼 돌리면 되는거 아니겠나?
        int num1 = a % 10;
        int result = num1;
        for(int i = 1; i < b; i++){ // 위에서 한번 했으니껜
            result = (result * num1) %10;
        }
        if(result == 0)
            result = 10;
        printf("%d\n", result);

    }
}
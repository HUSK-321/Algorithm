#include <iostream>
using namespace std;

int Search(int i){   // 분해합을 출력
    int temp = i;
    while(i){
        temp = temp + i%10;
        i = i/10;
    }
    return temp;
}
int main(){
    int n;
    scanf("%d", &n);
    // 분해합 : 원래수 + 각 자리 수
    // 여기서 원래 수가 분해합의 생성자
    // 구해야 할건 n의 가장 작은 생성자
    for(int i = 1; i < n; i++){
        if(Search(i) == n){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d", 0);
    return 0;
}
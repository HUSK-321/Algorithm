#include <iostream>
using namespace std;
int arr[10001];
int n,t,k,s;
int main(){
    // n 단원의 갯수, t 남은 시간
    scanf("%d %d", &n, &t);
    while(n--){
        // 단원별 공부시간 K, 단원의 배점 S
        scanf("%d %d", &k, &s);
        for(int i = t; i >= k; i--)
            arr[i] = max(arr[i], arr[i-k]+s);
    }
    printf("%d\n", arr[t]); // 220
    printf("%d\n", arr[250]); // 150
    printf("%d\n", arr[200]); // 150
    printf("%d\n", arr[199]); // 110
    printf("%d\n", arr[100]); //70
    printf("%d\n", arr[50]); //40
    printf("%d\n", arr[49]); //0

}
#include <iostream>
using namespace std;
long long arr[10001];
int main(){
    int n;
    scanf("%d", &n);
    long long div = 987654321;
    // 2사람이 악수를 하는게 기준
    // 영역이 2개로 나뉘게 된다
    arr[0] = 1;
    arr[2] = 1;
    for(int i = 4; i <= n; i += 2){
        for(int j = 0; j <= i-2; j += 2){
            arr[i] += arr[j] * arr[i - j - 2];
            arr[i] %= div;
        }
    }
    printf("%d\n", arr[n]);
}
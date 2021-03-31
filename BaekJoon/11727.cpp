#include <iostream>
using namespace std;
long long arr[1001];
int n;
int main(){
    scanf("%d", &n);
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 3;

    for(int i = 3; i <= n; i++)
        arr[i] = (arr[i-1] + arr[i-2]*2) % 10007;

    printf("%lld\n", arr[n]);
}
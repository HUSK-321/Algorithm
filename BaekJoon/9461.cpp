#include <iostream>

using namespace std;
int t, n;
long long arr[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
int main(){
    for(int i = 11; i <= 100; i++)
        arr[i] = arr[i-1] + arr[i-5];

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", arr[n]);
    }
    
}
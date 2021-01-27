#include <iostream>
using namespace std;
int main(){
    int n;
    int arr[1010];
    scanf("%d", &n);
    arr[0] = 1;
    arr[1] = 1;
    // arr[i] = arr[i-1] + arr[i-2]
    for(int i = 2; i <=n; i++)
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;
    printf("%d", arr[n]);
}
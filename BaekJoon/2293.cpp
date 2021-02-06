#include <iostream>
using namespace std;
int main(){
    int n, k;
    int search[10001] = {0, };
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    search[0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = arr[i]; j <= k; j++)
            if(j - arr[i] >= 0)
                search[j] += search[j - arr[i]];
    printf("%d\n", search[k]);
}
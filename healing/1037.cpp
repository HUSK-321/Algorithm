#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int N, result;
    scanf("%d", &N);
    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    sort(arr, arr+N);

    printf("%d\n", arr[0]*arr[N-1]);
}
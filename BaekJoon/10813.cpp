#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,m,a,b;
    scanf("%d %d", &n, &m);
    int arr[n+2];
    for(int i = 1; i<=n; i++)
        arr[i] = i;
    while(m--) {
        scanf("%d %d", &a, &b);
        swap(arr[a], arr[b]);
    }
    for(int i = 1; i<=n; i++)
        printf("%d ", arr[i]);

}
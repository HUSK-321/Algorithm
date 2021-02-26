#include <iostream>
using namespace std;
int arr[100001];
int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &arr[0]);
    for(int i = 1; i < n; i++){
        int input;
        scanf("%d", &input);
        arr[i] = arr[i-1] + input;
    }
    scanf("%d", &m);
    while(m--){
        int x, y;
        scanf("%d %d", &x, &y);
        if(x==1)
            printf("%d\n", arr[y-1]);
        else 
            printf("%d\n", arr[y-1] - arr[x-2]);
    }
}
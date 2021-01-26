#include <iostream>
int arr[11];
int n;
int function(){
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i = 4; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    return arr[n];
}

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d", &n);
        printf("%d \n", function());
    }
    return 0;
}
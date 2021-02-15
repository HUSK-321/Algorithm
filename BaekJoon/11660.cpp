#include<iostream>
using namespace std;
int arr[1025][1025];
int n, m;
int main(){
    int x1, y1, x2, y2;
    int input;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &input);
            arr[i+1][j+1] = arr[i][j+1] + arr[i+1][j] - arr[i][j] + input;
        }
    }
    while(m--){
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        int result = arr[y2][x2] - arr[y1 - 1][x2] - arr[y2][x1 - 1] + arr[y1 - 1][x1 - 1];
        printf("%d\n", result);
    }
    
}
/*
1  3  6  10
12 15 19 24
27 31 36 42
46 51 57 64
*/
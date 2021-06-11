#include <iostream>
using namespace std;

int n;
int num[1000001];
int track[1000001];

int bfs(){
    num[1] = 0;

    for(int i = 2; i <= n; i++){
        num[i] = num[i-1] + 1;
        track[i] = i-1;

        if(i%3 == 0 && num[i] > num[i/3] + 1){
            num[i] = num[i/3] + 1;
            track[i] = i/3;
        }

        if(i%2 == 0 && num[i] > num[i/2] + 1){
            num[i] = num[i/2] + 1;
            track[i] = i/2;
        }
        
    }
    return num[n];
}

int main(){
    scanf("%d", &n);

    printf("%d\n", bfs());
    while(n != 0){
        printf("%d ", n);
        n = track[n];
    }
}
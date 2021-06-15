#include <iostream>
#include <algorithm>
using namespace std;

int n, m, sum = 0;
int mem[10001];
int abyte[101];
int cost[101];

int main(){
    scanf("%d %d", &n ,&m);

    for(int i = 0; i < n; i++)
        scanf("%d", &abyte[i]);

    for(int i = 0; i < n; i++){
        scanf("%d", &cost[i]);
        sum += cost[i];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = sum; j >= cost[i]; j--){
            mem[j] = max(mem[j], mem[j-cost[i]] + abyte[i]);
        }
    }
    for(int i = 0; i < 10001; i++){
        if(mem[i] >= m){
            printf("%d\n", i);
            break;
        }
    }
    
}
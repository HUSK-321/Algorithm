#include <iostream>
#include <algorithm>
using namespace std;

int n, m, from, to, cost;
int bus[101][101];

// 플로이드-와샬 알고리즘
// 1~2로 가는데 만약 3을 거쳐가는게 더 빠르다고 하면 3을 거쳐가는 비용으로 업데이트
void F(){
    for(int v = 1; v <= n; v++){
        for(int f = 1; f <= n; f++){
            if(!bus[f][v])
                continue;
            for(int t = 1; t <= n; t++){
                if(!bus[v][t] || f == t)
                    continue;
                
                if(bus[f][t] > bus[f][v] + bus[v][t] || !bus[f][t])
                    bus[f][t] = bus[f][v] + bus[v][t];
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &from, &to, &cost);

        if(!bus[from][to])
            bus[from][to] = cost;
        else
            bus[from][to] = min(bus[from][to], cost);
    }

    F();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", bus[i][j]);
        }
        printf("\n");
    }
}
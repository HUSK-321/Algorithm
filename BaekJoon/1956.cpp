#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 999999999
using namespace std;

int v, e;
int a, b, c;
int road[401][401];
int res = MAX;

void Floyd(){
    for(int via = 1; via <= v; via++){
        for(int from = 1; from <= v; from++){
            if(road[from][via] == MAX)
                continue;

            for(int to = 1; to <= v; to++){
                if(road[via][to] == MAX)
                    continue;
                
                if(road[from][to] > road[from][via] + road[via][to])
                    road[from][to] = road[from][via] + road[via][to];
            }
        }
    }
}

int main(){
    for(int i = 0; i <= 400; i++){
        for(int j = 0; j <= 400; j++){
            road[i][j] = MAX;
        }
    }

    scanf("%d %d", &v, &e);

    while (e--){
        scanf("%d %d %d", &a, &b, &c);
        road[a][b] = c;
    }

    Floyd();

    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            if(i == j)
                continue;

            if(road[i][j] != MAX && road[j][i] != MAX)
                res = min(res, road[i][j] + road[j][i]);
        }
    }

    if(res == MAX)
        printf("-1\n");
    else
        printf("%d", res);
}
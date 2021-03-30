#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int n, res = 0;
int arr[501][501];
int visit[501][5001];
int goX[4] = {0, 0, 1, -1};
int goY[4] = {1, -1, 0, 0};

int DFS(int x, int y){
    if(visit[x][y] == -1){   // 아직 방문 안한곳이면
        visit[x][y] = 1;
        int bamboo = 0;
        for(int i = 0; i < 4; i++){
            int nextX = x + goX[i];
            int nextY = y + goY[i];
            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && arr[nextX][nextY] > arr[x][y])
                bamboo = max(bamboo, DFS(nextX, nextY));
        }
        visit[x][y] += bamboo;
    }
    return visit[x][y];
}

int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
            visit[i][j] = -1;
        }
    }
        
            
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            res = max(res, DFS(i, j));

    printf("%d\n", res);
}
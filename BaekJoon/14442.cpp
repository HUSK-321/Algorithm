#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m, k;
int goX[4] = { 0, 0, 1, -1 };
int goY[4] = { 1, -1, 0, 0 };
int map[1001][1001];
int cost[1001][1001][11];

int BFS(){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 0));
    cost[0][0][0] = 1;

    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int breakCnt = q.front().second;
        q.pop();

        if(curX == m-1 && curY == n-1)
            return cost[curY][curX][breakCnt];
        
        for(int i = 0; i < 4; i++){
            int nextX = curX + goX[i];
            int nextY = curY + goY[i];
                
            if(nextX >= 0 && nextX <= m-1 && nextY >= 0 && nextY <= n-1){
                if(breakCnt < k && map[nextY][nextX] == 1 && cost[nextY][nextX][breakCnt+1] == 0){
                    cost[nextY][nextX][breakCnt + 1] = cost[curY][curX][breakCnt] + 1;
                    q.push(make_pair(make_pair(nextX, nextY), breakCnt + 1));
                }
                else if(map[nextY][nextX] == 0 && cost[nextY][nextX][breakCnt] == 0){
                    cost[nextY][nextX][breakCnt] = cost[curY][curX][breakCnt] + 1;
                    q.push(make_pair(make_pair(nextX, nextY), breakCnt));
                }
            }
        
        }
    }
    return -1;
}

int main(){
    scanf("%d %d %d", &n ,&m, &k);

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < m; j++)
            map[i][j] = temp[j] - '0';
    }

    printf("%d\n", BFS());
}
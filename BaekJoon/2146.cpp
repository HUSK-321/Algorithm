#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, answer = 999999999;
int map[101][101];
bool visit[101][101];
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };

int IsOut(int y, int x){
    if(y < 0 || x < 0 || y >= n || x >= n)
        return true;
    return false;
}

void SearchBridge(int islandNo){
    memset(visit, false, sizeof(visit));

    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == islandNo)
                q.push({i, j});
        }
    }    
    int setCount = 0;
    while(!q.empty()){
        int curTurn = q.size();
        for(int i = 0; i < curTurn; i++){
            int curY = q.front().first;
            int curX = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nextY = curY + moveY[i];
                int nextX = curX + moveX[i];

                if(IsOut(nextY, nextX))             continue;
                if(map[nextY][nextX] == islandNo)   continue;
                if(visit[nextY][nextX])             continue;
                if(map[nextY][nextX] != 0){
                    answer = min(answer, setCount);
                    return;
                }

                q.push({nextY, nextX});
                visit[nextY][nextX] = true;
            }
        }
        setCount++;
    }
    
}

void DivideIsland(int y, int x, int islandNo){
    visit[y][x] = true;
    map[y][x] = islandNo;
    queue<pair<int, int>> q;
    q.push({y, x});

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];

            if(IsOut(nextY, nextX))         continue;
            if(map[nextY][nextX] == 0)      continue;
            if(visit[nextY][nextX])         continue;

            visit[nextY][nextX] = true;
            map[nextY][nextX] = islandNo;
            q.push({nextY, nextX});
        }
    }
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(visit, false, sizeof(visit));

    // input
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    // divide island
    int number = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visit[i][j]) continue;
            if(map[i][j] != 1)  continue;
            
            DivideIsland(i, j, number);
            number++;
        }
    }

    // find answer;
    memset(visit, false, sizeof(visit));

    for(int i = 1; i <= number; i++)
        SearchBridge(i);

    cout << answer << '\n';
}
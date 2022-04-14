#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, timeLimit;
int map[101][101];
bool visit[101][101][3];
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };

int IsOut(int y, int x){
    if(y < 1 || x < 1 || y > n || x > m)
        return true;
    return false;
}

void FindPrincess(){
    queue<pair<pair<int, int>, pair<bool, int>>> q;
    q.push({{1, 1}, {false, 0}});
    visit[1][1][0] = true;

    while (!q.empty()){
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        bool haveGram = q.front().second.first;
        int curTime = q.front().second.second;
        q.pop();

        // complete
        if(curTime > timeLimit){
            break;
        }
        if(curX == m && curY == n){
            cout << curTime << '\n';
            return;
        }

        // search next position
        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];

            if(IsOut(nextY, nextX)) continue;
            // have gram
            if(haveGram && !visit[nextY][nextX][1]){
                visit[nextY][nextX][1] = true;
                q.push({{nextY, nextX}, {haveGram, curTime+1}});
                continue;
            }

            if(visit[nextY][nextX][0])  continue;
            if(map[nextY][nextX] == 0){
                visit[nextY][nextX][0] = true;
                q.push({{nextY, nextX}, {haveGram, curTime+1}});
                
            }else if(map[nextY][nextX] == 2){
                visit[nextY][nextX][1] = true;
                q.push({{nextY, nextX}, {true, curTime+1}});
            }
        }
    }
    

    cout << "Fail\n";
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(visit, false, sizeof(visit));

    // input
    cin >> n >> m >> timeLimit;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }

    FindPrincess();
    return 0;
}
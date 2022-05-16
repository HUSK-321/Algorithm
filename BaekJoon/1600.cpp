#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int moveY[] = { 0, 0, 1, -1 };
int moveX[] = { 1, -1, 0, 0 };
pair<int, int> horseMove[] = { {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, 
                               {1, -2}, {2, -1}, {2, 1}, {1, 2} };
int k, w, h;
int map[201][201];
bool visit[201][201][31];

bool IsOut(int y, int x){
    if(x < 0 || y < 0 || x >= w || y >= h)
        return true;
    if(map[y][x] == 1)
        return true;
    return false;
}

bool SearchCount(){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {0, 0}});

    while(!q.empty()){
        int curK = q.front().first.first;
        int curCount = q.front().first.second;
        int curY = q.front().second.first;
        int curX = q.front().second.second;
        q.pop();

        // if now on finish
        if(curY == h-1 && curX == w-1){
            cout << curCount << '\n';
            return true;
        }

        // can horse movement
        if(curK < k){
            for(int i = 0; i < 8; i++){
                int nextY = curY + horseMove[i].first;
                int nextX = curX + horseMove[i].second;

                if(IsOut(nextY, nextX)) continue;
                if(visit[nextY][nextX][curK+1]) continue;

                q.push({{curK+1, curCount+1}, {nextY, nextX}});
                visit[nextY][nextX][curK+1] = true;
            }
        }

        // normal movement
        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];;
            int nextX = curX + moveX[i];

            if(IsOut(nextY, nextX)) continue;
            if(visit[nextY][nextX][curK]) continue;

            q.push({{curK, curCount+1}, {nextY, nextX}});
            visit[nextY][nextX][curK] = true;  
        }
    }

    return false;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> k;
    cin >> w >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> map[i][j];
        }
    }

    if(!SearchCount())
        cout << -1 << '\n';
}
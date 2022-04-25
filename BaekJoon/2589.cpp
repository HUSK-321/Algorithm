#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int col, row;
char map[51][51];
bool visit[51][51];
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };

void InitVisit(){
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            visit[i][j] = false;
        }
    }
}

bool IsOut(int y, int x){
    if(y < 0 || x < 0 || y >= col || x >= row)
        return true;
    return false;
}

int SearchMaxdistance(int startY, int startX){
    InitVisit();

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {startY, startX}});
    visit[startY][startX] = true;
    int res = 0;

    while(!q.empty()){
        int curY = q.front().second.first;
        int curX = q.front().second.second;
        int curCount = q.front().first;
        q.pop();

        res = max(res, curCount);

        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];

            if(IsOut(nextY, nextX))         continue;
            if(visit[nextY][nextX])         continue;
            if(map[nextY][nextX] == 'W')    continue;

            q.push({curCount+1, {nextY, nextX}});
            visit[nextY][nextX] = true;
        }
    }
    
    return res;
}


int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> col >> row;
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            cin >> map[i][j];
        }
    }

    // search
    int maxDistance = 0;
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            if(map[i][j] == 'L'){
               maxDistance = max(maxDistance, SearchMaxdistance(i, j));
            }
        }
    }

    // print
    cout << maxDistance << '\n';
}
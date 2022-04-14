#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool visit[101][101];
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };
int row, col;

bool IsOut(int y, int x){
    if(y < 0 || x < 0 || y >= col || x >= row)
        return true;
    return false;
}

int SearchArea(int startY, int startX, int areaColor, vector<vector<int>>& picture){
    queue<pair<int, int>> q;
    q.push({startY, startX});
    visit[startY][startX] = true;
    int areaCount = 1;

    while (!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];

            if(IsOut(nextY, nextX))                 continue;
            if(visit[nextY][nextX])                 continue;
            if(picture[nextY][nextX] != areaColor)  continue;

            q.push({nextY, nextX});
            visit[nextY][nextX] = true;
            areaCount++;
        }
    }
    return areaCount;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    // init
    memset(visit, false, sizeof(visit));
    row = n;
    col = m;

    int areaCount = 0;
    int maxSizeArea = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visit[i][j] && picture[i][j] != 0){
                areaCount++;
                maxSizeArea = max(maxSizeArea, SearchArea(i, j, picture[i][j], picture));
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = areaCount;
    answer[1] = maxSizeArea;
    return answer;
}
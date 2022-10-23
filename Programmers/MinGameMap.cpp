#include <vector>
#include <queue>
using namespace std;

const int moveX[] = { 0, 0, 1, -1 };
const int moveY[] = { 1, -1, 0, 0 };
bool visit[101][101];

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();

    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});

    while (!q.empty()){
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int curCount = q.front().second;
        q.pop();

        if(curY == n-1 && curX == m-1)
            return curCount;

        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];

            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= m)  continue;
            if(maps[nextY][nextX] == 0) continue;
            if(visit[nextY][nextX])     continue;

            visit[nextY][nextX] = true;
            q.push({{nextY, nextX}, curCount+1});
        }
    }
    

    return -1;
}
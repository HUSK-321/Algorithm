#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 101;
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };
int maxX, maxY;

bool IsOutRange(int x, int y)
{
    return (x < 0 || y < 0 || x >= maxX || y >= maxY);
}

int GetMinDistance(const pair<int, int>& from, const pair<int, int>& end, const vector<string>& maps)
{
    vector<vector<bool>> visit(maxY, vector<bool>(maxX, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({from, 0});
    visit[from.first][from.second] = true;

    while (!q.empty())
    {
        auto curPos = q.front().first;
        auto curCount = q.front().second;
        q.pop();

        if(curPos == end)
        {
            return curCount;
        }

        for(int i = 0; i < 4; ++i)
        {
            int nextY = curPos.first + moveY[i];
            int nextX = curPos.second + moveX[i];

            if(IsOutRange(nextX, nextY) || visit[nextY][nextX]) continue;
            visit[nextY][nextX] = true;
            if(maps[nextY][nextX] == 'X')   continue;

            q.push({{nextY, nextX}, curCount + 1});
        }
    }
    return -1;
}


int solution(vector<string> maps) 
{
    maxY = maps.size();
    maxX = maps[0].size();
    pair<int, int> start, lever, exit;

    for(int y = 0; y < maxY; ++y)
    {
        for(int x = 0; x < maxX; ++x)
        {
            if(maps[y][x] == 'S')
                start = {y, x};
            else if (maps[y][x] == 'L')
                lever = {y, x};
            else if (maps[y][x] == 'E')
                exit = {y, x};
        }
    }

    auto distanceToLever{ GetMinDistance(start, lever, maps) };
    auto distanceToExit{ GetMinDistance(lever, exit, maps) };

    return (distanceToLever == -1 || distanceToExit == -1) ? -1 : distanceToExit + distanceToLever;
}
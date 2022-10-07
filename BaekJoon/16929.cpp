#include <iostream>

using namespace std;

const int MAX = 51;

int n, m;
char map[MAX][MAX];
bool visit[MAX][MAX];
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };

bool IsOut(int y, int x){
    if(y < 0 || x < 0 || y >= n || x >= m)
        return true;
    return false;
}

bool SearchCycle(int prevY, int prevX, int curY, int curX, const char color){
    if(visit[curY][curX])
        return true;
    
    visit[curY][curX] = true;

    for(int i = 0; i < 4; i++){
        int nextY = curY + moveY[i];
        int nextX = curX + moveX[i];

        if(IsOut(nextY, nextX))                 continue;
        if(map[nextY][nextX] != color)          continue;
        if(prevY == nextY && prevX == nextX)    continue;

        if(SearchCycle(curY, curX, nextY, nextX, color))
            return true;
    }
    return false;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visit[i][j]) continue;
            if(SearchCycle(-1, -1, i, j, map[i][j])){;
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";
    return 0;
}
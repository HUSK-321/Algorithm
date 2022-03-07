#include <iostream>
#include <queue>
using namespace std;

int n;
int totalCount = 0;
int map[17][17];
// 0 - 가로, 1 - 세로, 2 - 대각선
pair<int, int> direction[] = {{0, 1}, {1, 0}, {1, 1}};

bool isOut(int y, int x){
    if(x <= 0 || y <= 0 || x > n || y > n)
        return true;
    return false;
}
bool isStuck(int y, int x){
    if(map[y][x] == 1)
        return true;
    
    return false;
}

void MakePipe(int y, int x, int dir){
    if(y == n && x == n){
        totalCount++;
        return;
    }

    for(int i = 0; i < 3; i++){
        if(i == 1 && dir == 0)  continue;
        if(i == 0 && dir == 1)  continue;

        int nextY = y + direction[i].first;
        int nextX = x + direction[i].second;

        if(isOut(nextY, nextX))     continue;
        if(isStuck(nextY, nextX))   continue;

        if(i == 2)
            if(isStuck(y+1, x) || isStuck(y, x+1))
                continue;
        MakePipe(nextY, nextX, i);
    }
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> map[i][j];
    
    MakePipe(1, 2, 0);

    cout << totalCount << '\n';
}
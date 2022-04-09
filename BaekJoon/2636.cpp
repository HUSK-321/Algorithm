#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int c, r;
int cheese[101][101];
bool visit[101][101];
int totalCheese = 0;

int moveC[] = { 0, 0, 1, -1 };
int moveR[] = { 1, -1, 0, 0 };

bool IsOut(int row, int col){
    if(row > r || row < 0 || col < 0 || col > c)
        return true;
    return false;
}

bool TimeCount(int& cheeseCount){
    bool melted = false;
    int meltedCount = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()){
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextR = moveR[i] + curR;
            int nextC = moveC[i] + curC;

            if(IsOut(nextR, nextC)) continue;
            if(visit[nextR][nextC]) continue;

            if(cheese[nextR][nextC] == 0){
                q.push({nextR, nextC});
            }
            else{
                meltedCount++;
                melted = true;
                cheese[nextR][nextC] = 0;
            }
            visit[nextR][nextC] = true;
        }
    }
    
    if(melted)
        cheeseCount = meltedCount;
    return melted;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> cheese[i][j];
            if(cheese[i][j] == 1)
                totalCheese++;
        }
    }

    // solve
    int meltCount = 0;
    int cheeseCount = 0;
    while (true){
        memset(visit, false, sizeof(visit));
        if(TimeCount(cheeseCount) == false)
            break;
        meltCount++;
    }

    cout << meltCount << '\n';
    cout << cheeseCount << '\n';
    
}
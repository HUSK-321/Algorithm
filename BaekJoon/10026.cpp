#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, regionCount1 = 0, regionCount2 = 0;
const char R = 'R', G = 'G';
char map[101][101];
bool visit[101][101];
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };

bool isOut(int x, int y){
    if(x < 0 || y < 0 || x >= n || y>= n)
        return true;
    return false;
}

void searchByBfs(int x, int y, const bool isRGSame){
    char curRegion = map[x][y];
    bool isInputRG = (curRegion == R || curRegion == G) ? true : false;
    queue<pair<int, int>> q;  // x, y
    q.push(make_pair(x, y));

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(unsigned i = 0; i < 4; i++){
            int nextX = curX + moveX[i];
            int nextY = curY + moveY[i];

            if(isOut(nextX, nextY)) continue;
            if(visit[nextX][nextY]) continue;

            if(isRGSame && isInputRG){
                if(map[nextX][nextY] == R || map[nextX][nextY] == G){
                    visit[nextX][nextY] = true;
                    q.push(make_pair(nextX, nextY));
                }
            }
            else {
                if(map[nextX][nextY] == curRegion){
                    visit[nextX][nextY] = true;
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    for(unsigned x = 0; x < n; x++)
        for(unsigned y = 0; y < n; y++)
            cin >> map[x][y];
    
    // solve
    for(unsigned x = 0; x < n; x++){
        for(unsigned y = 0; y < n; y++){
            if(!visit[x][y]){
                regionCount1++;
                searchByBfs(x, y, false);
            }
        }
    }

    memset(visit, false, sizeof(visit));

    for(unsigned x = 0; x < n; x++){
        for(unsigned y = 0; y < n; y++){
            if(!visit[x][y]){
                regionCount2++;
                searchByBfs(x, y, true);
            }
        }
    }

    // output
    cout << regionCount1 << " " << regionCount2 << '\n';
}
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 101;

int m, n, h;
int totalTomato = 0;
int tomato[MAX][MAX][MAX];
int moveZ[] = { 0, 0, 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0, 0, 0 };
int moveX[] = { 0, 0, 1, -1, 0, 0 };

queue<pair<int, pair<int, int>>> q;

bool IsOut(int z, int y, int x){
    if(z < 0 || y < 0 || x < 0 || z >= h || y >= n || x >= m)
        return true;
    return false;
}
int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> m >> n >> h;
    for(int z = 0; z < h; z++){
        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                int input;
                cin >> input;
                tomato[z][y][x] = input;

                if(input == -1)    continue;

                if(input == 1){
                    q.push({z, {y, x}});
                }
                if(input == 0){
                    totalTomato++;
                }
            }
        }
    }

    if(totalTomato == 0){
        cout << "0\n";
        return 0;
    }

    //
    int makeCount = 0;
    int dayCount = 0;
    while (!q.empty()){
        int curDay = q.size();

        for(int day = 0; day < curDay; day++){
            int curZ = q.front().first;
            int curY = q.front().second.first;
            int curX = q.front().second.second;
            q.pop();

            for(int i = 0; i < 6; i++){
                int nextZ = curZ + moveZ[i];
                int nextY = curY + moveY[i];
                int nextX = curX + moveX[i];

                if(IsOut(nextZ, nextY, nextX))  continue;
                if(tomato[nextZ][nextY][nextX] != 0)    continue;

                tomato[nextZ][nextY][nextX] = 1;
                q.push({nextZ, {nextY, nextX}});
                makeCount++;
            }
        }
        dayCount++;
    }

    if(makeCount == totalTomato)
        cout << dayCount-1 << '\n';
    else 
        cout << "-1\n";

    return 0;
}
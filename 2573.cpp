#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 301;
int ice[MAX][MAX];
int aftermelt[MAX][MAX];
bool visit[MAX][MAX];
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };

int n, m;

bool IsOut(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= m);
}

bool AllMelted(){
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(ice[y][x] > 0)   return false;
        }
    }
    return true;
}

void SearchByBFS(int startY, int startX){
    queue<pair<int, int>> q;
    q.push({startY, startX});
    visit[startY][startX] = true;

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];

            if(IsOut(nextY, nextX) || visit[nextY][nextX] || ice[nextY][nextX] <= 0) continue;

            visit[nextY][nextX] = true;
            q.push({nextY, nextX});
        }
    }
    
}

bool IsTwo(){
    memset(visit, false, sizeof(visit));

    int searchCount = 0;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(ice[y][x] <= 0 || visit[y][x])   continue;
            SearchByBFS(y, x);
            searchCount++;
        }
    }

    return searchCount >= 2;
}

void Melt(){
    memset(aftermelt, 0, sizeof(aftermelt));

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(ice[y][x] <= 0)  continue;

            int count = 0;
            for(int i = 0; i < 4; i++){
                int nextX = x + moveX[i];
                int nextY = y + moveY[i];
                if(IsOut(nextY, nextX) || ice[nextY][nextX] > 0)    continue;
                
                count++;
            }
            aftermelt[y][x] = ice[y][x] - count;
        }
    } 

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            ice[y][x] = aftermelt[y][x];
        }
    }  
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            cin >> ice[y][x];
        }
    }

    int year = 0;
    while(true){
        if(AllMelted()){
            cout << "0\n";
            return 0;
        }

        if(IsTwo()){
            cout << year << '\n';
            return 0;
        }

        year++;
        Melt();
    }
}
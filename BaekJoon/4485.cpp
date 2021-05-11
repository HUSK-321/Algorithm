#include <iostream>
#include <queue>
using namespace std;

int curX, curY, curRupee, nextX, nextY, nextRupee, n, num = 1;
int map[126][126];
int ans[126][126];
int goX[4] = { 0, 0, 1, -1 };
int goY[4] = { 1, -1, 0, 0 };
priority_queue<pair<int, pair<int, int>>> q;

int main(){
    while(true){
        cin >> n;
        if(n == 0)
            return 0;
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                ans[i][j] = -1;
            
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> map[i][j];
        
        ans[1][1] = map[1][1];
        q.push(make_pair(-map[1][1], make_pair(1, 1)));

        while(!q.empty()){
            curX = q.top().second.first;
            curY = q.top().second.second;
            curRupee = -q.top().first;

            q.pop();

            if(ans[curX][curY] < curRupee)
                continue;
            
            for(int i = 0; i < 4; i++){
                nextX = curX + goX[i];
                nextY = curY + goY[i];
                nextRupee = curRupee + map[nextX][nextY];

                if(nextX < 1 || nextX > n || nextY < 1 || nextY > n)
                    continue;

                if(ans[nextX][nextY] == -1){ // 첫 방문
                    ans[nextX][nextY] = nextRupee;
                    q.push(make_pair(-nextRupee, make_pair(nextX, nextY)));
                }
                else if(ans[nextX][nextY] > nextRupee){ // 최소값으로
                    ans[nextX][nextY] = nextRupee;
                    q.push(make_pair(-nextRupee, make_pair(nextX, nextY)));
                }

            }
        }
        cout << "Problem "<< num << ": " << ans[n][n] << '\n';
        num++;
    }
}
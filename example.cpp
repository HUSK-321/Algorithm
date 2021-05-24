#include<iostream>
#include<queue>
 
#define endl "\n"
#define MAX 1000
using namespace std;
 
int R, C;
char MAP[MAX][MAX];
int Fire_MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
pair<int, int> Start, Fire;
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
queue<pair<int, int>> Fire_Q;
 
void Input()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            bool Fire = false;
            cin >> MAP[i][j];
            if (MAP[i][j] == 'J')
            {
                Start.first = i;
                Start.second = j;
            }
            else if (MAP[i][j] == 'F')
            {
                Fire_Q.push(make_pair(i, j));
                Fire_MAP[i][j] = 0;
                Fire = true;
            }
            if(Fire == false) Fire_MAP[i][j] = 987654321;
        }
    }
}
 
void Make_Fire_Map()
{
    while (Fire_Q.empty() == 0)
    {
        int Qs = Fire_Q.size();
        for (int s = 0; s < Qs; s++)
        {
            int x = Fire_Q.front().first;
            int y = Fire_Q.front().second;
            Fire_Q.pop();
 
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
 
                if (nx >= 0 && ny >= 0 && nx < R && ny < C)
                {
                    if (MAP[nx][ny] != '#')
                    {
                        if (Fire_MAP[nx][ny] > Fire_MAP[x][y] + 1)
                        {
                            Fire_MAP[nx][ny] = Fire_MAP[x][y] + 1;
                            Fire_Q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }
}
 
int Move_Person(int a, int b)
{
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(a, b), 0));
    Visit[a][b] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second;
        Q.pop();
 
        if (x == 0 || y == 0 || x == R - 1 || y == C - 1) return Cnt + 1;
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < R && ny < C)
            {
                if (MAP[nx][ny] != '#' && Visit[nx][ny] == false)
                {
                    if (Fire_MAP[nx][ny] > Cnt + 1)
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
                    }
                }
            }
        }
    }
    return -1;
}
 
void Solution()
{
    Make_Fire_Map();
    int R = Move_Person(Start.first, Start.second);
    if (R == -1) cout << "IMPOSSIBLE" << endl;
    else cout << R << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}

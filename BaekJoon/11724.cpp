#include <iostream>
using namespace std;

bool visit[1001];
bool arr[1001][1001];
int n, m;
// dfs에서 하는 일
// 첫 시작점 input을 시작으로 다음 간선을 탐색
// 다음 간선과 연결이 되어있고 아직 방문하지 않았다면 재귀로 dfs호출
void dfs(int input){
    visit[input] = true;
    
    for(int i = 1; i <= n; i++){
        if(!visit[i] && arr[input][i])
            dfs(i);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    // 0 인 정점은 없다
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        arr[x][y] = true; arr[y][x] = true;
    }

    int count = 0;
    for(int i = 1; i <= n; i++){
        if(visit[i] == false){
            count++;
            dfs(i);
        }
    }
    cout << count << '\n';
}
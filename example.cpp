#include <iostream>
#include <queue>
#include <vector>
#define max 100001
using namespace std;
bool visit[max];
int history[max];
vector<int> result;

int bfs(int n, int k){
    queue<pair<int, int> > q;
    q.push(make_pair(n, 0));
    visit[n] = true;

    while(!q.empty()){
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();

        if(cur == n){    // 완료조건
            int temp = cur;
            while(temp != n){
                result.push_back(temp);
                temp = history[temp];
            }
            return count;
        }
        // 탐색
        if(cur+1 < max && !visit[cur+1]){
            q.push(make_pair(cur+1, count+1));
            visit[cur+1] = true;
            history[cur+1] = cur;
        }
        if(cur-1 < max && !visit[cur-1]){
            q.push(make_pair(cur-1, count+1));
            visit[cur-1] = true;
            history[cur-1] = cur;
        }
        if(cur*2 < max && !visit[cur*2]){
            q.push(make_pair(cur*2, count+1));
            visit[cur*2] = true;
            history[cur*2] = cur;
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << '\n';
    for(int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << " ";
    cout << n << '\n';
}
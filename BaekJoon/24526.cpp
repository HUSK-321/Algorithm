#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int from, to;
int inCome[100001];
vector<int> call[100001];

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        
        inCome[from]++;
        call[to].push_back(from);
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!inCome[i])
            q.push(i);
    }

    int answer = q.size();
    while (!q.empty()){
        int student = q.front();
        q.pop();

        for(auto i : call[student]){
            if(!--inCome[i]){
                q.push(i);
                answer++;
            }
        }
    }
    
    cout << answer << '\n';
}
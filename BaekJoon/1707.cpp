#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> arr[20001];
int node[20001];

void dfs(int nodeIndex, int color){
    node[nodeIndex] = color;      // 먼저 색을 지정
    for(int i = 0; i < arr[nodeIndex].size(); i++){
        // 이 점과 연결되어있는 점들을 전부 탐색
        if(!node[arr[nodeIndex][i]])
            dfs(arr[nodeIndex][i], 3-color);    // 3-color : 지금 1이면 다음은 2, 지금 2면 다음은 1로 번갈아가기
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int k, v, e;    // k : 테스트케이스, v : 정점의 수, e : 선의 수
    cin >> k;
    while(k--){
        memset(node, 0, sizeof(node));
        cin >> v >> e;

        for(int i = 1; i <= v; i++){
            arr[i].clear();
        }

        for(int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        for(int i = 1; i <= v; i++){
            if(!node[i])
                dfs(i, 1);
        }

        bool answer = true;
        for(int i = 1; i <= v; i++){
            for(int j = 0; j < arr[i].size(); j++){
                if(node[i] == node[arr[i][j]])
                    answer = false;
            }
        }

        if(answer)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    
}
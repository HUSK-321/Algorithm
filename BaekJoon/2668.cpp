#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, answer = 0;
int visit[101];
int nums[101];
vector<int> ans;


void HaveCycle(int start, int cur){
    if(visit[cur]){
        if(start == cur)
            ans.push_back(start);
    }
    else {
        visit[cur] = true;
        HaveCycle(start, nums[cur]);
    }
}

int main(){

    // inputs
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> nums[i];
    
    // DFS
    for(int i = 1; i <= n; i++){
        HaveCycle(i, i);
        memset(visit, 0, sizeof(visit));
    }

    // Answer
    answer = ans.size();

    cout << answer << '\n';
    for(int i = 0; i < answer; i++){
        cout << ans[i] << '\n';
    }

}
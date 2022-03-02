#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool visit[9];
int maxCount = -1;
void dfs(int count, int leftFatigue, const vector<vector<int>>& dun){
    for(int i = 0; i < dun.size(); i++){
        if(!visit[i] && leftFatigue >= dun[i][0]){
            visit[i] = true;
            dfs(count+1, leftFatigue-dun[i][1], dun);
            visit[i] = false;
        }
    }
    maxCount = max(count, maxCount);
    return ;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    dfs(0, k, dungeons);
    answer = maxCount;
    return answer;
}
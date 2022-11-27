#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
    int answer = distance;
    
    for(int i = 0; i < scope.size(); i++){
        int fromDist = min(scope[i][0], scope[i][1]);
        int toDist = max(scope[i][0], scope[i][1]);
        
        int workTime = times[i][0];
        int restTime = times[i][1];
        
        for(int pos = fromDist; pos <= toDist; pos++){
            if(pos % (workTime + restTime) == 0){
                continue;
            }
            if(pos % (workTime + restTime) <= workTime){
                answer = min(answer, pos);
            }
        }        
    }
        
    return answer;
}
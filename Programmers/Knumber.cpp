#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++){
        vector<int> thiscase;
        
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++){
            thiscase.push_back(array[j]);
        }
        
        sort(thiscase.begin(), thiscase.end());
        
        int kNum = commands[i][2] - 1;
        
        answer.push_back(thiscase[kNum]);
    }
    
    
    return answer;
}
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, int> skillPriority;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i = 0; i < skill.size(); i++){
        skillPriority.insert({skill[i], i});
    }
    
    for(auto curSkill : skill_trees){
        int curLv = 0;
        bool isPossible = true;
        
        for(int i = 0; i < curSkill.size(); i++){
            if(skillPriority.find(curSkill[i]) == skillPriority.end())  continue;
            if(skillPriority[curSkill[i]] > curLv){
                isPossible = false;
                break;
            }
            curLv++;
        }
        if(isPossible)
            answer++;
    }
    
    
    return answer;
}
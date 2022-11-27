#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> visit;

bool DFS(const vector<vector<string>>& tickets, vector<string>& answer, string curCity, int visitCount){
    
    answer.push_back(curCity);
    if(visitCount == tickets.size())    return true;
    
    for(int i = 0; i < tickets.size(); i++){
        if(tickets[i][0] != curCity || visit[i])    continue;
        
        visit[i] = true;
        auto success = DFS(tickets, answer, tickets[i][1], visitCount+1);
        if(success) return true;
        visit[i] = false;
    }
    answer.pop_back();
    return false;
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    visit.resize(tickets.size());
    sort(tickets.begin(), tickets.end());
    DFS(tickets, answer, "ICN", 0);
    
    return answer;
}
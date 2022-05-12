#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size(), 0);

    unordered_map<string, int> userIndex;
    unordered_map<string, set<string>> reportList;

    for(int i = 0; i < id_list.size(); i++)
        userIndex[id_list[i]] = i;
    
    for(auto reportInfo : report){
        stringstream ss(reportInfo);
        string id, target;

        ss >> id >> target;

        reportList[target].insert(id);
    }

    for(auto reportResult : reportList){
        if(reportResult.second.size() < k)  continue;

        for(auto receiveUser : reportResult.second){
            answer[userIndex[receiveUser]]++;
        }
    }

    return answer;
}
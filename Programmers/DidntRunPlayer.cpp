#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string, int> players;

    for(int i = 0; i < participant.size(); i++){
        players[participant[i]]++;
    }
    for(int i = 0; i < completion.size(); i++){
        players[completion[i]]--;
    }

    for(const auto &player : players){
        if(player.second > 0){
            answer = player.first;
            break;
        }
    }
    


    return answer;
}
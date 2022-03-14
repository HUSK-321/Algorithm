#include <string>
#include <vector>

using namespace std;

const string k = "Kim";
string solution(vector<string> seoul) {
    string answer = "";

    for(int i = 0; i < seoul.size(); i++){
        if(seoul[i] == k){
            answer += "김서방은 " + to_string(i) + "에 있다";
        }
    }
    return answer;
}
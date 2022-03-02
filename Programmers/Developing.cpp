#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    // make input
    for(int i = 0; i < progresses.size(); i++){
        int developSpeed = speeds[i];
        int leftDevelop = MAX - progresses[i];
        int days = leftDevelop / developSpeed;
        if(leftDevelop % developSpeed > 0)  days++;

        q.push(days);
    }

    // sort
    while (!q.empty()){
        int curLeftDays = q.front();    q.pop();
        int developed = 1;

        while ((!q.empty()) && q.front() <= curLeftDays){
            q.pop();
            developed++;
        }
        answer.push_back(developed);
    }

    return answer;
}
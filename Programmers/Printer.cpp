#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;  // priority, index

    for(int i = 0; i < priorities.size(); i++){
        pq.push(priorities[i]);
        q.push(make_pair(priorities[i], i));
    }

    while(!q.empty()){
        int curPirority = q.front().first;
        int curIndex = q.front().second;
        q.pop();

        if(curPirority == pq.top()){
            pq.pop();
            answer++;

            if(curIndex == location)
                break;
        }
        else{
            q.push(make_pair(curPirority, curIndex));
        }
    }

    return answer;
}
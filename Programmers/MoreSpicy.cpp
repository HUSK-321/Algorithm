#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int count = 0;

    // make input
    priority_queue<int> q;
    for(int i = 0; i < scoville.size(); i++)
        q.push(-scoville[i]);
    
    while(q.size() >= 2){
        int first = -q.top();   q.pop();

        if(first >= K)
            return count;

        int second = -q.top();  q.pop();
        int newScov = first + (second * 2);
        count++; 

        q.push(-newScov);
    }
    
    if(-q.top() >= K)
        return count;
    return -1;
}

// 16m - 95.2
// 17m 30s
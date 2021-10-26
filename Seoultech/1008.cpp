#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, s, e;
int answer;
vector<pair<int, int>> tasks;
priority_queue<int> endtime;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s >> e;
        tasks.push_back(make_pair(s, e));
    }

    sort(tasks.begin(), tasks.end());

    endtime.push(-tasks[0].second);
    answer = 1;

    for(int i = 1; i < n; i++){

/*
<경우의 수>
- 작업중인 기계가
    - 없다
        1. 일 할당
    - 있다
        - 돌아가는 일을 뺄 수 있다 > 2. 일을 빼고 새 일을 넣는다
        - 돌아가는 일을 뺄 수 없다 > 3. 새 기계를 할당한다 (++)
*/
        // 1
        if(endtime.empty()){
            endtime.push(-tasks[i].second);
        }
        // 2
        if(-endtime.top() <= tasks[i].first){
            endtime.pop();
            endtime.push(-tasks[i].second);
            continue;
        }
        // 3
        if(-endtime.top() > tasks[i].first){
            endtime.push(-tasks[i].second);
            answer++;
        }
    }
    
    cout << answer << '\n';
}
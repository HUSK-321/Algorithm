#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, s, t;
// 시작시간, 종료시간
priority_queue<int> classQ;
vector<pair<int, int>> class_time;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // input
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s >> t;
        class_time.push_back(make_pair(s, t));
    }

    sort(class_time.begin(), class_time.end());

    // 강의실 찾기
    /*
    1. 강의실이 다 비어있는 경우
    2. 강의실이 일부만 사용되는 경우 (큐에서 전부 차있는 경우)
    3. 강의실이 전부 찬 경우 
    */
    for(int i = 0; i < n; i++){

        if(classQ.empty()) {
            classQ.push(-class_time[i].second);
        }
        else {
            if(-classQ.top() <= class_time[i].first){
                classQ.pop();
                classQ.push(-class_time[i].second);
            } 
            else {
                classQ.push(-class_time[i].second);
            }
            
        }
    }

    cout << classQ.size() << '\n';
}
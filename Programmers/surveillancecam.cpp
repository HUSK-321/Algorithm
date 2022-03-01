#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
다음 차가
- 끝나는 부분 후에 있다면
- 겹친다면
- 포함된다면

*/
int solution(vector<vector<int>> routes) {
    int answer = 1;

    // sort
    sort(routes.begin(), routes.end());

    // solve
    int prev = routes[0][1];
    for(unsigned i = 1; i < routes.size(); i++){
        if(prev < routes[i][0]){
            prev = routes[i][1];
            answer++;
        }
        if(prev > routes[i][1])
            prev = routes[i][1];
    }

    return answer;
}
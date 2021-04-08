#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, count = 0;
    sort(people.begin(), people.end());
    // people.size() > count
    // count가 가벼운 사람들 중 탄 사람 수인데 size==count가 된다면
    // 사람들이 이미 다 탔다는 이야기가 된다.
    while(people.size() > count){
        int big = people.back();
        people.pop_back();
        // 제일 몸무게가 큰 사람이랑 작은 사람이 탈 수 있다면
        if(people[count] + big <= limit){
            count++; // 다음 사람이 대기
            answer++;
        } else
            answer++;
    }
    
    return answer;
}
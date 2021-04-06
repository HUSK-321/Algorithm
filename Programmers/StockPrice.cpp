#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    int temp;
    stack<int> s;
    vector<int> answer(n);
    
    for(int i = 0; i < n; i++){
        while(!s.empty() && prices[s.top()] > prices[i]){   // 가격이 떨어진 경우
            // s.top()의 인덱스와 현재 인덱스 i를 비교해야 한다
            int top = s.top();
            s.pop();
            answer[top] = i - top;
        }
        s.push(i);
    }
    while(!s.empty()){
        int top = s.top();
        s.pop();
        answer[top] = n - top - 1;
    }
    
    return answer;
}
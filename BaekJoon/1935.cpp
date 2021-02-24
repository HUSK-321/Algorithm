#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, num[27];
    string input;
    stack<double> sta;
    // 입력
    cin >> n;
    cin >> input;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    // 스택
    // ex) ABC*+DE/-
    for(int i = 0; i < input.size(); i++){
        if(input[i] >= 'A' && input[i] <= 'Z')
            sta.push(num[input[i] - 'A']);
        else {
            // 스택 위 2개를 빼고 계산하면 된다.
            double top1 = sta.top();
            sta.pop();
            double top2 = sta.top();
            sta.pop();
            // top1이 식에서 더 오른쪽에 있다
            if(input[i] == '*')
                sta.push(top1*top2);
            else if(input[i] == '/')
                sta.push(top2/top1);
            else if(input[i] == '+')
                sta.push(top1+top2);
            else if(input[i] == '-')
                sta.push(top2-top1);
        }
    }
    printf("%.2f", sta.top());
}
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int n, k;
string str;
stack<char> s;

int main(){
    cin >> n >> k;
    cin >> str;

    for(int i = 0; i < str.size(); i++){
        while(!s.empty() && s.top() < str[i] && k > 0){
            s.pop();
            k--;
        }
        s.push(str[i]);
    }

    if(k > 0)
        while(k--)
            s.pop();
    
    // 뒤집기용 스택
    stack<char> res;
    while(!s.empty()){
        res.push(s.top());
        s.pop();
    }

    while(!res.empty()){
        cout << res.top();
        res.pop();
    }
    return 0;
}
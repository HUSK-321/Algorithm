#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string s, result;
    stack<char> sta;
    cin >> s;

    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            result += s[i];
        
        else{
            if(s[i] == '(')
                sta.push(s[i]);
            else if(s[i] == ')'){
                while(!sta.empty() && sta.top() != '('){    // () 만나게 해줌
                    result += sta.top();
                    sta.pop();
                }
                sta.pop();
            }
            else if(s[i] == '*' || s[i] == '/'){
                while(!sta.empty() && (sta.top() == '*' || sta.top() == '/')){
                    result += sta.top();
                    sta.pop();
                }
                sta.push(s[i]);
            }
            else{
                while(!sta.empty() && sta.top() != '('){
                    result += sta.top();
                    sta.pop();
                }
                sta.push(s[i]);
            }
        }
    }

    while(!sta.empty()){
        result += sta.top();
        sta.pop();
    }

    cout << result << '\n';
    
}
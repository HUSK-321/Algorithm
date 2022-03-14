#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";

    int length = n;
    while (n >= 2){
        answer += "수박";
        n -= 2;
    }
    // 수, 수박, 수박수, 수박수박, 수박수박수 
    if(n > 0)
        answer += "수";
    

    return answer;
}

int main(){
    cout << solution(1);
}
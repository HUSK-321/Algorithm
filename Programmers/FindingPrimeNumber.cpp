#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Era(int end){
    if(end < 2)
        return false;
    
    for(int i = 2; i * i <= end; i++){
        if(end % i == 0)
            return false;
    }
    
    return true;
}


int solution(string numbers) {
    int answer = 0;

    // 문자열로 되어 있는 숫자를 넣어야 한다
    vector<int> num;
    vector<char> numStr;
    int length = numbers.size();
    
    for(int i = 0; i < length; i++){
        numStr.push_back(numbers[i]);
    }
    
    sort(numStr.begin(), numStr.end());
    
    do{
        string s = "";
        for(int i = 0; i < length; i++){
            s.push_back(numStr[i]);
            num.push_back(stoi(s));
        }
    } while(next_permutation(numStr.begin(), numStr.end()));
    
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    
    for(int i = 0; i < num.size(); i++){
        if(Era(num[i]))
            answer++;
    }
    
    


    return answer;
}
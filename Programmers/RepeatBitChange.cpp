#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    
    int eraseCount = 0;
    int transformCount = 0;
    size_t pos;
    
    while(s != "1"){
        while((pos = s.find("0")) != string::npos){
            s.erase(pos, 1);
            eraseCount++;
        }
        
        string nextString = "";
        int num = s.size();
        while(num > 1){
            nextString += to_string(num % 2);
            num /= 2;
        }
        nextString += to_string(num % 2);
        s = nextString;
        transformCount++;
    }
    
    answer[0] = transformCount;
    answer[1] = eraseCount;
    
    return answer;
}
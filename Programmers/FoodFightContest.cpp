#include <string>
#include <vector>

using namespace std;

int number[10];

string solution(vector<int> food) {
    string answer = "";
    
    for(int i = 1; i < food.size(); i++){
        number[i] = food[i];
    }
    
    for(int i = 1; i < food.size(); i++){
        for(int count = 0; count < number[i] / 2; count++){
            answer += to_string(i);
        }
    }
    answer += "0";
    for(int i = food.size(); i >= 1; i--){
        for(int count = 0; count < number[i] / 2; count++){
            answer += to_string(i);
        }
    }
    
    
    return answer;
}
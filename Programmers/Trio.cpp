#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    for(int first = 0; first < number.size()-2; first++){
        for(int second = first+1; second < number.size()-1; second++){
            for(int third = second+1; third < number.size(); third++){
                if(number[first] + number[second] + number[third] == 0)
                    answer++;
            }
        }
    } 
    
    return answer;
}
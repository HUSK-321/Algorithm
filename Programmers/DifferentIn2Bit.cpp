#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer(numbers.size());
    
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] % 2 == 0){
            answer[i] = numbers[i] + 1;
            continue;
        }
        long long temp = 1;
        while(true){
            if((temp & numbers[i]) == 0)  break;
            temp *= 2;
        }
        temp /= 2;
        answer[i] = numbers[i] + temp;
    }
    
    return answer;
}
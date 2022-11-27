#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i = left; i <= right; i++){
        long long biggerNum = max(static_cast<long long>(i/n), static_cast<long long>(i%n));
        answer.push_back(biggerNum + 1);
    }
    
    return answer;
}
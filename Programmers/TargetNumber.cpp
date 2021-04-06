#include <string>
#include <vector>

using namespace std;
int answer = 0;
void dfs(vector<int> numbers, int target, int i, int sum){
    int n = numbers.size();
    
    if(i >= n){
        if(sum == target)
            answer++;
        return;
    }
    // 0부터 시작을 했으니
    dfs(numbers, target, i+1, sum+numbers[i]);
    dfs(numbers, target, i+1, sum-numbers[i]);
    
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}
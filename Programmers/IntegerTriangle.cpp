#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[501][501];

// 다음 외부 벡터에서 오른쪽 왼쪽 위치를 골라야 한다
// 인덱스가 같은게 왼쪽 1큰게 오른똑이다
// arr을 통해 dp

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    
    // 꼭짓점 값
    answer = arr[0][0] = triangle[0][0];
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){
                arr[i][j] = arr[i-1][j] + triangle[i][j];
            }
            else if(j == i){
                arr[i][j] = arr[i-1][j-1] + triangle[i][j];
            }
            else {
                arr[i][j] = max(arr[i-1][j], arr[i-1][j-1]) + triangle[i][j];
            }
            
            answer = max(answer, arr[i][j]);
        }
    }
    return answer;
}
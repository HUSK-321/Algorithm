#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> board)
{
    int answer = board[0][0];

    for(int i = 1; i < board.size(); i++){
        for(int j = 1; j < board[i].size(); j++){
            if(board[i][j]){
                board[i][j] = min(board[i-1][j-1], min(board[i-1][j], board[i][j-1]));
                board[i][j]++;
                answer = max(board[i][j], answer);
            }
        }
    }
    answer *= answer;
    return answer;
}
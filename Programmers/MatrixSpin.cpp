#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int matrix[101][101];

int SpinMatrix(pair<int, int> leftUp, pair<int, int> rightDown){
    int minResult = 10000;
    int temp = matrix[leftUp.first][leftUp.second];
    minResult = min(temp, minResult);

    int vertical = rightDown.first - leftUp.first;
    int horizontal = rightDown.second - leftUp.second;

    int x = leftUp.second;
    for(int i = leftUp.first; i < leftUp.first + vertical; i++){
        matrix[i][x] = matrix[i+1][x];
        minResult = min(minResult, matrix[i][x]);
    }

    int y = rightDown.first;
    for(int i = leftUp.second; i < leftUp.second + horizontal; i++){
        matrix[y][i] = matrix[y][i+1];
        minResult = min(minResult, matrix[y][i]);
    }

    x = rightDown.second;
    for(int i = rightDown.first; i > rightDown.first - vertical; i--){
        matrix[i][x] = matrix[i-1][x];
        minResult = min(minResult, matrix[i][x]);
    }

    y = leftUp.first;
    for(int i = rightDown.second; i > rightDown.second - horizontal; i--){
        matrix[y][i] = matrix[y][i-1];
        minResult = min(minResult, matrix[y][i]);
    }

    matrix[leftUp.first][leftUp.second+1] = temp;

    return minResult;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    // make Matrix
    for(int i = 1; i <= rows; i++)
        for(int j = 1; j <= columns; j++)
            matrix[i][j] = (i-1)*columns + j;
        
    // spin
    for(int i = 0; i < queries.size(); i++){
        pair<int, int> leftUp = {queries[i][0], queries[i][1]};
        pair<int, int> rightDown = {queries[i][2], queries[i][3]};

        answer.push_back(SpinMatrix(leftUp, rightDown));
    }

    return answer;
}
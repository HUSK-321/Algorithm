#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int matrix[101][101];

// 2 2 5 4
int SpinMatrix(pair<int, int> leftUp, pair<int, int> rightDown){
    int minResult = 10000;
    int temp = matrix[leftUp.first][leftUp.second];
    minResult = min(temp, minResult);

    int vertical = rightDown.first - leftUp.first;  // 3
    int horizontal = rightDown.second - leftUp.second; // 2

    int x = leftUp.second;
    // 2 ~ 4
    for(int i = leftUp.first; i < leftUp.first + vertical; i++){
        matrix[i][x] = matrix[i+1][x];
        minResult = min(minResult, matrix[i][x]);
        /*
        20
        26
        27
        ?(27)
        */
    }

    int y = rightDown.first;
    // 2~3
    for(int i = leftUp.second; i < leftUp.second + horizontal; i++){
        matrix[y][i] = matrix[y][i+1];
        minResult = min(minResult, matrix[y][i]);
        /*
        20 ?  ?
        26    ?
        27    ?
        28 22 ?(22)
        */
    }

    x = rightDown.second;
    // y : 2~5
    for(int i = rightDown.first; i > rightDown.first - vertical; i--){
        matrix[i][x] = matrix[i-1][x];
        minResult = min(minResult, matrix[i][x]);
        /*
        20 ?  ?(9)
        26    9
        27    10
        28 22 16
        */
    }

    y = leftUp.first;
    // 2 ~4
    for(int i = rightDown.second; i > rightDown.second - horizontal; i--){
        matrix[y][i] = matrix[y][i-1];
        minResult = min(minResult, matrix[y][i]);
        /*
        20 20*  8
        26      9
        27      10
        28 22   16
        */
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
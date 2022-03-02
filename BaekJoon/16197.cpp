#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int boardH, boardW;
char board[21][21];
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};
vector<pair<int, int>> coinPos;  // height, weight
int answer = 20;

bool isCoinOut(const pair<int, int>& coin){
    if(coin.first < 0 || coin.second < 0 || coin.first >= boardH || coin.second >= boardW)
        return true;
    
    return false;
}

bool isWallStuck(const pair<int, int>& coin){
    if(board[coin.first][coin.second] == '#')
        return true;

    return false;
}

void moveCoin(pair<int, int> coin1, pair<int, int> coin2, int moveCount, int direction){
    // not answer
    if(moveCount > 10)  return;
    if(answer < moveCount)  return;

    // Next Position
    pair<int, int> coin1Next = make_pair(coin1.first + moveY[direction], coin1.second + moveX[direction]);
    pair<int, int> coin2Next = make_pair(coin2.first + moveY[direction], coin2.second + moveX[direction]);

    bool is1Stuck = isWallStuck(coin1Next);
    bool is2Stuck = isWallStuck(coin2Next);
    bool is1Out = isCoinOut(coin1Next);
    bool is2Out = isCoinOut(coin2Next);

    // stuck can't move
    if(is1Stuck)    coin1Next = coin1;
    if(is2Stuck)    coin2Next = coin2;

    // not answer
    if(is1Out && is2Out)    return;
    if(is1Stuck && is2Stuck)    return;

    // only one coin out
    if(is1Out ^ is2Out){
        answer = min(answer, moveCount);
        return;
    }

    // no return -> move next
    for(unsigned dir = 0; dir < 4; dir++)
        moveCoin(coin1Next, coin2Next, moveCount+1, dir);
}


int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> boardH >> boardW;

    for(unsigned h = 0; h < boardH; h++){
        for(unsigned w = 0; w < boardW; w++){
            char input;
            cin >> input;

            if(input == 'o')
                coinPos.push_back(make_pair(h, w));
            
            board[h][w] = input;
        }
    }

    // solve
    for(unsigned dir = 0; dir < 4; dir++)
        moveCoin(coinPos[0], coinPos[1], 1, dir);

    // output
    if(answer > 10)
        cout << "-1\n";
    else
        cout << answer << '\n';

    return 0;
}
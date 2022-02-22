#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int totalTime, totalMove;
int plumCount[3][1001][31]; // location, time, movecount
int whichTree[1001];
int maxPlum = -1;

int movingPlum(int moveCount, int time, int curTree){
    if(time == totalTime)   return 0;

    if(plumCount[curTree][time][moveCount] != -1)
        return plumCount[curTree][time][moveCount];
    
    if(curTree == whichTree[time]){
        if(moveCount < totalMove)
            return plumCount[curTree][time][moveCount] = max(1+movingPlum(moveCount, time+1, curTree), movingPlum(moveCount+1, time+1, 3-curTree));
        else
            return plumCount[curTree][time][moveCount] = 1 + movingPlum(moveCount, time+1, curTree);
    }
    else {
        if(moveCount < totalMove)
            return plumCount[curTree][time][moveCount] = max(movingPlum(moveCount, time+1, curTree), 1+movingPlum(moveCount+1, time+1, 3-curTree));
        else 
            return plumCount[curTree][time][moveCount] = movingPlum(moveCount, time+1, curTree);
    }
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(plumCount, -1, sizeof(plumCount));

    // input
    cin >> totalTime >> totalMove;

    for(int t = 0; t < totalTime; t++)
        cin >> whichTree[t];
    
    // solve
    cout << movingPlum(0, 0, 1) << '\n';

    return 0;
    
}
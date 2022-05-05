#include <iostream>
#include <queue>

using namespace std;

int ladder, snake;
int nextMap[200];
bool visit[101];

void MakeRoute(){
    int from, to;
    cin >> from >> to;
    nextMap[from] = to;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i <= 100; i++){
        nextMap[i] = i;
    }

    // input
    cin >> ladder >> snake;
    while(ladder--){
        MakeRoute();
    }
    while(snake--){
        MakeRoute();
    }
    
    // solution
    queue<pair<int, int>> dice;  // pos, count
    dice.push({1, 0});
    visit[1] = true;

    while (!dice.empty()){
        int curPos = dice.front().first;
        int count = dice.front().second;
        dice.pop();

        if(curPos == 100){
            cout << count << '\n';
            return 0;
        }

        for(int i = 1; i <= 6; i++){
            int nextPos = curPos+i;
            if(nextPos > 100)   continue;
            nextPos = nextMap[curPos+i];

            if(visit[nextPos])  continue;

            visit[nextPos] = true;
            dice.push({nextPos, count+1});
        }
    }
    
    
}
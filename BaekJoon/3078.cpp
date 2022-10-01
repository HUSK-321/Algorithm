#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int numberofStudent, rankDifference;
vector<int> rankToLength;
deque<int> lengthToRank[21];

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input
    cin >> numberofStudent >> rankDifference;
    rankToLength.resize(numberofStudent);

    for(int i = 0; i < numberofStudent; i++){
        string studentName;
        cin >> studentName;
        rankToLength[i] = studentName.length();
    }

    // calculate
    long long answer = 0;
    for(int rank = 0; rank < numberofStudent; rank++){
        auto& curNameGroup = lengthToRank[rankToLength[rank]];
        curNameGroup.push_back(rank);

        if(curNameGroup.size() == 1)    continue;

        while (rank - curNameGroup.front() > rankDifference){
            curNameGroup.pop_front();
        }
        answer += curNameGroup.size() - 1;
    }

    cout << answer << '\n';
}
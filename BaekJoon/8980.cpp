#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e4+1;
int numOfTown, truckCapacity, sendingBox;
pair<pair<int, int>, int> sendInfo[MAX];
int capacityAt[MAX];

struct SendInfoCompare{
    using info = pair<pair<int, int>, int>;
    bool operator() (const info& a, const info& b){
        if(a.first.second < b.first.second)
            return true;
        if(a.first.second == b.first.second)
            if(a.first.first < b.first.first)
                return true;
        return false;
    }
};

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> numOfTown >> truckCapacity;
    cin >> sendingBox;
    for(int i = 0; i < sendingBox; i++){
        cin >> sendInfo[i].first.first >> sendInfo[i].first.second >> sendInfo[i].second;
    }

    // solve
    sort(sendInfo, sendInfo + sendingBox, SendInfoCompare());

    int answer = 0;
    for(int i = 0; i < sendingBox; i++){
        int boxCount = 0;

        for(int j = sendInfo[i].first.first; j < sendInfo[i].first.second; j++){
            boxCount = max(boxCount, capacityAt[j]);
        }
        int leftSpace = min(sendInfo[i].second, truckCapacity - boxCount);
        answer += leftSpace;
        for(int j = sendInfo[i].first.first; j < sendInfo[i].first.second; j++){
            capacityAt[j] += leftSpace;
        }
    }

    // print
    cout << answer << '\n';
}
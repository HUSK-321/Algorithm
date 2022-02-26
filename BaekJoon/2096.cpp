#include <iostream>
#include <algorithm>
using namespace std;

int n;
int map[100001][4];
int maxVal[3][4];
int minVal[3][4];

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> map[i][0] >> map[i][1] >> map[i][2];
    
    // solve
    maxVal[0][0] = minVal[0][0] = map[0][0];
    maxVal[0][1] = minVal[0][1] = map[0][1];
    maxVal[0][2] = minVal[0][2] = map[0][2];


    for(int i = 1; i < n; i++){
        int left = map[i][0];
        int mid = map[i][1];
        int right = map[i][2];

        maxVal[1][0] = left + max(maxVal[0][0], maxVal[0][1]);
        maxVal[1][1] = mid + max(maxVal[0][0], max(maxVal[0][1], maxVal[0][2]));
        maxVal[1][2] = right + max(maxVal[0][1], maxVal[0][2]);

        minVal[1][0] = left + min(minVal[0][0], minVal[0][1]);
        minVal[1][1] = mid + min(minVal[0][0], min(minVal[0][1], minVal[0][2]));
        minVal[1][2] = right + min(minVal[0][1], minVal[0][2]);

        maxVal[0][0] = maxVal[1][0];
        maxVal[0][1] = maxVal[1][1];
        maxVal[0][2] = maxVal[1][2];

        minVal[0][0] = minVal[1][0];
        minVal[0][1] = minVal[1][1];
        minVal[0][2] = minVal[1][2];

    }

    int totalMax = max(maxVal[0][0], max(maxVal[0][1], maxVal[0][2]));
    int totalMin = min(minVal[0][0], min(minVal[0][1], minVal[0][2]));
    cout << totalMax << " " << totalMin << '\n';
}
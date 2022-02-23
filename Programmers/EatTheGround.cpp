#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int totalSize = land.size()-1;
    for(unsigned i = 0; i < totalSize; i++){
        int land0 = land[i][0];
        int land1 = land[i][1];
        int land2 = land[i][2];
        int land3 = land[i][3];
        land[i+1][0] += max(land1, max(land2, land3));
        land[i+1][1] += max(land0, max(land2, land3));
        land[i+1][2] += max(land0, max(land1, land3));
        land[i+1][3] += max(land0, max(land1, land2));
    }

    answer = max(max(land[totalSize][0], land[totalSize][1]), max(land[totalSize][2], land[totalSize][3]));
    return answer;
}
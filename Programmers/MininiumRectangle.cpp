#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int longOfLongest = 0, shortOfLongest = 0;
    for(int i = 0; i < sizes.size(); i++){
        int longSide = max(sizes[i][0], sizes[i][1]);
        int shortSide = min(sizes[i][0], sizes[i][1]);
        
        longOfLongest = max(longOfLongest, longSide);
        shortOfLongest = max(shortOfLongest, shortSide);
    }
    
    
    return longOfLongest * shortOfLongest;
}
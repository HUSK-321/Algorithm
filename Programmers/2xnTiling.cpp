#include <string>
#include <vector>

using namespace std;
const int mod = 1000000007;
int solution(int n) {
    int answer = 0;

    vector<int> wayCount(n+1);
    wayCount[0] = 0;
    wayCount[1] = 1;
    wayCount[2] = 2;

    for(unsigned i = 3; i <= n; i++){
        wayCount[i] = (wayCount[i-1] + wayCount[i-2])%mod;
    }

    return answer = wayCount[n];
}
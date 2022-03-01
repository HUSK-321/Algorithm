#include <string>
#include <vector>

using namespace std;

int numbers[100001];
const int mod = 1234567;
int solution(int n) {
    int answer = 0;

    numbers[0] = 0;
    numbers[1] = 1;
    numbers[2] = 1;
    numbers[3] = 2;

    for(unsigned i = 4; i <= n; i++){
        numbers[i] = (numbers[i-1] + numbers[i-2]) % mod;
    }

    return answer = numbers[n];
}
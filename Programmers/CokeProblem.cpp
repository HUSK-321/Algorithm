#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(true){
        if(n < a)   break;
        int newBottle = (n/a) * b;
        answer += newBottle;
        n = n % a + newBottle;
    }
    
    return answer;
}
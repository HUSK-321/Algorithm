#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long num[10];

long long solution(long long n) {
    long long answer = 0;

    while(n > 0){
        num[n%10] += 1;
        n /= 10;
    }

    for(int i = 0; i < 10; i++)
        cout << num[i] << " ";
    cout << '\n';

    long long count = 1;
    for(long long i = 0; i <= 9; i++){
        for(int j = 0; j < num[i]; j++){
            answer += i * count;
            count *= 10;
        }
    }
    return answer;
}

int main(){
    cout << solution(8000000000) << endl;
}
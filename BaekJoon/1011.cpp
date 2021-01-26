#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long T;
    cin >> T;
    while(T--) {
        long long start, end, distance, etc, count = 1;      // start < end

        cin >> start >> end;

        distance = end - start;
        // count는 최대 워프 거리
        while(count * count <= distance){
            count++;
        }
        count--;

        etc = distance - (count*count);
        etc = (long long)ceil(((double)etc / (double)count));

        cout << (count * 2) -1 + etc << '\n';
    }
}
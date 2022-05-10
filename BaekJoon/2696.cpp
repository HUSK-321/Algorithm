#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, m;
long long input;

int main(){
    // init
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // input
    cin >> t;

    while (t--){

        priority_queue<long long> maxQ;
        priority_queue<long long> minQ;

        cin >> m;
        cout << (m/2) + 1 << '\n';

        // solve
        for(int i = 0; i < m; i++){
            cin >> input;

            if(maxQ.size() > minQ.size())
                minQ.push(-input);
            else
                maxQ.push(input);

            if(!maxQ.empty() && !minQ.empty()){
                if(maxQ.top() > -minQ.top()){
                    long long minValue = -minQ.top();
                    long long maxValue = maxQ.top();

                    minQ.pop();
                    maxQ.pop();

                    minQ.push(-maxValue);
                    maxQ.push(minValue);
                }
            }

            if(i % 2 == 0)
                cout << maxQ.top() << " ";
        }

        cout << '\n';
    }
}
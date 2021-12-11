#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int t, m, input;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;

    while (t--){

        priority_queue<int> maxQ;
        priority_queue<int> minQ;

        cin >> m;

        cout << (m/2) + 1 << '\n';

        for(int i = 0; i < m; i++){

            cin >> input;

            if(maxQ.size() > minQ.size())
                minQ.push(-input);
            else
                maxQ.push(input);

            if(!maxQ.empty() && !minQ.empty()){

                if(maxQ.top() > -minQ.top()){

                    int minValue = -minQ.top();
                    int maxValue = maxQ.top();

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
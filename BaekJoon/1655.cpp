#include <iostream>
#include <queue>
using namespace std;

int n, input;

// smallerQ.top() < biggerQ.top();
priority_queue<int> biggerQ;    // max-heap
priority_queue<int> smallerQ;   // min-heap

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        if(biggerQ.size() > smallerQ.size())
            smallerQ.push(-input);
        else 
            biggerQ.push(input);

        if(!biggerQ.empty() && !smallerQ.empty()){
            if(-smallerQ.top() < biggerQ.top()){
                int small = -smallerQ.top();
                int big = biggerQ.top();

                smallerQ.pop();
                biggerQ.pop();

                biggerQ.push(small);
                smallerQ.push(-big);
            }
        }


        // biggerQ >= smallerQ
        cout << biggerQ.top() << '\n';
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int jobs_can = 0;
pair<int, int> now_working = {-1, -1};

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    // finishtime, starttime
    vector<pair<int, int>> jobs_time(n);
    for(int i = 0; i < n; i++){
        cin >> jobs_time[i].second >> jobs_time[i].first;
    }

    // solve
    // pair<int, int> : first = end time, second = start time; 
    sort(jobs_time.begin(), jobs_time.end());
    for(int i = 0; i < jobs_time.size(); i++){
        if(now_working.first <= jobs_time[i].second){
            // can do another job
            now_working = jobs_time[i];
            jobs_can++;
        }
    }

    cout << jobs_can << '\n';
}
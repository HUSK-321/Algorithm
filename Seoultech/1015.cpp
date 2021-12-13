#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<int, int>> vertex;
vector<int> distances;
vector<bool> isCenter;
vector<int> centers_of_clusters_index;

int Distance(const pair<int, int>& A, const pair<int, int>& B){
    int distance = sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));

    return distance;
}

int Find_All_Distance(){
    for(int i = 0; i < n; i++){
        if(isCenter[i] == true){
            distances[i] = -1;
            continue;
        }

        int minnum = 210000000;
        for(int j = 0; j < centers_of_clusters_index.size(); j++){
            int center = centers_of_clusters_index[j];
            minnum = min(minnum, Distance(vertex[center], vertex[i]));
        }

        distances[i] = minnum;
    }
}

int Find_Index_Of_MaxDistance(){
    int max_distance = -1;
    int max_index = -1;

    // search min
    Find_All_Distance();

    for(int i = 0; i < n; i++){
        if(max_distance < distances[i])
        {
            max_distance = distances[i];
            max_index = i;
        }   
    }
    return max_index;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input;
    cin >> n >> k;

    vertex.resize(n);
    distances.resize(n);
    isCenter.resize(n);
    fill(isCenter.begin(), isCenter.end(), false);

    for(int i = 0; i < n; i++){
        cin >> vertex[i].first >> vertex[i].second;
    }

    // slove
    // 1. select random cluster's center
    centers_of_clusters_index.push_back(0);
    isCenter[0] = true;

    // 2. make cluster
    for(int i = 1; i < k; i++){
        int new_center_index = Find_Index_Of_MaxDistance();
        isCenter[new_center_index] = true;
        centers_of_clusters_index.push_back(new_center_index);
    }


    // print
    sort(centers_of_clusters_index.begin(), centers_of_clusters_index.end());

    for(int i = 0; i < centers_of_clusters_index.size(); i++){
        int index = centers_of_clusters_index[i];
        cout << vertex[index].first << " " << vertex[index].second << '\n';
    }
}
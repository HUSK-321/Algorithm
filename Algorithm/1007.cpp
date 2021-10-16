#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int parent[201];

struct EDGE
{
    int from;
    int to;
    int cost;

    bool operator < (const EDGE &e) const {
        return cost < e.cost;
    }

    bool operator > (const EDGE &e) const {
        return cost > e.cost;
    }
};

int FindParent(int x){
    if(x == parent[x])
        return x;
    return parent[x] = FindParent(parent[x]);
}

void Merge(int x, int y){
    x = FindParent(x);
    y = FindParent(y);

    if(x == y)
        return;
    
    parent[x] = y;
}

void Swap(EDGE *x, EDGE *y){
    EDGE temp = *x;
    *x = *y;
    *y = temp;
}

void Quick(vector<EDGE>& quick ,int i, int j)
{
	if(i>=j) return;
	int pivot = quick[(i+j)/2].cost;
	int left = i;
	int right = j;
	
	while(left<=right)
	{
		while(quick[left].cost < pivot) 
            left++;

		while(quick[right].cost > pivot)
            right--;

		if(left <= right)
		{
			Swap(&quick[left], &quick[right]);
			left++; right--;
		}
	}
	Quick(quick,i,right);
	Quick(quick,left,j);
}


int main(){
    cin >> n >> m;

    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
    vector<EDGE> edge(m);

    for(int i = 0; i < m; i++){
        cin >> edge[i].from >> edge[i].to >> edge[i].cost;
    }

    // sort
    Quick(edge, 0, m-1);
    // sort(edge.begin(), edge.end());

    int res = 0, count = 0;

    for(int i = 0; i < m; i++){
        if(FindParent(edge[i].from) == FindParent(edge[i].to))
            continue;
        
        Merge(edge[i].from, edge[i].to);
        res += edge[i].cost;
        count++;

        if(count == n - 1)
            break;

    }

    cout << res;
}
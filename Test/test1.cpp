#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define INF 987654321
int n;
long long node[501];
vector<tuple<int, int, int>> edge;

int Bellman(int start) {
	node[start] = 0;
	for (int i = 1; i < start; i++) {
		cout << edge.size() << '\t';
		for (int j = 0; j < edge.size(); j++) {
			int from, to, cost; 
			
			from = get<0>(edge[j]);
			to = get<1>(edge[j]);
			cost = get<2>(edge[j]);

			if (node[from] == INF)
				continue;
			if (node[to] > node[from] + cost)
				node[to] = node[from] + cost;
		}
	}

	for (int i = 0; i < edge.size(); i++) {
		int from, to, cost;
		from = get<0>(edge[i]);
		to = get<1>(edge[i]);
		cost = get<2>(edge[i]);

		if (node[to] == INF)
			continue;
		if (node[to] > node[from] + cost) {
			return INF;
		}
	}
	return 0;
}
int main(void) {
	cin >> n;
	for (int j = 0; j < n; j++) {
		fill(node, node + 501, INF);
        edge.clear();

		int a, b, c;
		cin >> a >> b >> c;
		for (int i = 0; i < b; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			edge.push_back(make_tuple(s, e, t));
			edge.push_back(make_tuple(e, s, t));
			//edge.push_back(make_tuple(a + 1, s, 0));
			//edge.push_back(make_tuple(a + 1, e, 0));
		}
		for (int i = 0; i < c; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			edge.push_back(make_tuple(s, e, -t));
		}

		if (Bellman(a + 1) == INF) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
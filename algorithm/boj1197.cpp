#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10001
using namespace std;
int V, E;
int graph[MAX];


int find(int x) {
	if (graph[x] == x)return x;
	return graph[x] = find(graph[x]);
}

void uni(int x, int y) {
	int u = find(x);
	int v = find(y);
	if (u < v)graph[v] = u;
	else graph[u] = v;
}

bool isCycle(int x, int y) {
	int u = find(x);
	int v = find(y);
	if (u == v)return true;
	return false;
}
class Node {
public:
	int node[2];
	int distance;
	Node(int x, int y, int dis) {
		this->node[0] = x;
		this->node[1] = y;
		this->distance = dis;
	};
	bool operator <(Node &node) {
		return this->distance < node.distance;
	}
};


void init() {
	for (int i = 0; i < MAX; i++)graph[i] = i;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;
	init();

	vector<Node>v;
	while (E--) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(Node(a, b, c));
	}

	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!isCycle(v[i].node[0], v[i].node[1])) {
			uni(v[i].node[0], v[i].node[1]);
			sum += v[i].distance;
		}
	}
	cout << sum << '\n';

}
#include<iostream>
#include<vector>
#define MAX 500000
using namespace std;

int parent[MAX];
vector<int>cycle;
int N, M;
bool isCycle = false;
int find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
	int u = find(x);
	int v = find(y);
	if (u != v) {
		if (u < v)swap(u, v);
		parent[u] = v;
	}
	else isCycle = true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < MAX; i++) {
		parent[i] = i;
	}

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int u, v;
		cin >> u >> v;
		uni(u, v);
		if (isCycle)cycle.push_back(i);
	}

	if (isCycle) { cout << cycle.front() << '\n'; return 0; }

	cout << 0 << '\n';
}
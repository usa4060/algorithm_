#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int set[8];

int find(int x) {
	if (set[x] == x)return x;
	return set[x] = find(set[x]);
}

void uni(int x, int y) {
	int u = find(x);
	int v = find(y);
	if (u > v)set[v] = u;
	else set[u] = v;
}


int checkParent(int x, int y) {
	int u = find(x);
	int v = find(y);
	if (u == v)return 1;
	return 0;
}

class Edge {
public:
	int node[2]; // u , v
	int dis; // u와 v사이의 거리
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->dis = distance;
	}
	bool operator <(Edge& edge) {
		return this->dis < edge.dis;
	}

};

int main() {
	vector<Edge>v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	sort(v.begin(), v.end());

	for (int i = 1; i <= 7; i++) {
		set[i] = i;
	}


	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!checkParent(v[i].node[0], v[i].node[1])) {
			sum += v[i].dis;
			uni(v[i].node[0], v[i].node[1]);
		}
	}

	cout << sum << '\n';
}
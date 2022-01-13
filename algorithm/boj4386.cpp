#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX 101
using namespace std;
int N;
int parent[MAX];


int find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
	int u = find(x);
	int v = find(y);
	if (u < v)parent[v] = u;
	else parent[u] = v;
}

bool isCycle(int x, int y) {
	int u = find(x);
	int v = find(y);
	if (u == v)return true;
	return false;
}


void init() {
	for (int i = 1; i < MAX; i++) {
		parent[i] = i;
	}
}
class Star{
public:
	int u,v;
	float dis;
	Star(int x, int y, float dis) {
		this->u = x;
		this->v = y;
		this->dis = dis;
	}

	bool operator <(Star &star) {
		return this->dis < star.dis;
	}
};

float distance(float x, float y) {
	return sqrt(x * x + y * y);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<Star>v;
	vector<pair<float, float>>st;
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		float x, y;
		cin >> x >> y;
		st.push_back(make_pair(x,y));
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			v.push_back(Star(i, j, distance((st[i].first - st[j].first), (st[i].second - st[j].second))));
		}
	}
	sort(v.begin(), v.end());
	float sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!isCycle(v[i].u, v[i].v)) {
			uni(v[i].u, v[i].v);
			sum += v[i].dis;
		}
	}
	cout.precision(3);
	cout << sum << '\n';
}
#include<iostream>
#define MAX 1001
using namespace std;
int T, N, M, a, b;

int nation[MAX];

int find(int x) {
	if (nation[x] == x)return x;
	return nation[x] = find(nation[x]);
}

void uni(int x, int y) {
	int u = find(x);
	int v = find(y);
	if (u < v)nation[v] = u;
	else nation[u] = v;
}

bool isCycle(int x, int y) {
	int u = find(x);
	int v = find(y);
	if (u == v)return true;
	return false;
}

void init() {
	for (int i = 0; i < MAX; i++) {
		nation[i] = i;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		init();
		cin >> N >> M;
		int cnt = 0;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			if (!isCycle(a, b)) {
				uni(a, b);
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
}

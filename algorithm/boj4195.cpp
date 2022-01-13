/*#include<iostream>
#include<map>
#define MAX 100001
using namespace std;
int T, F;
string name1, name2;
pair<int, string>person[MAX];
int friends[MAX];


int getFriend(pair<int, string>f[], int x) {
	if (f[x].first == x)return x;
	return f[x].first = getFriend(f, f[x].first);
}

void unionFriend(pair<int, string> f[], int x, int y) {
	int a = getFriend(f, x);
	int b = getFriend(f, y);
	if (a < b) {
		int temp = f[b].first;
		for (int i = 1; i < MAX; i++) {
			if (f[i].first == temp)f[i].first = a;
		}
	}
	else {
		int temp = f[a].first;
		for (int i = 1; i < MAX; i++) {
			if (f[i].first == temp)f[i].first = b;
		}
	}
}

int checkFriend(string name) {
	for (int i = 1; i < MAX; i++) {
		if (name == person[i].second)return i;
	}
	return 0;
}


void makeFriendPair() {
		cin >> name1 >> name2;
		for (int i = 1; i < MAX; i++) {
			if (person[i].second == " ") { person[i].second = name1; break; }
			else if (person[i].second == name1)break;
		}
		for (int i = 1; i < MAX; i++) {
			if (person[i].second == " ") { person[i].second = name2; break; }
			else if (person[i].second == name2)break;
		}
}

int makeFriendBound(int checkFriendShip) {
	int cnt = 0;
	for (int i = 1; i < MAX; i++) {
		if (person[i].first == checkFriendShip)cnt++;
	}
	return cnt;
}

void init() {
	for (int i = 1; i < MAX; i++) {
		person[i].first = i;
		person[i].second = " ";
		friends[i] = 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		init();
		cin >> F;
		for (int i = 0; i < F; i++) {
			makeFriendPair();
			int a = checkFriend(name1);
			int b = checkFriend(name2);
			unionFriend(person, a, b);
			cout << makeFriendBound(person[a].first) << '\n';
		}
	}
}
*/

#include<iostream>
#include<map>
#define MAX 200001
using namespace std;

int F, T;
int f_size[MAX];
int parent[MAX];


int getParent( int x) {
	if (parent[x] == x)return x;
	return parent[x] = getParent( parent[x]);
}

int unionParent( int x, int y) {
	int a = getParent( x);
	int b = getParent( y);
	if (a != b) {
		f_size[a] += f_size[b];
		parent[b] = a;
		f_size[b] = 1;
	}
	return f_size[a];
}


void init() {
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		map<string, int>map;
		cin >> F;
		for (int i = 1; i < 2*F+1; i++) {
			f_size[i] = 1;
			parent[i] = i;
		}
		int idx = 1;
		for (int i = 0; i < F; i++) {
			string f1, f2;
			cin >> f1 >> f2;

			if (map.count(f1) == 0)map[f1] = idx++;
			if (map.count(f2) == 0)map[f2] = idx++;

			int name1 = map[f1];
			int name2 = map[f2];

			

			cout << unionParent(name1, name2)<<'\n';
		}
	}
}

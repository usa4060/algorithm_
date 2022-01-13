#include<iostream>
using namespace std;
int T, R;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> R;
		string a;
		cin >> a;
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < R; j++) {
				cout << a[i];
			}
		}
		cout << '\n';
	}
}
#include<iostream>
using namespace std;

int N;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = N; i >= 1; i--) {
		cout << i << '\n';
	}
}
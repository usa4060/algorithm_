#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int max = 0;
	int check;
	for (int i = 1; i <= 9; i++) {
		int num;
		cin >> num;
		if (max < num) { max = num; check = i; }
	}
	cout << max << '\n' << check;
}

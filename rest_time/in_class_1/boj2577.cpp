#include<iostream>
using namespace std;

int arr[10] = {0,};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	int sum = 0;
	cin >> a >> b >> c;
	sum = a * b * c;
	int check = 10;
	while (sum != 0) {
		int temp = sum / check;
		int dev  = sum % check;
		arr[dev]++;
		sum -= dev;
		sum /= check;
	}
	for (int i = 0; i < 10; i++)cout << arr[i] << '\n';
}
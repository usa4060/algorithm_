#include<iostream>
using namespace std;
int num, sum = 0, remainderArr[42] = { 0, };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 10; i++) {
        cin >> num;
        if (!remainderArr[num % 42]++)
            sum++;
    }
    cout << sum;
}
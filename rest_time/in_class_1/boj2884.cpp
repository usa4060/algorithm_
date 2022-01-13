#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    if (b < 45) {
        b += 15;
        if (--a < 0)
            a = 23;
    }
    else
        b -= 45;

    cout << a << " " << b;

}
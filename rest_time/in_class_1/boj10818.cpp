#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num, count, min = 1000001, max = -1000001;
    cin >> count;



    while (cin >> num) {
        max = num > max ? num : max;
        min = num < min ? num : min;
    }
    cout << min << " " << max;
}
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, X;
    cin >> N >> X;

    int arr[10001];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int j = 0; j < N; j++)
        if (arr[j] < X)
            cout << arr[j] << " ";
}
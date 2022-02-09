#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    deque<pair<int,int>> v;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back({ i, num }); //i가 몇 번째 num이 우선 순위
    }
    int cnt = 0;
    while (1) {
        bool check = false;
        int fir = v.front().first; //자기가 처음에 몇 번째 위치 했는지
        int sec = v.front().second; //자기의 우선 순위
        int vsize = v.size();
        for (int i = 1; i < vsize; i++) {
            if (sec < v[i].second) {
                check = true;
                break;
            }
        }
        if (!check) {
            int temp = v.front().first;
            v.pop_front();
            cnt++;
            if (M == temp) break;
        }
        else {
            auto temp = v.front();
            v.pop_front();
            v.push_back(temp);
        }
    }
    cout  <<cnt << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

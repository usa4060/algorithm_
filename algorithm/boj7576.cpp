#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1002;
vector<pair<int,int>>check;
int M,N,ans;
int map[MAX][MAX];
int dis[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};



bool check_ripen(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(map[i][j] == 0)return false;
            }
    }
    return true;
}

void bfs(){
    if(check_ripen())return;
    
    queue<pair<int, int>>q;
    for(int i = 0; i < check.size(); i++){
        q.push(make_pair(check[i].first, check[i].second));
        dis[check[i].first][check[i].second] = 0;
    }
    
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int X = nx+dx[i];
            int Y = ny+dy[i];
            if(map[X][Y] == 0){
                q.push(make_pair(X, Y));
                map[X][Y] = 1;
                dis[X][Y] = dis[nx][ny]+1;
                ans = max(ans, dis[X][Y]);
            }
        }
    }
    if(!check_ripen())ans = -1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>M>>N;
    
    for(int i = 0; i < MAX; i++){
        memset(map[i], -1, sizeof(map[i]));
        memset(dis[i], -1, sizeof(dis[i]));
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin>>map[i][j];
            if(map[i][j] == 1){
                check.push_back(make_pair(i, j));
            }
        }
    }
    
    ans = 0;  //  토마토가 원래 다 익어 있을 때
    bfs();
    cout<<ans<<'\n';
}


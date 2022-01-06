#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 102;
int M,N,H,ans;
int map[MAX][MAX][MAX];
int dis[MAX][MAX][MAX];

int dx[6] = {0,1,0,-1,0,0};
int dy[6] = {1,0,-1,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

vector<pair<int, pair<int, int>>> ripe;

bool check_ripe(){
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= M; k++){
                if(map[i][j][k] == 0)return true;
            }
        }
    }
    return false;
}

void bfs(){
    if(!check_ripe())return;
    queue<pair<int, pair<int, int>>>q;
    for(int i = 0; i < ripe.size(); i++){
        q.push(make_pair(ripe[i].first, make_pair(ripe[i].second.first, ripe[i].second.second)));
        dis[ripe[i].first][ripe[i].second.first][ripe[i].second.second] = 0;
    }
    while(!q.empty()){
        int z = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        for(int i = 0; i < 6; i++){
            int nz = z+dz[i];
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(map[nz][ny][nx] == 0){
                map[nz][ny][nx] = 1;
                dis[nz][ny][nx] = dis[z][y][x] + 1;
                ans = max(ans, dis[nz][ny][nx]);
                q.push(make_pair(nz, make_pair(ny, nx)));
            }
        }
    }
    if(check_ripe())ans = -1;
}


void init(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            memset(map[i][j], -1, sizeof(map[i][j]));
            memset(dis[i][j], -1, sizeof(dis[i][j]));
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>M>>N>>H;
    
    init();
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= M; k++){
                cin>>map[i][j][k];
                if(map[i][j][k] == 1){
                    ripe.push_back(make_pair(i, make_pair(j, k)));
                }
            }
        }
    }
    ans = 0;
    bfs();
    cout<<ans<<'\n';
    
}

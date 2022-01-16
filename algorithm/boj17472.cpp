#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 12
#define LAND_MAX 7
using namespace std;
int N, M;
int idx = 0;
int land[LAND_MAX];
vector<pair<int, int>>node[LAND_MAX];
int map[MAX][MAX];
bool visit[MAX][MAX] = {0, };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


class Land{
public:
    int u, v;
    int distance;
    Land(int u, int v, int dis){
        this->u = u;
        this->v = v;
        this->distance = dis;
    }
    
    bool operator < (const Land &l)const{
        return this->distance < l.distance;
    }
};

int find(int x){
    if(land[x] == x)return x;
    return land[x] = find(land[x]);
}

void uni(int x, int y){
    int u = find(x);
    int v = find(y);
    if(u < v)land[v] = u;
    else land[u] = v;
}

bool isCycle(int x, int y){
    int u = find(x);
    int v = find(y);
    if(u == v)return true;
    return false;
}





void dfs(int x, int y, int index){
    if(visit[x][y])return;
    visit[x][y] = true;
    node[index].push_back(make_pair(x, y));
    for(int i = 0; i < 4; i++){
        if(map[x+dx[i]][y+dy[i]] == 1)dfs(x+dx[i], y+dy[i], index);
    }
    return;
}


void makeMap(int x, int y){
    for(int i =1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            int loc;
            cin>>loc;
            map[i][j] = loc;
        }
    }
}

void makeIsland(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(!visit[i][j]&&map[i][j])dfs(i,j,++idx);
        }
    }
}

void valueOfDis(vector<Land>& island){
    for(int from = 1; from < idx; from++){
        for(int i = 0; i < node[from].size(); i++){
            for(int to = from + 1; to <= idx; to++){
                for(int j = 0; j < node[to].size(); j++){
                    
                    
                    
                    if(node[from][i].first == node[to][j].first){
                        int y = node[from][i].first;
                        if(node[from][i].second < node[to][j].second){
                            for(int x = node[from][i].second; x < node[to][j].second; x++){
                                if(x == node[to][j].second - 1){
                                    int dis = node[to][j].second - node[from][i].second;
                                    island.push_back(Land(from,to,dis - 1));
                                    break;
                                }
                                else if(map[y][x + 1] == 1)break;
                            }
                        }
                        else{
                            for(int x = node[to][j].second; x < node[from][i].second; x++){
                                if(x == node[from][i].second - 1){
                                    int dis = node[from][i].second - node[to][j].second;
                                    island.push_back(Land(from,to,dis - 1));
                                    break;
                                }
                                else if(map[y][x + 1] == 1)break;
                            }
                        }
                    }
                    if(node[from][i].second == node[to][j].second){
                        int x = node[from][i].second;
                        if(node[from][i].first < node[to][j].first){
                            for(int y = node[from][i].first; y < node[to][j].first; y++){
                                if(y == node[to][j].first - 1){
                                    int dis = node[to][j].first - node[from][i].first;
                                    island.push_back(Land(from,to,dis - 1));
                                    break;
                                }
                                else if(map[y + 1][x] == 1)break;
                            }
                        }
                        
                        
                        
                        else{
                            for(int y = node[to][j].first; y < node[from][i].first; y++){
                                if(y == node[from][i].first - 1){
                                    int dis = node[from][i].first - node[to][j].first;
                                    island.push_back(Land(from,to,dis - 1));
                                    break;
                                }
                                if(map[y + 1][x] == 1)break;
                            }
                        }
                    }
                    
                    
                    

                }
            }
        }
    }       // island 섬별로 거리 계산 완료
}
void init(){
    for(int i = 0; i < LAND_MAX; i++)land[i] = i;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<Land>island;
    
    cin>>N>>M;
    init();
    makeMap(N,M);
    makeIsland();
      // 섬에 번호매기기 & 섬에 해당하는 좌표 집어넣기 node[1]부터
    valueOfDis(island);
    // 현재 node에는 섬 번호에 해당하는 좌표들이 들어가있음
   
    
    sort(island.begin(), island.end());
    int sum = 0;
    for(int i = 0; i < island.size(); i++){
        if(!isCycle(island[i].u, island[i].v)){
            if(island[i].distance > 1){
                sum+=island[i].distance;
                uni(island[i].u, island[i].v);
            }
        }
    }
    
    int check = 0;
    for(int i = 1; i < LAND_MAX; i++){
        if(node[i].size() == 0){check = i;break;}
        else if (i == 6)check = 7;
    }
    
    
    for(int i = 1; i < LAND_MAX; i++){
        land[i] = land[land[i]];
    }
    
    for(int i = 1; i < check; i++){
        if(land[i] != 1){cout<<-1<<'\n'; return 0;}
    }
    cout<<sum<<'\n';
    return 0;
}

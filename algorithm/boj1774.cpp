#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 1001
using namespace std;
int N, M;
int god[MAX];

int find(int x){
    if(god[x] == x)return x;
    return god[x] = find(god[x]);
}

void uni(int x, int y){
    int u = find(x);
    int v = find(y);
    if(u > v)god[u] = v;
    else god[v] = u;
}

double calcuDis(int x1, int x2, int y1, int y2){
    double y_dis = pow(x1-x2, 2);
    double x_dis = pow(y1-y2, 2);
    return sqrt(x_dis + y_dis);
}

bool isCycle(int x, int y){
    int u = find(x);
    int v = find(y);
    if(u == v)return true;
    return false;
}

class God{
public:
    int u, v;
    double distance;
    God(int x, int y, double dis){
        this->u = x;
        this->v = y;
        this->distance = dis;
    }
    
    bool operator <(const God &god)const{
        return distance < god.distance;
    }
};
void init(){
    for(int i = 0; i < MAX; i++)god[i] = i;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;
    
    vector<pair<int, int>>loc;
    vector<God>god;
    loc.push_back(make_pair(-1, -1)); // loc[0]값 버리기 용도
    init();
    for(int i = 0; i < N; i++){
        int x, y;
        cin>>x>>y;
        loc.push_back(make_pair(x, y));
    }
    
    for(int i = 1; i < N; i++){
        for(int j = i+1; j <= N; j++){
            double dis = calcuDis(loc[i].first, loc[j].first, loc[i].second, loc[j].second);
            god.push_back(God(i,j,dis));
        }
    }
    sort(god.begin(), god.end());
    
    while(M--){
        int u, v;
        cin>> u >> v;
            uni(u,v);
    }
    long double sum = 0.0;
    for(int i = 0; i < god.size(); i++){
        if(!isCycle(god[i].u, god[i].v)){
            uni(god[i].u, god[i].v);
            sum+=god[i].distance;
        }
    }
    sum = round(sum*100)/100;   // 소숫점 3자리에서 반올림하는 함수 (#include<iomanip>사용)
    cout<<fixed<<setprecision(2)<<sum<<'\n';
}

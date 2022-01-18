#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#define MAX 501
using namespace std;
int N, M;
int node[MAX];
bool cycle[MAX];
int find(int x){
    if(node[x] == x)return x;
    return node[x] = find(node[x]);
}

void uni(int x, int y){
    int u = find(x);
    int v = find(y);
    if(u < v)node[v] = u;
    else node[u] = v;
}

bool isCycle(int x, int y){
    int u = find(x);
    int v = find(y);
    if(u == v)return true;
    return false;
}

void makeCycle(int nu){
    for(int i = 1; i <= N; i++){
        if (node[i] == node[nu]) {
            cycle[i] = true;
        }
    }
}

void init(){
    memset(cycle, false, sizeof(cycle));
    for(int i = 0; i < MAX; i++)node[i] = i;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int idx = 0;
    while(1){
        idx++;
        vector<pair<int, int>>edge;
        set<int>cnt;
        init();
        cin>>N>>M;
        if(N == 0 && M == 0)break;
        while(M--){
            int u, v;
            cin>>u>>v;
            edge.push_back(make_pair(u, v));
        }
        sort(edge.begin(),edge.end());
        for(int i = 0; i < edge.size(); i++){
            int nu = edge[i].first;
            int nv = edge[i].second;
            
            if(!isCycle(nu, nv)){
                uni(nu, nv);
            }
            else if(nu == nv){
                makeCycle(nu);
            }
            else if(isCycle(nu, nv)){
                makeCycle(nu);
            }
            
            if(cycle[nu] || cycle[nv]){
                makeCycle(nu);
                makeCycle(nv);
            }
        }
        for(int i = 1; i <= N; i++){
            if(!cycle[i]){
                cnt.insert(node[i]);
            }
        }
        
        if(cnt.size() == 0){
            cout<<"Case "<<idx<<": "<<"No trees."<<'\n';
        }
        else if(cnt.size() == 1){
            cout<<"Case "<<idx<<": "<<"There is one tree."<<'\n';
        }
        else{
            cout<<"Case "<<idx<<": "<<"A forest of "<< cnt.size() <<" trees."<<'\n';
        }
    }
}


#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAX 100001
using namespace std;
int N,cost;
int star[MAX];


int find(int x){
    if(star[x] == x)return x;
    return star[x] = find(star[x]);
}

void uni(int x, int y){
    int u = find(x);
    int v = find(y);
    if(u < v)star[v] = u;
    else star[u] = v;
}

bool isCycle(int x, int y){
    int u = find(x);
    int v = find(y);
    if(u == v)return true;
    return false;
}


class Node{
public:
    int x, y, z;
    int idx;
    Node(int x, int y, int z, int idx){
        this->x = x;
        this->y = y;
        this->z = z;
        this->idx = idx;
    }
};


class STAR{
public:
    int u, v;
    int distance;
    STAR(int x, int y, int dis){
        this->u = x;
        this->v = y;
        this->distance = dis;
    }
    
    bool operator < (const STAR &star)const{
        return this->distance < star.distance;
    }
};

int dist(int x1, int x2, int y1, int y2, int z1, int z2){
    int x_d = sqrt(pow(x1-x2, 2));
    int y_d = sqrt(pow(y1-y2, 2));
    int z_d = sqrt(pow(z1-z2, 2));
    
    return min(x_d,min(y_d,z_d));

}

bool comX(Node& a, Node&b){
    return a.x < b.x;
}
bool comY(Node& a, Node&b){
    return a.y < b.y;
}
bool comZ(Node& a, Node&b){
    return a.z < b.z;
}


void init(){
    for(int i = 0; i < MAX; i++)star[i] = i;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    init();
    vector<STAR>star;
    vector<Node>node;
    vector<pair<int, pair<int, int>>>locate;
    cin>>N;
    for(int i = 1; i <= N; i++){
        int x, y, z;
        cin>>x>>y>>z;
        node.push_back(Node(x,y,z,i));
    }
    
    sort(node.begin(), node.end(), comX);
    for(int i = 0; i < node.size() - 1; i++){
        star.push_back(STAR(node[i].idx,node[i+1].idx,(node[i+1].x - node[i].x)));
    }
    sort(node.begin(), node.end(), comY);
    for(int i = 0; i < node.size() - 1; i++){
        star.push_back(STAR(node[i].idx,node[i+1].idx,(node[i+1].y - node[i].y)));
    }
    sort(node.begin(), node.end(), comZ);
    for(int i = 0; i < node.size() - 1; i++){
        star.push_back(STAR(node[i].idx,node[i+1].idx,(node[i+1].z - node[i].z)));
    }
    
    // 메모리 : 3N , 시간 : 3 * O(N)
    
    sort(star.begin(), star.end()); //
    
    int sum = 0;
    for(int i = 0; i < star.size(); i++){
        if(!isCycle(star[i].u, star[i].v)){
            sum+=star[i].distance;
            uni(star[i].u, star[i].v);
        }
    }
    
    cout<<sum<<'\n';
}

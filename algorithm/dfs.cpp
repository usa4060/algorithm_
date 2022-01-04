#include <iostream>
#include <vector>

using namespace std;

int num = 7;
bool c[8];
vector<int> a[8];

void dfs(int x){
    if(c[x])return;
    c[x] = true;
    cout<<x<<' ';
    for(int i = 0; i < a[x].size(); i++){
        int y = a[x][i];
        dfs(y);
    }
}

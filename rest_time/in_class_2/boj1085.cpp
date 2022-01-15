#include<iostream>
#include <algorithm>
using namespace std;
int x, y, w, h;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>x>>y>>w>>h;
    
    int m = min(x,min(w-x,min(y,h-y)));
    cout<<m<<'\n';
}

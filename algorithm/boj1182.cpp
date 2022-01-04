#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int T;
string s;

vector<pair<int,string>> p;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    while(T--){
        cin>>s;
        p.push_back({s.length(),s});
    }
    sort(p.begin(), p.end());
    
    cout<<p[0].second<<'\n';
    for(int i = 1; i < p.size(); i++){
        if(p[i].second != p[i-1].second)
        cout<<p[i].second <<'\n';
    }
    return 0;
}

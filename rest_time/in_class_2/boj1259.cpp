#include <iostream>
#include <string.h>
using namespace std;
string s;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>s;
    while(s != "0"){
        bool check = true;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != s[s.size()-i-1])check = false;
        }
        if(!check)cout<<"no"<<'\n';
        else cout<<"yes"<<'\n';
        cin>>s;
    }
}

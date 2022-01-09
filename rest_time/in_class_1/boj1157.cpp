#include <iostream>
#include <algorithm>
using namespace std;

pair<int, char>alpha[26];

int main(){
    string str;
    cin>>str;
    
    
    for(int i = 0; i < 26; i++){
        alpha[i].first = 0;
        alpha[i].second = 'A'+i;
    }
    
    for(int i = 0; i < str.size(); i++){
        if(str[i] < 'a')alpha[str[i]-'A'].first++;
        else alpha[str[i]-'a'].first++;
    }
    
    sort(alpha, alpha+26);
    if(alpha[25].first == alpha[24].first)cout<<"?"<<'\n';
    else cout<<alpha[25].second<<'\n';
    
}

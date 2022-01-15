#include <iostream>
#include <vector>
using namespace std;
vector<int>v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    v.push_back(-1);
    for(int i = 0; i < 11000000; i++){
        int check = 0;
        int temp = i;
        int div = 0;
        while(temp != 0){
            div = temp%10;
            temp /= 10;
            if(div == 6){check++;}
            else check = 0;
            
            if(check == 3){v.push_back(i); break;};
        }
    }
    int a;
    cin>>a;
    cout<<v[a]<<'\n';
}

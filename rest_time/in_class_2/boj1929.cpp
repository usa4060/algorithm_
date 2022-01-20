#include<iostream>
#include<vector>
#define MAX 1000001
using namespace std;

vector<int>save;
bool eratos[MAX] ;
int M,N;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>M>>N;

    for(int i = 2; i <= N; i++){
        for(int j = i; j <= N; j = j + i){
            if(!eratos[i]){
                save.push_back(j);
                eratos[j] = true;
            }else{
            eratos[j] = true;
            }
        }
    }
    for(int i = 0; i < save.size(); i++){
        if(save[i] >= M && save[i] <=N)cout<<save[i]<<"\n";
    }
}


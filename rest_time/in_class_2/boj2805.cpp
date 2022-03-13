#include <iostream>
using namespace std;
 
int main() {
    int n;
    long long m,mid,min=0,max=0,ans=0;
    cin>>n>>m;
    long long arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(max<arr[i]) max=arr[i];
    }
    
    max--;
    while(min<=max)
    {
        mid=(min+max)/2;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(arr[i]-mid)>=0?arr[i]-mid:0;
        }
        if(sum<m) max=mid-1;
        else
        {
            if(ans<mid) ans=mid;
            min=mid+1;
        }
    }
    cout<<ans;
    return 0;
}


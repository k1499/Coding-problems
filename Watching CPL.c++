//Problem link : https://www.codechef.com/problems/WIPL/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[200007],n,k,dp[9002][9002];

ll f(int h1,int h2,ll lvl,int ind){
    if(dp[h1][h2]!=-1){
        return dp[h1][h2];
    }
    else if(ind>=n){
        if(h1>=k&&h2>=k){
           return   lvl;
        }
        return 1e9;
    }
    else if(h1<k&&h2<k){
        return dp[h1][h2] = min(f(min(h1+arr[ind],k),h2,lvl+1,ind+1),f(h1,min(k,h2+arr[ind]),lvl+1,ind+1));
    }
    else if(h1>=k&&h2<k){
        return f(h1,min(k,h2+arr[ind]),lvl+1,ind+1);
    }
    else if(h1<k&&h2>=k){
        return f(min(k,h1+arr[ind]),h2,lvl+1,ind+1);
    }
    else if(h1>=k&&h2>=k){
        return  lvl;
    }
}
void solve(){
  cin>>n>>k;
  memset(arr,0,sizeof(arr));
 for(int i = 0;i<=9000;i++){
     for(int j = 0;j<=9000;j++){
         dp[i][j] = -1;
     }
 }
  for(int i = 0;i<n;i++){
      cin>>arr[i];
  }
  sort(arr,arr+n,greater<int>());
  ll ans = f(0,0,0,0);
  if(ans==1e9){
      cout<<"-1"<<endl;
  }
  else{
      cout<<ans<<endl;
  }
 
}
int main(){
    ll test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}
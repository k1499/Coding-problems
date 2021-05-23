//problem link : https://codeforces.com/contest/676/problem/C
#include<bits/stdc++.h>
using namespace std;
string str;
int aa[100007],bb[100007],n,k;
bool f(int s){
    if(min(aa[s-1],bb[s-1])<=k)return true;
    for(int i = s;i<n;i++){
        int aas = aa[i] - aa[i-s];
        int bbs = bb[i] - bb[i-s];
       
        if(min(aas,bbs)<=k){
            return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>k>>str;
    for(int i = 0;i<str.size();i++){
        int a = str[i] - 'a';
        if(a==0){
            aa[i]++;
        }
        else{
            bb[i]++;
        }
    }
    for(int i = 1;i<str.size();i++){
        aa[i] = aa[i] + aa[i-1];
        bb[i] = bb[i] + bb[i-1];
    }
    int l = 1,r = n,ans = 0;
    while(l<=r){
       /*cout<<" l "<<l<<" r "<<r<<endl;*/
        int mid = (l+r)/2;
        if(f(mid)==true){
            ans = max(ans,mid);
            l = mid+1;
        }
        else{
            r = mid - 1; 
        }
    }
    cout<<ans<<endl;
}
//problem link : https://codeforces.com/contest/1433/problem/D
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[5001],test,n;
    cin>>test;
    while(test--){
        cin>>n;
        set<int> s;
        s.clear();
        memset(arr,0,sizeof(arr));
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            s.insert(arr[i]);
        }
        bool visited[5007];
        if(s.size()==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            int flag = 0; 
            memset(visited,false,sizeof(visited));
            for(int i = 0;i<n;i++){
                flag=0;
                if(visited[i]==false){
                    for(int j  = 0;j<n&&flag==0;j++){
                        if(arr[i]!=arr[j]&&i!=j){
                        cout<<i+1<<" "<<j+1<<endl;
                        flag=1;
                       visited[j] = true;
                        }
                    }
                }
            
            }
           
        }
        
        
    }
}
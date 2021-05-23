//problem link : https://codeforces.com/contest/1435/problem/D
#include<bits/stdc++.h>
using namespace std;
struct node {
    int ind,ele;
};
node arr[200007];
bool comp(node n1,node n2){
    if(n1.ind<=n2.ind){
        return true;
    }
    return false;
}
void solve(){
    int n,a,count = 0,start = 0;
    stack<int> st,ver;
    vector<int> in;
    string str = "";
    char ch;
    cin>>n;
    for(int i = 0;i<2*n;i++){
        cin>>ch;
        if(ch=='+'){
            str+='+';
            count++;
            st.push(count);
        }
        else{
            str+='-';
            cin>>a;
            in.push_back(a);
            if(st.empty()==true){
                cout<<"NO"<<endl;
                return;
            }
            else{
              int tt = st.top();
              st.pop();
              arr[start].ind = tt;
              arr[start].ele = a;
              start++;            
            }
        }
    }
   sort(arr,arr+n,comp);
   int stt = 0,vec_itr = 0;
   for(int i = 0;i<str.size();i++){
       if(str[i]=='+'){
           if(ver.empty()==true){
             ver.push(arr[stt++].ele);
           }
           else{
               int topp = ver.top();
               if(topp<arr[stt].ele){
                   cout<<"NO";
                   return;
               }
               else{
                   ver.push(arr[stt++].ele);
               }
           }
        }
        else{
            if(!ver.empty()){
              int pot = ver.top();
              int elem = in[vec_itr++];
              if(elem!=pot){
                cout<<"NO";
                return;
              }
              else{
                ver.pop();
              }
            }
            else{ 
                cout<<"NopopO";
                return;
            }
        }
       
   }
   if(ver.size()!=0){
       cout<<"NO";
   }
   else{
       cout<<"YES"<<endl;
       for(int i = 0;i<n;i++){
           cout<<arr[i].ele<<" ";
       }
   }
}
int main(){
    solve();
}
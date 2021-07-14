#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int go(int today,int profit,int lastDay,vector<int>& t,vector<int>& p){
  if(today > lastDay) return 0;
  if(today == lastDay) return profit;
  int ret = go(today+1,profit,lastDay,t,p);
  ret= max(ret,go(today+t[today],profit+p[today],lastDay,t,p));
  return ret;
}

int main(){
  int n; 
  cin>>n;
  vector<int> t(n);
  vector<int> p(n);
  for(int i=0; i<n; i++){
    cin>>t[i]>>p[i];
  }
  cout<<go(0,0,n,t,p)<<'\n';
}
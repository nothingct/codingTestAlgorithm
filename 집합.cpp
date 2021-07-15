#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m ,n; 
  string cmd;
  cin>>m;
  int s=0;
  for(int i=0; i<m; i++){
    cin>>cmd;
    if(cmd=="add"){
      cin>>n; n-=1;
      s |= (1<<n);
    }else if(cmd=="remove"){
      cin>>n; n-=1;
      s &= ~(1<<n);
    }else if(cmd=="check"){
      cin>>n; n-=1;
      int ret = s & 1<<n;
      if(ret) cout<<"1\n";
      else cout<<"0\n";
    }else if(cmd=="toggle"){
      cin>>n; n-=1;
      s ^= 1<<n;
    }else if(cmd=="all"){
      s= (1<<20) -1;
    }else if ( cmd=="empty"){
      s=0;
    }
  }
  return 0;
}
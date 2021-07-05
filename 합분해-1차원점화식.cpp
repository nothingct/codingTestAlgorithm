#include <iostream>
using namespace std;

const int MAX =200;
const long long MOD = 1000000000;
long long d[MAX+1];
int main(){
  int n,m;
  cin>>n>>m;
  d[0]=1; 
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      d[j]+=d[j-1];
      d[j]%=MOD;
    }
  }
  cout<<d[n]<<'\n';
  return 0;
}
#include <iostream>
using namespace std;
const int MAX = 10000000;
const long long MOD= 1000000009LL;

long long d[MAX+1];

int main(){
  d[0]=1,d[1]=1, d[2]=2;
  for(int i=3; i<=MAX; i++){
    d[i]= d[i-1]+d[i-2]+d[i-3];
    d[i]%=MOD;
  }
  int t;
  cin>>t;
  while(t--){
    int n ;
    cin>>n;
    cout<<d[n]<<'\n';
  }
}
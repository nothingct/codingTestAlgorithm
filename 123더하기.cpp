#include <iostream>
#include <algorithm>

using namespace std;

int go(int sum,int n){
  if (sum > n ) return 0;
  if (sum == n) return 1;

  int ret = 0;
  for(int i=1; i<=3; i++){
    ret+=go(sum+i,n);
  }
  return ret;
}


int main(){
  int t;
  cin>>t;
  while(t--){
    int n ;
    cin>>n;
    cout<<go(0,n)<<'\n';
  }
}
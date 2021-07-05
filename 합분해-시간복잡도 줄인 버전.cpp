#include <iostream>
using namespace std;

const long long MOD = 1000000000;
const int MAX = 200;
//d[n][m] : 0~n까지의 정수 m개를 더해서 그 합이 n이 되는 경우의 수
long long d[MAX+1][MAX+1];

int main(){
  int n,m;
  cin>>n>>m;
  d[0][0] = 1ll;
  //d[m][n] = sum([d[m-1][n-k]]) [k<=n]
  //d[m-1][n] = sum(d[m-1][n-1-k]) [K<=n-1]
  //d[m][n] = d[m-1][n]
  for(int i=1; i<=m; i++){
    for(int j=0; j<=n; j++){
      d[i][j]= d[i-1][j];
      if( j>=1){
        d[i][j]+=d[i][j-1];
      }
      d[i][j] %=MOD;
    }
  }
  cout<<d[m][n]<<'\n';
}
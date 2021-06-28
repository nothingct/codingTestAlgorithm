#include <iostream>
using namespace std;
const int MAX = 200;
const long long MOD = 1000000000;

long long d[MAX+1][MAX+1];

int main(){
  int n,k;
  cin>>n>>k;
  // d[k][i] : 0~i까지의 정수 K개를 더해서 그 합이 i 이 되는 경우의수
  // 초기값 : d[i][1]= 1 ,1개의 정수만으로 i를 표현하려면 자기자신 말고는 불가능.by 반복문->초기값보장됨
  d[0][0]=1ll;
  for(int i=1; i<=k; i++){
    for(int j=0; j<=n; j++){
      for(int l=0; l<=j; l++){
      // 점화식 : d[k][i] = sum(d[k-1][i-j]) [ j<=i]
        d[i][j]+= d[i-1][j-l];
        d[i][j]%=MOD;
      }
    }
  }
  cout<<d[k][n]<<'\n';
}
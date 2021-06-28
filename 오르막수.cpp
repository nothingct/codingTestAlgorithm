#include <iostream>
using namespace std; 
const int MAX = 1000;
const int MOD = 10007;
// d[n][m] : 1번째 수 ~n번째 수 를 채울 때, n번째 수가 m 일때의 오르막수의 경우의 수.
int d[MAX+1][10];

int main(){
  int n; 
  cin>>n;

  // 초기 값 d[1][m] = 1 한 자리 오르막수 는 모두 자기자신을 끝으로 가질 수 밖에없다.
  for(int i=0; i<=9; i++){
    d[1][i] = 1;
  } 
  for(int i=2; i<=n; i++){
    for(int j=0; j<=9; j++){
      for(int k=0; k<=j; k++){
        // 점화식 : d[i][j] :BY 연결의 조건 i번째 자리의 수가 j일 때의 오르막 수는
        //  i-1번째 자리의 수가 j보다 작거나 같은 오르막 수들만 연결이 가능하다
        d[i][j] += d[i-1][k];
        d[i][j]%=MOD;
      }
    }
  }
  int ans = 0;
  // 정답 : d[n][1]~d[n][9] 의 합 
  for(int i=0; i<=9; i++){
    ans+=d[n][i];
    ans%=MOD;
  }
  cout<<ans<<'\n';
}

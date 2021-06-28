#include <iostream>
using namespace std;
const int MAX = 100000;
const int MOD = 9901;

// d[n][case]: 1번쨰~n번째인 우리를 채워 나갈 때, 마지막 n번째 우리를 case로 채웠을 때의 경우의 수
// case 0: 양 쪽 모두 사자를 놓지 않음 
// case 1: 왼 쪽에 사자를 놓음
// case 2: 오른쪽에 사자를 놓음 
int d[MAX+1][3];

int main(){
  int n ;
  cin>>n;
  // 초기값: 1번째 우리의 case를 결정 
  for(int i=0; i<3; i++){
    d[1][i]=1;
  }
  for(int i=2; i<=n; i++){
    // 점화식 : d[n][case] 에서 BY연속의 조건 n번쨰 우리를 어떤 case로 채우느냐에 따라 식이 달라진다.->RGB거리의 논리와 동일
    // d[n][0] : d[n-1][0],d[n-1][1],d[n-1][2] 모두 올 수 있음 => 모두 더함
    // d[n][1] : d[n-1][0],d[n-1][2] 올 수 있음 => 모두 더함 
    // d[n][2] : d[n-1][0],d[n-1][1] 올 수 있음 => 모두 더함
    d[i][0] = d[i - 1][0] + d[i - 1][1] + d[i - 1][2];
    d[i][1] = d[i - 1][0] +  d[i - 1][2];
    d[i][2] = d[i - 1][0] + d[i - 1][1];
    for(int j=0; j<3; j++){
      d[i][j] %=MOD;
    }
  }
  cout << (d[n][0]+d[n][1]+d[n][2])%MOD <<'\n';
  return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;
// houses[n][c] : n번 집을 c색깔로 칠할떄의 비용 (0 :R, 1:G, 2:B)
int houses[MAX+1][3];
//  d[n][c] : 1~n번째 집을 색칠한 비용의 합에서, 마지막 n번째 집을 c색깔로 칠했을 때의 최소비용
//  n제한 1000, 비용 제한 1000 -> 모든 집 비용이 1000->1000*1000=>int 범위.
int d[MAX+1][3];
int main(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++){
    for(int j=0; j<3; j++){
      cin>>houses[i][j];
    }
  }
  // 초기값 : 각 집이 직선개념으로 나열됨->원형 구조가 X: 1번째 집은 R,G,B 중 모든 색깔이 올 수 있음 AND d[1][c] = houses[1][c]일수 밖에 없음 
  // 점화식 d[n][c] : BY 문제의 조건(연속성) -> n-1번째 집의 색은 무조건 c색깔이 아니어야 함. +배열의 idx가 0부터 시작하고 전역변수로 선언해서 d[0][c]= 0 이기에
  //점화식에 초기값 설정도 같은 논리로 포함시킬 수 있음. Ex) d[1][0]= min(d[0][1],d[0][2])+houses[1][0] 인데 어차피 d[0][c]= 0=>d[1][0]=housds[1][0] 과 동일.
  // n번째 집의 color에 따라서 경우가 달라지므로, n번째 color를 고정시킨 후 점화식 적용하면 코드 직관적.
  for(int i=1; i<=n; i++){
    d[i][0] = min(d[i - 1][1], d[i - 1][2]) + houses[i][0];
    d[i][1] = min(d[i - 1][0], d[i - 1][2]) + houses[i][1];
    d[i][2] = min(d[i - 1][0], d[i - 1][1]) + houses[i][2];
  }
  //d[n][0] ,d[n][1], d[n][2] 중 최솟값 이 정답
  cout << min({d[n][0], d[n][1], d[n][2]}) <<'\n';
  return 0;
}

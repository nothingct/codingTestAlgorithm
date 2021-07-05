#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000;
// houses[n][c] : n번 집을 c색깔로 칠할떄의 비용 (0 :R, 1:G, 2:B)
int houses[MAX + 1][3];
//  d[n][c] : 1~n번째 집을 색칠한 비용의 합에서, 마지막 n번째 집을 c색깔로 칠했을 때의 최소비용
//  n제한 1000, 비용 제한 1000 -> 모든 집 비용이 1000->1000*1000=>int 범위.
int d[MAX + 1][3];
int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> houses[i][j];
    }
  }
  // 추가된 조건 : 원형 조건 : 1번째 집 과 n번째 집은 이웃한다. 
  // 원형 조건만 을 제외하면 기존의 RGB 거리와 같은 문제 이다=>어떠한 방법을 사용하여 RGB거리와 같은 방식으로 풀 수 있을까?
  // 기존의 RGB=> 집의 연결방식이 직선이었다. 그렇다면 원형을 직선으로 만들면 되지 않을까?
  // 즉, 원형일 떄의 제한(조건)을 만족하는 직선의 경우의 수를 모두 확인하면 이것은 원형일 때의 정답을 구한 것과 같지 않을까?
  // 기존의 조건 :  연속하는 집 은 서로 다른 색
  // 이번에 추가된 조건 : 1번과 n번은 서로 다른색=>CASE 분류 
  // 1번째 집 R => n번째 집 : G 또는 B 2가지 경우
  // 1번쨰 집 G => n번째 집 : R 또는 B 2가지 경우
  // 1번째 집 B => n번째 집 : R 또는 G 2가지 경우
  //=>1번째 집의 색깔을 고정 후 점화식 배열을 채운 후 1번째 집의 색에 따른 원형조건을 유지하는 n번째 집의 색으로 이루어진 점화식배열의 값이 정
  int ans = MAX*MAX+1;
  for(int i=0; i<3; i++){
    // 1번째 집의 색깔을 i 로 고정한다. 그 외 의 색은 나올 수없는 값( 최댓값)으로 고정해서 정답의 후보가 될 수 없게 한다.
    d[1][0] = MAX * MAX + 1;
    d[1][1] = MAX * MAX + 1;
    d[1][2] = MAX * MAX + 1;
    d[1][i] = houses[1][i];
    //2번째 집부터 n번째 집까지는 RGB거리 문제 와 동일한 점화식을 세워 점화식 배열을 채운다.
    for(int j=2; j<=n; j++){
      d[j][0] = min(d[j - 1][1], d[j - 1][2]) + houses[j][0];
      d[j][1] = min(d[j - 1][0], d[j - 1][2]) + houses[j][1];
      d[j][2] = min(d[j - 1][0], d[j - 1][1]) + houses[j][2];
    }
    //n번째 집의 색깔이 1번째 집의 색깔인 i 와 같을 수 없기에 같다면 생략 하고 다른 색일 때만 정답의 후보를 찾는다.
    for(int j=0; j<3; j++){
      if(i==j) continue;
      ans = min(ans,d[n][j]);
    }
  }
  //모든 경우(6가지의 정답후보)를 마치고 정답을 구하였다.
  cout<<ans<<'\n';
  return 0;
}
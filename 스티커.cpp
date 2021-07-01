#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;
long long sticker[MAX + 1][2];
// d[row][state일]: row번째 의 상태가  state일 때, 1번째 부터 row상태까지의 만들 수 있는 최댓값.
// state -> 0: 위,아래 둘다 스티커 떼지 않음, 1: 위의 스티커를 떼었음 , 2: 아래의 스티커를 떼엇음.
long long d[MAX + 1][3];
int main()
{
  // 입력 처리
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    for (int i = 0; i < 2; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        cin >> sticker[j][i];
      }
    }
    d[0][0] = d[1][0] = d[2][0] = 0;
    // 점화식 ->마지막 Row번째의 state에 따라서 case 분류 한다. WHY?연속의 조건
    // state->0 : d[row][0] : max(d[row-1][0],d[row-1][1],d[row-1][2]): 위아래 다 떼지 않았으므로 모든 case 가능)
    // state->1 : d[row][1] : max(d[row-1][0],d[row-1][2])+sticker[i][0]: 위를 떼엇음->바로 이전 번째는 위를 뗄 수없음.
    // state->2 : d[row][2] : max(d[row-1][0],d[row-1][1]+sticker[i][1]: 아래를 떼엇음 -> 발바로 이전 번째는 아래를 뗼 수 없음.
    for (int i = 1; i <= n; i++)
    {
      d[i][0] = max({d[i - 1][0], d[i - 1][1], d[i - 1][2]});
      d[i][1] = max(d[i - 1][0], d[i - 1][2]) + sticker[i][0];
      d[i][2] = max(d[i - 1][0], d[i - 1][1]) + sticker[i][1];
    }
    // 정답은 n번째 줄까지의 최댓값 을 찾아야 한다. -> d[n][0],d[n][1],d[n][2] 의 max
    long long ans = max({d[n][0], d[n][1], d[n][2]});
    cout << ans << '\n';
  }
  return 0;
}

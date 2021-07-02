#include <iostream>
using namespace std;

const int MAX = 1000;

int a[MAX];
int d[MAX];
int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  //O(N^2)
  //d[i] : i를 "시작"으로 하는 가장 긴 감소하는 부분수열 :
  // 이번엔 점화식이 해당 i부터 시작을 하기 때문에
  // '뒤'에서부터 테이블을 채우며 시작한다.
  for (int i = n-1; i >=0; i--)
  {
    d[i] = 1; //초기값 1: 적어도 자기자신은 포함하므로
    for (int j = i+1; j < n; j++)
    { 
      if (a[i] > a[j] && d[i] < d[j] + 1)
      { 
        d[i] = d[j] + 1;
      }
    }
  }
  // 정답 찾기 위해 순차탐색 O(N)
  int ans = d[0];
  for (int i = 1; i < n; i++)
  {
    if (ans < d[i])
    {
      ans = d[i];
    }
  }
  cout << ans << '\n';
  return 0;
}
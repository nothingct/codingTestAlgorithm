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
  //d[i] : i를 "끝"으로 하는 가장 긴 감소하는 부분수열 :
  for (int i = 0; i < n; i++)
  {
    d[i] = 1; //초기값 1: 적어도 자기자신은 포함하므로
    for (int j = 0; j < i; j++)
    {
      if (a[i] < a[j] && d[i] < d[j] + 1)
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
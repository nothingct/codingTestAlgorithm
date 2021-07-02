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
  //d[i] : i를 "끝"으로 하는 가장 큰 증가하는 부분수열 :
  // 이전의 가장 긴 증가하는 부분 수열 의 끝이 자신보다 작으면 연결이 가능하고 , a[i] > a[j] ,j < i (이전에 나와야하므로)
  // 이들 중 가장 큰 부분수열과 연결해야 i 로 끝나는 가장 큰 증가하는 부분수열을 만들 수 잇음.
  for (int i = 0; i < n; i++)
  {
    d[i] = a[i];  //초기값 a[i]: 적어도 자기자신은 포함하므로
    for (int j = 0; j < i; j++)
    { //이전 에 나와야 하는 조건 충족
      if (a[i] > a[j] && d[i] < d[j] + a[i])
      { //증가 조건+ 갱신
        d[i] = d[j] + a[i];
      }
    }
  }
  // 정답 찾기 위해 순차탐색 O(N)
  int ans = d[0];
  for (int i = 1; i < n; i++)
  {
    if (ans < d[i]){
      ans = d[i];
    }
  }
  cout << ans << '\n';
  return 0;
}
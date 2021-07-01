#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10000;
// d[n]: 1번째 포도주부터 n번째 포도주 를 시식할 수 있을 때, 시식량의 최댓값 :(3번연속은 안된다는 조건 준수)
// 1. n번째 포도주를 시식하지 않을 경우의 최댓값 = d[i-1]
// 2. n번째 포도주를 시식하고, n-1번째 포도주를 시식하지 않은 경우: d[i-2]+wines[i]
// 3. n-1번째, n번째 포도주를 시식하고 n-2번째 포도주는 시식하지 않은 경우: d[i-3]+wines[i-1]+wines[i]
int d[MAX + 1];
int wines[MAX + 1];

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> wines[i];
  }
  // d[1],d[2]일때는 3번연속 조건이 의미없으므로 무조건 마신다.
  d[1] = wines[1];
  d[2] = wines[1]+wines[2];
  for (int i = 3; i <= n; i++)
  {
    d[i]= max({d[i-1],d[i-2]+wines[i],d[i-3]+wines[i-1]+wines[i]});
  }
  cout<<d[n];
}
#include <iostream>
using namespace std;

const int MAX = 1000;

int a[MAX];
int d[MAX];
int s[MAX];
// 가장 긴 부분수열을 print하는 함수
void print(int idx){
  //더 이상 앞의 수가 없는 경우: 맨 첫번째 수인 경우
  if (idx == -1)
    return;
  //자신을 출력하기 전에, 앞의 수를 먼저 출력
  print(s[idx]);
  cout << a[idx] << ' ';
}

int main(){
  int n;
  cin >> n;

  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  //O(N^2)
  //d[i] : i를 "끝"으로 하는 가장 긴 증가하는 부분수열 :
  // 이전의 가장 긴 증가하는 부분 수열 의 끝이 자신보다 작으면 연결이 가능하고 , a[i] > a[j] ,j < i (이전에 나와야하므로)
  // 이들 중 가장 긴 부분수열과 연결해야 i 로 끝나는 가장 긴 증가하는 부분수열을 만들 수 잇음.
  for (int i = 0; i < n; i++){
    d[i] = 1;  //초기값 1: 적어도 자기자신은 포함하므로
    s[i] = -1; //초기값 -1: 처음은 자기자신만을 포함하므로 앞의 수 X 을
    for (int j = 0; j < i; j++)
    { //이전 에 나와야 하는 조건 충족
      if (a[i] > a[j] && d[i] < d[j] + 1)
      { //증가 조건+ 갱신
        d[i] = d[j] + 1;
        s[i] = j; //i로 끝나는 가장 긴 증가하는 부분수열 에서 i의 앞에는 a[j]의 수가 와야 함을 의미, stack 구조 -> s
      }
    }
  }
  // 정답 찾기 위해 순차탐색 O(N)
  int ans = d[0];
  int idx = 0;
  for (int i = 1; i < n; i++)
  {
    if (ans < d[i])
    {
      ans = d[i];
      idx = i;
    }
  }
  cout << ans << '\n';
  print(idx);
  cout << '\n';
  return 0;
}
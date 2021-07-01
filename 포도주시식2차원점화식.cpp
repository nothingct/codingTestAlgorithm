#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10000;
// d[n][state] : 1번째 ~n번째 까지의 포도주를 시식할 때, n번째 포도주를 마지막으로 마신다고 할 때, n번째 포도주를 마시는 상태가 state인 경우의 최댓값 
// state 0 : 0번 연속으로 마심->바로 이전인 n-1번째 포도주의 모든 상태 중 최댓값 : max([d-1][0],d[i-1][1],d[i-1][2])
// state 1 : 1번 연속으로 마심 ->바로 이전인 n-1번쨰 포도주는 마시지 않았음을 의미 : d[i-1][0]+wines[i]
// state 2 : 2번 연속으로 마심 ->n-2번째 포도주는 마시지 말고, n-1번쨰 포도주는 마셨음을 의미 : d[i-1][1]+ wines[i]
int d[MAX+1][3];
int wines[MAX+1];

int main(){
  int n; 
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>wines[i];
  }
  for(int i=1; i<=n; i++){
    d[i][0]=max({d[i-1][0],d[i-1][1],d[i-1][2]});
    d[i][1]=d[i-1][0]+wines[i];
    d[i][2]=d[i-1][1]+wines[i];
  }
  int ans = max({d[n][0],d[n][1],d[n][2]});
  cout<<ans;
}
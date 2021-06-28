#include <iostream>
using namespace std;
// 입력제한 10만-> O(N^2)이상 걸리는 알고리즘 X
//O(N) OR O(NlogN) 알고리즘 필요
const int MAX=100000;

int a[MAX];
int d[MAX];

int main(){
  int n ; 
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>a[i];
    d[i]=a[i]; //d[i] : i를 마지막 수로 갖는 연속합 중 최댓값. 초기값 : 자기자신은 무조건 가져야 하므로 a[i]
    if(d[i] < d[i-1]+a[i]){
      d[i]=d[i-1]+a[i]; 
      //BY 연속의 조건 : 바로 이전 i-1을 마지막 수로 갖는 연속값중 최대값 :d[i-1]
      //d[i-1]에 자기자신을 연결한 값 VS 자기자신 만을 갖는 값(D[i-1]이 음수인 경우 자기자신만을 연속합으로 갖는 것이 최대연속합이 되기 때문) 비교
      // O(N)만에 해결가능.
    }
  }
  int ans= d[0];
  for(int i=0; i<n; i++){
    if(ans < d[i]){
      ans=d[i];
    }
  }
  cout<<ans<<'\n';
}
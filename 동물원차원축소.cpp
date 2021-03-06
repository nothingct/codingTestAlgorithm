#include <iostream>
using namespace std;

const int MAX = 100000;
const int MOD = 9901;
// d[i] : i 번째 우리에 사자 가 있을 때의 경우의 수 .
int d [MAX+1];
// s[i] : d[1]~d[i] 까지의 연속합 을 기록 =>WHY? 시간복잡도 줄이기 위해서.
int s [MAX+1];

int main(){
  int n; 
  cin>>n;
  
  //한 마리도 안 놓아도 된다.
  d[0]=1;
  s[0]=d[0];
  //left OR right
  d[1]=2;
  s[1]=s[0]+d[1];

  for(int i=2; i<=n; i++){
    //점화식 d[i] : i번째에 사자가 있다.->
    //              i-1번째에 사자가 있다면 반대 편에 만 있어야함 :d[i-1]
    //              i-1번째에 사자가 없다면 i-2번째는 양쪽 모두 사자 있어도 됨: 2*d[i-2]
    //              i-1,i-2번째에 사자가 없다면 i-3번째는 양쪽 모두 사자 있어도 됨 : 2*d[i-3]
    //              ... 반복 
    //              i-1~2번째까지 사자가 없다면 1번째는 양쪽 모두 사자가 있어도 됨 :2*d[1]
    //결론 : d[i] = d[i-1]*2(d[1]+d[2]+...+d[i-1]) ->d[i]를 구하기 위해 1~(i-1)을 또 탐색하면 O(N^2) 이 걸림
    //==> d[i] = d[i-1]+2*s[i-2] : O(N) , 연속합을 기록하는 공간을 따로 만듬 : s[i]
    d[i] = d[i-1]+2*s[i-2];
    s[i] = s[i-1]+d[i]; //s[i] 갱신
    d[i]%=MOD;
    s[i]%=MOD;
  }
  //정답은 ? 1~n까지의 우리의 사자를 놓는 모든 경우의 수 : s[n]에 있다
  cout<<s[n]<<'\n';
  return 0;
}

 
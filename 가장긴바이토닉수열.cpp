#include <iostream>
using namespace std;

const int MAX = 1000;

int a[MAX];
//가장 긴 바이토닉 수열 : lis[i] +lids[i]-1
//lis[i] : i 에서 끝나는 가장 긴 증가하는 부분수열 +
//lds[i] : i 에서 시작하는 가장 긴 감소하는 부분 수열 
//i의 중복 이 있기 때문에 -1
int lis[MAX];
int lds[MAX];
int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  // i에서 끝나는 가장 긴 증가하는 부분 수열 구하기
  for (int i = 0; i<n; i++)
  {
    lis[i] = 1; //초기값 1: 적어도 자기자신은 포함하므로
    for (int j = 0; j < i; j++)
    {
      if (a[i] > a[j] && lis[i] < lis[j] + 1)
      {
        lis[i] = lis[j] + 1;
      }
    }
  }

  // i 에서 시작하는 가장 긴 감소하는 부분 수열 구하기 
  for (int i=n-1; i>-1; i--){
    lds[i]=1;
    for(int j= i+1; j<n; j++){
      if(a[i] >a[j] && lds[i] < lds[j]+1){
        lds[i] = lds[j]+1;
      }
    }
  }

  // 가장 긴 바이토닉 = max(lis[i]+lds[i])-1
  int ans =lis[0]+lds[0];
  for(int i=1; i<n; i++){
    if(ans < lis[i]+lds[i]){
      ans =lis[i]+lds[i];
    }
  }
  ans-=1;
  cout<<ans<<'\n';
  
  return 0;
}
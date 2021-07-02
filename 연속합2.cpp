#include <iostream>
#include <algorithm>
// 왜 vector를 사용하기로 하였는가? 입력값이 10만-> 실제로 n이 10이라고 할지라도 10만의 고정적인 배열을 a,conSumEnd,conSumBegin 에 할당해야함->메모리낭비
#include <vector>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  // conSumEnd[i] : i로 끝나는 연속합의 최댓값
  vector<int> conSumEnd(n);
  for(int i=0; i<n; i++){
    conSumEnd[i]=arr[i];
    if(i == 0) continue;
    conSumEnd[i] = max(conSumEnd[i-1]+arr[i],conSumEnd[i]);// 점화식 : 기존의 연속합 에 자신을 포함할 것인가 아니면 자기자신만을 가질것인가? : 기존연속합의 결과가 음수일 경우가 있기 때문 
  }

  // conSumBegin[i] : i로 시작하는 연속합의 최댓값 
  vector<int> conSumBegin(n);
  for(int i=n-1; i>=0; i--){
    conSumBegin[i]=arr[i];
    if(i==n-1) continue;
    conSumBegin[i] = max(conSumBegin[i+1] + arr[i], conSumBegin[i]);
  }

  //정답의 후보 : 1) 기존의 연속합에서의 최댓값 2) 기존의 연속합에서 하나의 원소를 제외한 최댓값 : 원소 i 를 기준으로 conSumEnd[i-1]+conSumBegin[i+1] 
  //1) 기존합에서 후보 찾기
  int ans =conSumEnd[0];
  for(int i=1; i<n; i++){
    ans =max(ans,conSumEnd[i]);
  }
  //2) 하나의 원소를 제외 한 상태에서 후보찾기 
  for(int i=1; i<n-1; i++){ // 어차피 중간 하나를 제외하므로 index 0, index n-1 은 볼 필요없다(처음, 끝 인덱스)
    ans= max(conSumEnd[i-1]+conSumBegin[i+1],ans);
  }
  cout<<ans<<'\n';
  return 0;
}
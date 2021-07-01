#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500;
int trianlge[MAX+1][MAX+1];
// d[col][row] : col번째 줄 row번째를 선택하였을 때의 삼각형의 지금 까지 의 최댓값 .
int d[MAX+1][MAX+1];

int main(){
  int n; 
  cin >>n;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=i; j++){
      cin>>trianlge[i][j];
    }
  }
  //초기값: d[1][1] 이 선택할 수 있는 경우 의 수는 오직 자기자신을 포함하는 것뿐이다.
  d[1][1] = trianlge[1][1];
  //점화식 : d[i][j] = i번째 줄 j번째를 포함하는 최댓값은 (i,j)에 도달 할 수 있는 방법인
  //        (i-1,j-1) , (i-1,j) 에서 연결되어야 하며 해당 위치에서의 최댓값 즉 
  //        d[i-1][j-1],d[i-1][j] 중 최댓값 + triangle[i][j] 를 선택하면된다.
  for(int i=2; i<=n; i++){
    for(int j=1; j<=i; j++){
      d[i][j]= max(d[i-1][j],d[i-1][j-1])+trianlge[i][j];
    }
  } 
  int ans =0;
  for(int i=1; i<=n; i++){
    ans= max(ans,d[n][i]);
  }
  cout<<ans<<'\n';
}

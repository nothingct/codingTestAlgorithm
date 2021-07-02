// 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.
#include <iostream>
using namespace std;

const int MAX =30;
int d[MAX+1];

int main(){
  int n;
  cin>>n;
  d[0]=1;
  for(int i=2; i<=n; i+=2){
    d[i]=d[i-2]*3;
    for(int j= i-4; j>=0; j-=2){
      d[i]+= d[j] *2;
    }
  }
  cout<<d[n]<<'\n';
}
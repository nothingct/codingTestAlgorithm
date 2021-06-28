#include <iostream>
using namespace std;

const int MAX = 100000;
int d[MAX+1];

int main(){
  int n ;
  cin>>n;
  // O(N*√N)
  for(int i=1; i<=n; i++){
    //d[i] : i를 제곱수의 합으로 표현할 때 그 항의 최소개수
    d[i]=i; //초기값: 모든 수 i는 1^2 를 i 번 더함으로 표현할 수 있다. 
    //d[i] : ㅁ + ㅁ + ㅁ + ㅁ + x^2 => (x^2 <= i)=>min(d[i-x^2]+1)
    for(int j=1; j*j <= i; j++){
      if(d[i] > d[i-j*j]+1){
        d[i]= d[i-j*j]+1;
      }
    }
  }
  cout<<d[n]<<'\n';
}
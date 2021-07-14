#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool isValidPW(string &pw){
  int mo =0,ja=0;
  for (char ch: pw){
    if(ch=='a' || ch=='e'|| ch=='i'||ch=='o'||ch=='u') mo++;
    else ja++;
  }
  return ja>=2 && mo >=1;
}

void go(int index, vector<char>& alpha, string pw, int n ){
  if(pw.length() == n ) {
    if(isValidPW(pw)) cout<<pw<<'\n';
    return;
  }
  if(index == alpha.size() ) return;
  go(index+1,alpha,pw+alpha[index],n);
  go(index+1,alpha,pw,n);
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<char> alpha(m);
  for(int i=0; i<m; i++){
    cin>>alpha[i];
  }
  sort(alpha.begin(),alpha.end());
  go(0,alpha,"",n);
}
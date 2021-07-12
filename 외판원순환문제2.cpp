#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INT_MAX =2147483647;
int w[11][11];

int main(){
  int n ; 
  cin >>n;
  vector<int> perm(n);
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> w[i][j];
    }
  }
  for(int i=0; i<n; i++){
    perm[i] = i;
  }
  int ans = INT_MAX;
  do{
    if(perm[0] != 0) break;
    bool isPossible = true;
    int costs = 0; 
    for(int i=0; i<n-1; i++){
      if(w[perm[i]][perm[i+1]] == 0) isPossible = false;
      else costs+=w[perm[i]][perm[i+1]];
    }
    if(isPossible&& w[perm[n-1]][perm[0]] != 0){
      costs += w[perm[n-1]][perm[0]];
      ans = min(ans,costs);
    }
  }while(next_permutation(perm.begin()+1,perm.end()));
  cout<<ans<<'\n';
}
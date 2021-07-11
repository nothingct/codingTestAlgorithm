#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int calDiffSum(vector<int>&a){
  int ret= 0; 
  for(int i=1; i<a.size(); i++){
    ret +=abs(a[i]-a[i-1]);
  }
  return ret;
}
int main(){
  int n ;
  cin>>n;
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr.begin(), arr.end());
  int ans = 0;
  do{
    ans =  max(ans,calDiffSum(arr));
  }while(next_permutation(arr.begin(), arr.end()));
  cout<<ans<<'\n';
}
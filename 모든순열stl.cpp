#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    arr[i]=i+1;
    cout<<arr[i]<<' ';
  }
  cout<<'\n';
  while(next_permutation(arr.begin(),arr.end())){
    for(int i=0; i<n; i++){
      cout<<arr[i]<<' ';
    }
    cout<<'\n';
  }
  return 0;
}

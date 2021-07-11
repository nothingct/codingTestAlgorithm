#include <iostream>
#include <vector>


using namespace std;

bool next_permutation(vector<int> & a ,  int n ){
  int i = n -1 ; 
  while( i > 0 && a[i-1] >= a[i]) i--;
  if( i <=0) return false;
  int j = n-1 ; 
  while(j>=i && a[j] <=a[i-1]) j--;
  swap(a[i-1],a[j]);
  j = n-1;
  while( i < j ) {
    swap(a[i],a[j]);
    i+=1; j-=1;
  }
  return true;
}
int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    arr[i]=i+1;
  }
  for(int i=0; i<n; i++){
    cout<<arr[i]<<' ';
  }
  cout<<'\n';
  while(next_permutation(arr,n)){
    for(int i=0; i<n; i++){
      cout<<arr[i]<<' ';
    }
    cout<<'\n';
  }
  return 0;
}

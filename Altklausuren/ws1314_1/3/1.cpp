#include<vector>
#include<iostream>
using namespace std;

int main(){
  vector<int> v(3);
  vector<int>::reverse_iterator i;
  int j=1;
  for (i = v.rbegin(); i != v.rend(); i++,j++) if (*i==0) *i=j;
  *(v.begin())+=2;
  return 0;
}
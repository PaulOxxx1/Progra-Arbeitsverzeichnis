#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <mpi.h>

using namespace std;

int measure_roundtrip(const vector<int> & vertices, const vector<pair<pair<int,int>,short> > & edges) {
  vector<int>::const_iterator vert_iter, vert_iter_prev;
  vector<pair<pair<int,int>,short> >::const_iterator edge_iter;
  
  int roundtrip_length = 0;
  vert_iter = vertices.begin();
  vert_iter_prev = vert_iter;
  vert_iter++;
  
  for (; vert_iter != vertices.end(); vert_iter++) {
    for (edge_iter = edges.begin(); edge_iter != edges.end(); edge_iter++) {
      if (((*edge_iter).first.first == *vert_iter_prev && (*edge_iter).first.second == *vert_iter) || 
          ((*edge_iter).first.second == *vert_iter_prev && (*edge_iter).first.first == *vert_iter)) {
        roundtrip_length += (*edge_iter).second;
      }
    }
    
    vert_iter_prev = vert_iter;
  }
  
  return roundtrip_length;
}

int main(int argc, char const *argv[]) {
  const int n = 5;
  vector<int> vertices;
  vector<pair<pair<int,int>,short> > edges;
  vector<int>::const_iterator iter, iter2;
  
  for (int i = 0; i < n; i++) {
    vertices.push_back(i);
  }
  
  srand(0);
  for (iter = vertices.begin(); iter != vertices.end(); iter++) {
    iter2 = iter;
    iter2++;
    for (; iter2 != vertices.end(); iter2++) {
      pair<int,int> p = make_pair(*iter, *iter2);
      short d = floor((double)rand() / RAND_MAX * 1000);
      
      pair<pair<int,int>,short> e = make_pair(p,d);
      edges.push_back(e);
      
      cout << *iter << " / " << *iter2 << " / " << d << endl;
    }
  }
  
  int shortest_roundtrip = 9999999;
  int roundtrip_length = measure_roundtrip(vertices,edges);
  cout << roundtrip_length << endl;
  
  /*while (next_permutation(vertices.begin(), vertices.end())) {
    if 
  }*/
  
  return 0;
}
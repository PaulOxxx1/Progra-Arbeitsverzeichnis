int main() {
  int* v[3];
  int x;
  
  v[2] = &x;
  v[1] = new int;
  v[0] = new int[2];
  
  delete v[1];
  delete [] v[0];
  
  return 0;
}
int main() {
  int* v;
  int** vp;
  
  vp = &v;
  v = new int[2];
  
  delete [] v;
  
  return 0;
}
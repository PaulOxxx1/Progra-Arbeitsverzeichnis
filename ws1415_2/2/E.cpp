int main() {
  int*** p;
  int* v;
  
  p = new int**;
  *p = &v;
  
  int s[3];
  v = &(s[0]);
  
  delete p;
  
  return 0;
}
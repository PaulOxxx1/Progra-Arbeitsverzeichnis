int main() {
  int*** p;
  int* v;
  int s[3];
  
  p = new int**;
  *p = &v;
  v = &(s[0]);
  
  delete p;
  
  return 0;
}
int main() {
  int* k;
  int* j;
  int** i;
  int*** h;
  
  k = new int;
  j = k;
  i = &j;
  h = &i;
  
  delete k;
  
  return 0;
}
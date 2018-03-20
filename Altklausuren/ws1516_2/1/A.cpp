int main() {
  int i;
  int* v[3];

  v[0] = new int;
  v[1] = &i;
  v[2] = v[0];
  
  return 0;
}

int main() {
  int*** v;
  int i;
  
  v = new int**;
  *v = new int*[2];
  (*v)[1] = new int;
  
  delete (*v)[1];
  delete [] *v;
  delete v;
  
  return 0;
}
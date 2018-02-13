#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

class node {
  int v;
  node *l, *r;
public:
  node(int v): l(0), r(0), v(v) {}
  ~node() {
    if (l) delete l;
    if (r) delete r;
  }
  int& vaccess() { return v; }
  node*& laccess() { return l; }
  node*& raccess() { return r; }
  int rsum() {
    int sum = 0;
    if (l) sum += l->rsum();
    if (r) sum += r->rsum();
    sum += v;
    return sum;
  }
  void print() {
    if (l) l->print();
    cout << v << " ";
    if (r) r->print();
  }
};

class BinTree {
  node* root;
  unsigned int s;
public:
  BinTree(): root(0), s(0) {}
  ~BinTree() { delete root; }
  void print_sum() {
    if (root) {
      cout << root -> rsum() << endl;
    } else {
      cout << 0 << endl;
    }  
  }
  void add_node(int v) { s++;
    node* p = root;
    node* hp = root;
    while (p) {
      hp = p;
      if (p->vaccess() > v) {
        p = p -> laccess();
      } else {
        p = p -> raccess();
      }
    }
    if (hp) {
      if (hp -> vaccess() > v) {
        hp -> laccess() = new node(v);
      } else {
        hp -> raccess() = new node(v);
      }
    } else {
      root = new node(v);
    }
  }
  void print() { if (root) root -> print(); }
  int gets() { return s; }
};

int main(int argc, char* argv[]) {
  assert(argc==2);
  BinTree tree;
  ifstream in(argv[1]);
  int s = 0; int v = 0;
  in >> s;
  for (int i=0;i<s;i++) {
    in >> v;
    tree.add_node(v);
    cout << tree.gets() << ": ";
    tree.print();
    cout << endl;
  }
  tree.print_sum();
}
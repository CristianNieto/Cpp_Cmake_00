// #include "test.h"
#include <any>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

using namespace std;

struct visitor;

struct animal { // Pure virtual function
  virtual void accept(visitor &v) = 0;
}; // Pure virtual function

struct dog : animal {
  virtual void accept(visitor &v) override;
};

struct cat : animal {
  virtual void accept(visitor &v) override;
};

struct visitor { // Pure virtual function
  virtual void visit(dog &d) = 0;
  virtual void visit(cat &c) = 0;
}; // Pure virtual function

void dog::accept(visitor &v) { v.visit(*this); }
void cat::accept(visitor &v) { v.visit(*this); }

struct print_visitor : visitor {
  void visit(dog &d) override { cout << "dog" << endl; }
  void visit(cat &c) override { cout << "cat" << endl; }
};

/* Main */
int main() {

  std::unique_ptr<animal> a(new dog);
  std::unique_ptr<animal> b(new cat);
  print_visitor v;
  a->accept(v);
  b->accept(v);

  return 0; // End
} //	Main
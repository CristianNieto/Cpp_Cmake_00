#ifndef _SON
#define _SON

#include <iostream>
// using std::cout;
// using std::endl;

template <typename T> class Son {
private:
  T sVal;

protected:
public:
  // Constructor
  Son(T s); // Constructor

  // Destructor
  virtual ~Son(); // Destructor

  // Operators

  // Getters
  T getSVal() { return sVal; }
  // Setters

  // Functions
};
#endif //_SON
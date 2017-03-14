
#include <iostream>
#include "item.h"

using std::cout;
using std::endl;

Item::Item(void) {
  cout << "constructor" << endl;
}

Item::~Item(void) {
  cout << "destructor" << endl;
}

void Item::PrintContent() const {
  cout << "Here is the content." << endl;
}



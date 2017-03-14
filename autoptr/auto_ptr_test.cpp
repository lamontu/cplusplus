
#include <iostream>
#include "auto_ptr.h"
#include "item.h"

using std::cout;


int main() {
  auto_ptr<Item> itemPtr(new Item);
  itemPtr->PrintContent();
  auto_ptr<Item> itemPtr2(itemPtr);
  itemPtr2->PrintContent();
  return 0;
}

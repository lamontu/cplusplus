
#include <iostream>
#include <cstdio>

using namespace std;

typedef enum { CB_MOVE = 0, CB_COMEBACK, CB_BUYEQUIP } cb_type;
typedef void (*cb_func)(void *);

class CCommu {
 public:
  CCommu() {
    memset(func_list, 0, sizeof(cb_type) * (CB_BUYEQUIP + 1));
    memset(func_args, 0, sizeof(void *) * (CB_BUYEQUIP + 1));
  }

  // register callback function
  int reg_cb(cb_type type, cb_func func, void *args = nullptr) {
    if (type <= CB_BUYEQUIP) {
      func_list[type] = func;
      func_args[type] = args;
    }
    return 0;
  }

 public:
  cb_func func_list[CB_BUYEQUIP + 1];  // array of function pointers
  void * func_args[CB_BUYEQUIP + 1];  // array of function arguments
};



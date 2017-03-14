
#include "def.h"

class CGameStart {
 public:
  CGameStart();
  ~CGameStart();
  void Init();
  void run();
  void Execute();

  // callback functions
  void static Move(void *args);
  void static Comeback(void *args);
  void static Buyequip(void *args);

 public:
  CCommu *pCommu;
};



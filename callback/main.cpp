
#include "GameStart.h"

int main() {
  CGameStart *pGame = new CGameStart;
  pGame->run();
  if (pGame->pCommu->func_list[CB_MOVE] != nullptr) {
    pGame->pCommu->func_list[CB_MOVE](pGame->pCommu->func_args[CB_MOVE]);
  }

  return 0;
}



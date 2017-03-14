
#include "GameStart.h"

CGameStart::CGameStart() : pCommu(nullptr) {  }

void CGameStart::Init() {  // register callback functions when initializing 
  pCommu = new CCommu;
  pCommu->reg_cb(CB_MOVE, Move, this);
  pCommu->reg_cb(CB_COMEBACK, Comeback, this);
}

void CGameStart::run() {
  Init();
}

void CGameStart::Execute() {
  cout << "Callback function is running." << endl;
}

CGameStart::~CGameStart() {
  if (pCommu != nullptr) {
    delete pCommu;
    pCommu = nullptr;
  }
}

void CGameStart::Move(void *args) {
  CGameStart *pGame = (CGameStart *) args;
  pGame->Execute();
}

void CGameStart::Comeback(void *args) {
  // Unknown
  //char *str = (char *)args;
  //cout << str << endl;
}



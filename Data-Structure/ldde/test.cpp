
  bool remove (int value) {
      bool finded = this->search(value);
      if (!finded)
          return false;
      else {
          Node* ptrAnt = nullptr;
          Node* ptrAtual = first;
          while (ptrAtual != nullptr && ptrAtual->value < value) {
              ptrAnt = ptrAtual;
              ptrAtual = ptrAtual->next;
          }
          if (!ptrAtual) {
              return false;
          }
          if (ptrAtual->next && ptrAnt) {
              ptrAnt->next = ptrAtual->next;
              ptrAtual->next->previous = ptrAnt;
              delete ptrAtual;
              n--;
              return true;
          }
          else if (!ptrAtual->next){
              if (ptrAnt) {
                  ptrAnt->next = nullptr;
                  this->last = ptrAnt;
                  delete ptrAtual;
                  n--;
                  return true;
              }
              else{
                  this->last = nullptr;
                  delete ptrAtual;
                  n--;
                  return true;
              }
          }
      }
      return true;
  }



  bool search (int value) {
    Node* ptrAnt = nullptr;
    Node* ptrAtual = first;
    while (ptrAtual != nullptr && ptrAtual->value < value) {
      ptrAnt = ptrAtual;
      ptrAtual = ptrAtual->next;
    }
    if (ptrAtual && ptrAtual->value == value)
        return true;
    return false;
  }

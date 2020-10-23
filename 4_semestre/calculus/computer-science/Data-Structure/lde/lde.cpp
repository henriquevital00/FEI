#include <iostream>
using namespace std;



// Tipo abstrato de dados
class AbstractOrderedList {
public:
  AbstractOrderedList () {
  }

  virtual bool insert (int value)=0;
  virtual bool remove (int value) = 0;
  virtual bool search (int value) = 0;
  virtual int getAtIndex (int index) = 0;
  virtual unsigned int getSize () = 0;

  virtual void print () {
    for (int i = 0; i < getSize (); ++i) {
      cout << getAtIndex (i) << " ";
    }
    cout << endl;
  }


  virtual ~AbstractOrderedList () {
  }
};


class LinkedList;
class Node {
private:
  int value;
  Node* next;
  friend class LinkedList;

public:
  ~Node () {
      std::cout << "Call the destructor " << std::endl;
  }
};

class LinkedList : public AbstractOrderedList {
private:
  Node* first;
  int n;

public:
  LinkedList () {
    first = nullptr;
    n = 0;
  }
  bool insert (int value) {
    Node* newNode = new Node;
    if (newNode == nullptr)
      return false;

    newNode->value = value;
    newNode->next = nullptr;

    Node* ptrAnt = nullptr;
    Node* ptrAtual = first;
    while (ptrAtual != nullptr && ptrAtual->value < value) {
      ptrAnt = ptrAtual;
      ptrAtual = ptrAtual->next;
    }

    if (ptrAnt != nullptr)
      ptrAnt->next = newNode;
    else
      this->first = newNode;

    newNode->next = ptrAtual;

    this->n++;
    return true;
  }

  bool remove (int value) {
    // IMPLEMENTAR
    Node* ptrAnt = nullptr;
    Node* ptrAtual = first;
    while (ptrAtual != nullptr && ptrAtual->value < value) {
      ptrAnt = ptrAtual;
      ptrAtual = ptrAtual->next;
    }
    if (ptrAtual == nullptr) {
        return false;
    }
    else if (ptrAtual->value != value)
        return false;
    else if(ptrAtual){
        if (ptrAnt != nullptr){
            if (ptrAtual->next){
                Node* a = ptrAtual->next;
                delete ptrAtual;
                ptrAnt->next = a;
                n--;
                return true;
            }
            else{
                delete ptrAtual;
                ptrAnt->next = nullptr;
                n--;
                return true;
            }
        }
        else{
            ptrAnt = ptrAtual->next;
            this->first = ptrAnt;
            delete ptrAtual;
            n--;
            return true;
        }
    }
    return false;
  }

  bool search (int value) {
    // IMPLEMENTAR
    Node* ptrAnt = nullptr;
    Node* ptrAtual = first;
    while (ptrAtual != nullptr && ptrAtual->value < value) {
      ptrAnt = ptrAtual;
      ptrAtual = ptrAtual->next;
    }
    if (!ptrAtual)
        return false;
    if (ptrAtual->value == value){
        return true;
    }
    return false;
  }

  int getAtIndex (int index) {
    Node* tmp = first;
    for (int i = 0; tmp != nullptr && i < index; i++) {
      tmp = tmp->next;
    }
    if (tmp != nullptr)
      return tmp->value;
    else
      return -1;
  }

  virtual void print () {
    Node* tmp = first;
    while (tmp) {
      cout << tmp->value << " ";
      tmp = tmp->next;
    }
    cout << endl;
  }
  unsigned int getSize () {
    return 0;
  }
    ~LinkedList () {
    Node* tmp = first;
    Node* tmpNext;
    while (tmp) {
      tmpNext = tmp->next;
      delete tmp;
      tmp = tmpNext;
    }
  }
};


int main () {
  // NÃO ALTERAR O MAIN
  AbstractOrderedList* l = new LinkedList ();

  cout << (l->remove (0) ? "removi 0" : "nao removi") << endl;
  l->print ();
  cout << (l->insert (5) ? "inseri 5" : "nao inseri") << endl;
  l->print ();
  cout << (l->insert (85) ? "inseri 85" : "nao inseri") << endl;
  l->print ();
  cout << (l->insert (69) ? "inseri 69" : "nao inseri") << endl;
  l->print ();
  cout << (l->remove (5) ? "removi 5" : "nao removi") << endl;
  l->print ();
  cout << (l->insert (84) ? "inseri 84" : "nao inseri") << endl;
  l->print ();
  cout << (l->insert (83) ? "inseri 83" : "nao inseri") << endl;
  l->print ();
  cout << (l->remove (84) ? "removi 84" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (83) ? "removi 83" : "nao removi") << endl;
  l->print ();
  cout << (l->insert (38) ? "inseri 38" : "nao inseri") << endl;
  l->print ();
  cout << l->search (85) << endl;
  cout << l->search (86) << endl;
  cout << (l->insert (856) ? "inseri 856" : "nao inseri") << endl;
  l->print ();
  cout << (l->insert (846) ? "inseri 846" : "nao inseri") << endl;
  l->print ();
  cout << (l->remove (856) ? "removi 856" : "nao removi") << endl;
  l->print ();
  cout << (l->insert (390) ? "inseri 390" : "nao inseri") << endl;
  l->print ();
  cout << (l->remove (390) ? "removi 390" : "nao removi") << endl;
  l->print ();
  cout << l->search (9000) << endl;
  cout << l->search (-1) << endl;

  cout << (l->remove (5) ? "removi 5" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (38) ? "removi 38" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (69) ? "removi 69" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (83) ? "removi 83" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (84) ? "removi 84" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (85) ? "removi 85" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (390) ? "removi 390" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (846) ? "removi 846" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (856) ? "removi 856" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (5) ? "removi 5" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (38) ? "removi 38" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (69) ? "removi 69" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (83) ? "removi 83" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (84) ? "removi 84" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (85) ? "removi 85" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (390) ? "removi 390" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (846) ? "removi 846" : "nao removi") << endl;
  l->print ();
  cout << (l->remove (856) ? "removi 856" : "nao removi") << endl;
  l->print ();

  delete l;

  return 0;
}


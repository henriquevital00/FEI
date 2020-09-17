/**
 * @author      : Guilherme Wachs Lopes (gwachs@fei.edu.br)
 * @file        : LDS
 * @created     : quarta set 09, 2020 21:35:09 -03
 */
//
//     ___________
//    / ALTERAR APENAS AS FUNÇÕES COM \
//    \ COMENTÁRIO "IMPLEMENTAR"       /
//     ---------------------------------
//            \   ^__^
//             \  (oo)\___
//                (__)\       )\/\
//                    ||----w |
//                    ||     ||
//


#include <iostream>
#include <vector>

using namespace std;

// Tipo abstrato de dados
template <typename T>
class AbstractOrderedList {
public:
  AbstractOrderedList () {
  }

  virtual bool insert (T value) = 0;
  virtual bool remove (T value) = 0;
  virtual bool search (T value) = 0;
  virtual T getAtIndex (unsigned int index) = 0;
  virtual unsigned int getSize () = 0;

  virtual void print () {
    for (unsigned int i = 0; i < getSize (); ++i) {
      cout << getAtIndex (i) << " ";
    }
    cout << endl;
  }


  virtual ~AbstractOrderedList () {
  }
};

template <typename T>
class AbstractResizableOrderedList : public AbstractOrderedList<T> {
public:
  // redimensiona a estrutura de modo que capacity=size
  virtual void shrink_to_fit () = 0;
  // redimensiona estrutura para novo newCapacity
  virtual bool resize (unsigned int newCapacity) = 0;
  virtual unsigned int capacity () = 0;


  virtual ~AbstractResizableOrderedList () {
  }
};


template <typename T>
class LDS : public AbstractResizableOrderedList<T> {
private:
  T* v;
  unsigned int cap;
  unsigned int size;

public:
  LDS () {
    cap = 10;
    size = 0;
    v = new T[cap];
  }

  bool insert (T value) {
    // encontrar posição
    // deslocar elementos
    // adicionar
    // size++
    if (size == cap) {
      if (!this->resize (2 * cap)) {
        return false;
      }
    }

    int i;
    for (i = 0; i < size && v[i] < value; i++)
      ;

    for (unsigned int j = size; j > i; j--) {
      v[j] = v[j - 1];
    }

    v[i] = value;
    size++;
    return true;
  }

  bool resize (unsigned int newCap) {
    // Aloca area com o dobro do tamanho
    // copia elementos
    T* newV = new T[newCap];
    if (!newV) // newV == nullptr
      return false;

    cap = newCap;
    size = ((size > cap) ? cap : size);

    for (int i = 0; i < size; i++) {
      newV[i] = v[i];
    }
    delete[] v;
    v = newV;

    return true;
  }


  void shrink_to_fit () {
    // Implementar
    this->cap = this->size;
  }

  unsigned int capacity () {
    // Implementar
    return this->cap;
  }

  unsigned int getSize () {
    // Implementar
    return this->size;
  }

  T getAtIndex (unsigned int index) {
    // Implementar
    if (index >= 0 && index < this->size)
        return this->v[index];
    std::cout << "Will return nullptr\n";
    return nullptr;
  }

  bool search (T value) {
    // Implementar
      int begin=-1;
      int end=this->size;
      int q=0;
      // Binária
      while (begin < end-1){
          if (this->size == 0){
              return false;
          }
          q = (begin + end)/2;

          if(v[q] == value){
              return true;
          }

          if( v[q] < value){
              begin = q;
          }
          else{
             end = q;
          }
      }
    return false;
  }

  bool remove (T value) {
    // Implementar
      bool find = search(value);
      bool finded = false;
      if(!find){
          return false;
      }
      else{
          for (int i = 0; i <= this->size-2; i++) {
              if (v[i] == value){
                  finded = true;
              }
              if (finded){
                  v[i] = v[i+1];
              }
        }
          this->size--;
        return true;
      }
  }

  void print () {
    for (int i = 0; i < size; i++) {
      cout << v[i] << endl;
    }
  }

  ~LDS () {
    delete[] v;
  }
};


int main () {
  LDS<string> l;
  l.insert ("babbs");
  l.insert ("coldren");
  l.insert ("highinterest");
  l.insert ("loney");
  l.insert ("bangwe");
  l.insert ("datagrams");
  l.insert ("needers");
  l.insert ("proboscidial");
  l.insert ("pighead");
  l.insert ("warfel");
  l.insert ("verbed");
  l.insert ("cyprinidae");
  l.insert ("dalmard");
  l.insert ("unhumbled");
  l.insert ("belinuridae");
  l.insert ("malibu");
  l.insert ("tuitionary");
  l.insert ("pushball");
  l.insert ("gatehouse");
  l.insert ("goodsprings");
  l.insert ("disillusion");
  l.insert ("bidkar");
  l.insert ("misumalpan");
  l.insert ("nonadecane");
  l.insert ("nahor");
  l.insert ("bimahs");
  l.insert ("cade");
  l.insert ("mbwisi");
  l.insert ("urfirnis");
  l.print ();
  cout << "capacity: " << l.capacity () << endl;
  cout << "size: " << l.getSize () << endl;
  cout << "====================" << endl;
  l.resize (5);
  l.insert ("jihad");
  l.print ();
  cout << "capacity: " << l.capacity () << endl;
  cout << "size: " << l.getSize () << endl;
  cout << "====================" << endl;
  l.shrink_to_fit ();
  l.print ();
  cout << "capacity: " << l.capacity () << endl;
  cout << "size: " << l.getSize () << endl;
  cout << "====================" << endl;
  cout << (l.remove ("pighead") ? "removeu pighead" : "nao removeu pighead") << endl;
  cout << (l.remove ("babbs") ? "removeu babbs" : "nao removeu babbs") << endl;
  cout << (l.remove ("jihad") ? "removeu jihad" : "nao removeu jihad") << endl;
  l.print ();
  cout << "capacity: " << l.capacity () << endl;
  cout << "size: " << l.getSize () << endl;
  cout << "====================" << endl;
  l.insert ("nonadecane");
  l.insert ("nahor");
  l.insert ("bimahs");
  l.insert ("cade");
  l.insert ("mbwisi");
  l.print ();
  cout << "capacity: " << l.capacity () << endl;
  cout << "size: " << l.getSize () << endl;
  cout << "====================" << endl;

  return 0;
}

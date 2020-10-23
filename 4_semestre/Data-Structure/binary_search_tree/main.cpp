/**
 * @author      : Henrique Vital Carvalho (henriquevital1000@hotmail.com)
 * @file        : main
 * @created     : quinta out 22, 2020 22:36:58 -03
 */

#include <iostream>

using namespace std;


template <typename T>
class Tree;

template <typename T>
class Node {
private:
  Node<T>* father;
  Node<T>* left;
  Node<T>* right;
  T value;


public:
  T getValue () {
    return value;
  }
  Node () : father (nullptr), left (nullptr), right (nullptr) {
    value = T{};
  }
  Node (T value) : father (nullptr), left (nullptr), right (nullptr), value (value) {
  }

  friend class Tree<T>;
};

template <typename T>
class Tree {
private:
  Node<T>* root;
  int n;

  void print (Node<T>* x) {
    if (!x)
      return;

    print (x->left);
    cout << x->value << " ";
    print (x->right);
  }

  void deleteSubTree (Node<T>* r) {
    if (!r)
      return;

    deleteSubTree (r->left);
    deleteSubTree (r->right);
    delete r;
  }

public:
  Tree () : root (nullptr), n (0) {
  }

  bool insert (T value) {
    Node<T>* novo = new Node<T> (value);
    if (!novo)
      return false;

    if (!root) {
      root = novo;
      n++;
      return true;
    }

    Node<T>* atual = root;
    Node<T>* anterior = nullptr;

    while (atual) {
      anterior = atual;

      if (value <= atual->value)
        atual = atual->left;
      else
        atual = atual->right;
    }

    novo->father = anterior;
    if (value <= anterior->value)
      anterior->left = novo;
    else
      anterior->right = novo;

    n++;
    return true;
  }

  Node<T>* search (T value) {
    Node<T>* atual = root;
    while (atual) {
      if (value < atual->value)
        atual = atual->left;
      else if (value > atual->value)
        atual = atual->right;
      else
        return atual;
    }
    return nullptr;
  }

  void print () {
    print (root);
    cout << endl;
  }

  ~Tree () {
    deleteSubTree (root);
  }
};

int main () {
  Tree<int> v;
  v.insert (50);
  v.insert (25);
  v.insert (75);
  v.insert (45);


  int buscas[] = { 2, 5, 26, 50, 25, 45, 75 };
  for (int i = 0; i < 7; i++) {
    Node<int>* s = v.search (buscas[i]);
    if (s)
      cout << "encontrei " << s->getValue () << endl;
    else
      cout << "nao encontrei " << buscas[i] << endl;
  }
  v.print ();

  return 0;
}


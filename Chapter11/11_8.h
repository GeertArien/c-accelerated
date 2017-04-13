#ifndef GUARD_11_8_H
#define GUARD_11_8_H

#include <memory>

int ex11_8();

template <class T>
struct Node
{
  T data;
  Node<T>* previous;
  Node<T>* next;

  Node() : data(0), previous(0), next(0) {};
  Node(T d) : data(d), previous(0), next(0) {};
};

template <class T>
class NodeIterator
{

public:
  NodeIterator(Node<T>* d) : data(d) {};

  NodeIterator& operator++();
  NodeIterator& operator--();
  NodeIterator  operator++(int);
  NodeIterator  operator--(int);
  bool operator!=(NodeIterator&) const;
  T& operator*() const;

private:
  Node<T>* data;

};

template <class T>
NodeIterator<T>& NodeIterator<T>::operator++()
{
  data = data->next;
  return *this;
}

template <class T>
NodeIterator<T>& NodeIterator<T>::operator--()
{
  data = data->previous;
  return *this;
}

template <class T>
NodeIterator<T> NodeIterator<T>::operator++(int)
{
  NodeIterator<T> ret(this->data);
  data = data->next;
  return ret;
}

template <class T>
NodeIterator<T> NodeIterator<T>::operator--(int)
{
  NodeIterator<T> ret(this->data);
  data = data->previous;
  return this;
}

template <class T>
bool NodeIterator<T>::operator!=(NodeIterator& rhs) const
{
  return this->data != rhs.data;
}

template <class T>
T& NodeIterator<T>::operator*() const
{
  return data->data;
}

template <class T>
class LList
{
 
public:
  typedef NodeIterator<T> iterator;
  typedef const NodeIterator<T> const_iterator;
  typedef size_t size_type;
  typedef T value_type;

  LList() : front(0), back(0), s(0) {}
  explicit LList(size_type s, const T& t = T()) { create(s, t); }
  LList(const LList& l) { create(l.begin(), l.end()); }

  LList& operator=(const LList&);
  ~LList() { uncreate(); }

  void push_back(const T& t) {
    append(t);
  }

  size_type size() const { return s; }
  iterator begin() { return iterator(front); }
  const_iterator begin() const { return iterator(front); }
  iterator end() { return iterator(0); }
  const_iterator end() const { return iterator(0); }
 
private:
  Node<T>* front;
  Node<T>* back;
  size_type s;

  std::allocator<Node<T>> alloc;

  void create(size_type, const T&);
  void create(iterator, iterator);
  void append(const T&);
  void uncreate();

};

template <class T>
LList<T>& LList<T>::operator=(const LList& l)
{
  if (&l != this) {
    uncreate();
    create(l.begin(), l.end());
  }
  return *this;
}

template <class T>
void LList<T>::create(size_type s, const T& t)
{
  for (size_type i = 0; i < s; i++)
    append(t);
}

template <class T>
void LList<T>::create(iterator b, iterator e)
{
  while (b != e)
    append(*b++);
}

template <class T>
void LList<T>::append(const T& t)
{
  Node<T>* node = new Node<T>(t);

  if (s == 0)
    front = node;
  else if (s == 1)
  {
    node->previous = front;
    back = node;
    front->next = node;
  }
  else
  {
    back->next = node;
    node->previous = back;
    back = node;
  }

  s++;
}

template <class T>
void LList<T>::uncreate()
{
  Node<T>* node = back;

  while (node != 0)
  {
    Node<T>* node_delete = node;
    node = node->previous;
    delete node_delete;
  }

  front = back = 0;
  s = 0;
}

#endif // !GUARD_11_8_H
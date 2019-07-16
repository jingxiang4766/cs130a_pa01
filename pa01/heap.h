#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <vector>

class heap{
public:
  heap();
  void add(int element);
  int delete_max();
  void build_heap();
  void up(int index);
  void down(int index);
  void printHeap();
  int getsize(){return size;}
private:
  int size;
  std::vector<int> v;
};











#endif

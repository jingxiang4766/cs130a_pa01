#include "heap.h"
#include <vector>
#include <iostream>

heap::heap(){
  v.push_back(0);
  size = 0;
}

void heap::add(int element){
  v.push_back(element);
  size++;
}

int heap::delete_max(){
  int max = v[1];
  v[1] = v[size];
  v.pop_back();
  this->down(1);
  size--;
  return max;
}

void heap::build_heap(){
  for(int i = size/2; i > 0; i--){
    down(i);
  }
}

void heap::up(int index){
  int parent = index/2;
  int temp;
  while(parent > 0){
    if(v[parent] < v[index]){
      temp = v[parent];
      v[parent] = v[index];
      v[index] = temp;
      index = index/2;
      parent = parent/2;
    }
  }
}

void heap::down(int index){
  int leftChild = 2 * index;
	int rightChild = 2 * index + 1;
	int largestIndex = index;

	if (leftChild <= size &&
    v[leftChild] > v[largestIndex]) {
		largestIndex = leftChild;
	}
	if (rightChild <= size &&
    v[rightChild] > v[largestIndex]) {
		largestIndex = rightChild;
	}
	if (largestIndex != index) {
		int temp = v[index];
		v[index] = v[largestIndex];
		v[largestIndex] = temp;
		down(largestIndex);
	}
}

void heap::printHeap(){
  for(int i = 1; i <= size; i++){
    std::cout<<v[i]<< " ";
  }
}

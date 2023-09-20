#ifndef HEAP_PRIORITY_QUEUE_HPP
#define HEAP_PRIORITY_QUEUE_HPP
#include "load.hpp"
#include <vector>
#include <cstring>
#include <algorithm>

typedef struct {
    char* word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency* heap;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity);
void destroyHeap(Heap* heap);
void insert(Heap* heap, const char* word, int frequency);
bool shouldInsert(Heap* heap, int frequency);
void adjustHeap(Heap* heap, int index);
void printHeap(Heap* heap);
void printHeapUnsorted(Heap* heap);

#endif // HEAP_PRIORITY_QUEUE_H

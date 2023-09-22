#include "heap.hpp"


Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->heap = (WordFrequency*)malloc(sizeof(WordFrequency) * (capacity + 1)); // Heap index starts from 1
    return heap;
}

void destroyHeap(Heap* heap) {
    free(heap->heap);
    free(heap);
}

void insert(Heap* heap, const char* word, int frequency) {
    if (heap->size < heap->capacity) {
        WordFrequency newEntry;
        newEntry.word = strdup(word);
        newEntry.frequency = frequency;

        heap->size++;
        heap->heap[heap->size] = newEntry;

        adjustHeap(heap, heap->size);
    } else if (shouldInsert(heap, frequency)) {
        free(heap->heap[1].word);
        heap->heap[1].word = strdup(word);
        heap->heap[1].frequency = frequency;

        adjustHeap(heap, 1);
    }
}

bool shouldInsert(Heap* heap, int frequency) {
    return frequency > heap->heap[1].frequency;
}

void adjustHeap(Heap* heap, int index) {
    int parent = index / 2;
    int leftChild = index * 2;
    int rightChild = leftChild + 1;
    int smallest = index;

    if (leftChild <= heap->size && heap->heap[leftChild].frequency < heap->heap[smallest].frequency) {
        smallest = leftChild;
    }
    if (rightChild <= heap->size && heap->heap[rightChild].frequency < heap->heap[smallest].frequency) {
        smallest = rightChild;
    }

    if (smallest != index) {
        WordFrequency temp = heap->heap[index];
        heap->heap[index] = heap->heap[smallest];
        heap->heap[smallest] = temp;
        adjustHeap(heap, smallest);
    }
}

void printHeap(Heap* heap) {
     // Cria uma cópia do heap para não modificar a estrutura original
    Heap* heapCopy = createHeap(heap->capacity);
    for (int i = 1; i <= heap->size; i++) {
        heapCopy->heap[i] = heap->heap[i];
    }
    heapCopy->size = heap->size;

    // Converte o heap em um heap mínimo (min-heap)
    for (int i = heapCopy->size / 2; i >= 1; i--) {
        adjustHeap(heapCopy, i);
    }

    // Imprime as palavras mais frequentes em ordem crescente
    while (heapCopy->size > 0) {
        printf("%s: %d\n", heapCopy->heap[1].word, heapCopy->heap[1].frequency);
        // Remove o elemento de maior prioridade do heap (raiz)
        heapCopy->heap[1] = heapCopy->heap[heapCopy->size];
        heapCopy->size--;
        adjustHeap(heapCopy, 1); // Reajusta o heap após a remoção
    }

    // Libera a memória do heap copiado
    destroyHeap(heapCopy); 
}

void printHeapUnsorted(Heap* heap, std::ofstream &print) {
    for (int i = 1; i <= heap->size; i++) {
        print<<heap->heap[i].word<<":"<<heap->heap[i].frequency<<endl;
    }
}
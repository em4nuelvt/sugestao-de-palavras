#include "huffman.hpp"
#include <queue>

bool compareNodes(HuffmanNode* a, HuffmanNode* b) {
    return a->frequency > b->frequency; // Min-heap com base nas frequências
}

HuffmanNode* buildHuffmanTree(Heap* heap) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, decltype(&compareNodes)> minHeap(compareNodes);

    // Preencher o min-heap com os nós iniciais (um para cada palavra e frequência)
    for (int i = 1; i <= heap->size; i++) {
        HuffmanNode* node = new HuffmanNode;
        node->word = strdup(heap->heap[i].word);
        node->frequency = heap->heap[i].frequency;
        node->left = nullptr;
        node->right = nullptr;
        minHeap.push(node);
    }

    // Construir a árvore de Huffman
    while (minHeap.size() > 1) {
        HuffmanNode* leftNode = minHeap.top();
        minHeap.pop();
        HuffmanNode* rightNode = minHeap.top();
        minHeap.pop();

        HuffmanNode* mergedNode = new HuffmanNode;
        mergedNode->word = nullptr; // Não é uma folha
        mergedNode->frequency = leftNode->frequency + rightNode->frequency;
        mergedNode->left = leftNode;
        mergedNode->right = rightNode;
        minHeap.push(mergedNode);
    }

    return minHeap.top(); // O nó raiz da árvore de Huffman
}

void printHuffmanTree(HuffmanNode* root, std::ofstream& print) {
    if (root == nullptr) {
        return;
    }
    printHuffmanTree(root->left, print);
    if (root->word != nullptr) {
        print<< root->word << ": " << root->frequency << endl;
    }

    
    printHuffmanTree(root->right, print);
}

void destroyHuffmanTree(HuffmanNode* root) {
    if (root == nullptr) {
        return;
    }

    destroyHuffmanTree(root->left);
    destroyHuffmanTree(root->right);
    free(root->word);
    delete root;
}

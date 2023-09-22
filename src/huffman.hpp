#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include "heap.hpp"
#include <fstream>

// Definição da estrutura do nó da árvore de Huffman
struct HuffmanNode {
    char* word; // Palavra
    int frequency; // Frequência
    HuffmanNode* left; // Filho esquerdo
    HuffmanNode* right; // Filho direito
};

// Função de comparação para uso no heap
bool compareNodes(HuffmanNode* a, HuffmanNode* b);

// Função para criar a árvore de Huffman
HuffmanNode* buildHuffmanTree(Heap* heap);

// Função para imprimir a árvore de Huffman
void printHuffmanTree(HuffmanNode* root, std::ofstream& print);

// Função para destruir a árvore de Huffman após o uso
void destroyHuffmanTree(HuffmanNode* root);

#endif // HUFFMAN_HPP

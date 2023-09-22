#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include <iostream>
#include "heap.hpp"
using namespace std;

typedef struct treeNode{
    int frequencia;
    string palavra;
    treeNode* esquerda;
    treeNode* direita;
}treeNode;

treeNode* inserir(treeNode* raiz, string palavra, int frequencia);
void imprimir(treeNode* raiz, std::ofstream &print);


#endif
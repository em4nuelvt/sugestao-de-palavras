#include "binaryTree.hpp"

treeNode* inserir(treeNode* raiz, string palavra, int frequencia) {
    if (raiz == NULL) {
        treeNode* aux = new treeNode;
        aux->palavra = palavra;
        aux->frequencia = frequencia;
        aux->direita = NULL;
        aux->esquerda = NULL;
        return aux;
    } else {
        if (frequencia < raiz->frequencia) {
            raiz->esquerda = inserir(raiz->esquerda, palavra, frequencia);
        } else {
            raiz->direita = inserir(raiz->direita, palavra, frequencia);
        }
        return raiz;
    }
}

void imprimir(treeNode* raiz, std::ofstream &print){
    if(raiz){
        imprimir(raiz->esquerda,print);
        print<<raiz->palavra<<": "<<raiz->frequencia<<endl;
        imprimir(raiz->direita,print);
    }

}
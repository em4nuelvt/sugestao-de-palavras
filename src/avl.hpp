#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include <fstream>
using namespace std;

typedef struct No{
    int frequencia;
    string palavra;
    No* esquerdo, *direito;
    short altura;
}No;

No* novoNo(string palavra, int frequencia );
short maior(short a, short b);
short alturaDoNo(No *no);
short fatorDeBalanceamento(No *no);
No* rotacaoEsquerda(No *r);
No* rotacaoDireita(No *r);
No* rotacaoEsquerdaDireita(No *r);
No* rotacaoDireitaEsquerda(No *r);
No* balancear(No *raiz);
No* inserirAVL(No *raiz, string palavra, int frequencia);
void imprimeEmOrdem(No* raiz, std::ofstream &print);
#endif
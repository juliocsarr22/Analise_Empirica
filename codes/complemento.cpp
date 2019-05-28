/**
 * @file complemento.cpp
 * @author Janeto Erick
 * @author Julio Cesar
 * @brief Funções auxiliares para o projeto
*/

#include <vector>
#include "complemento.h"

/**
 * @brief Função auxiliar para a busca fibonacci.
 * @param number        Número de compração.
*/
int fibonacci(int number){
    int a = 0, b = 1, c = 1;
    while(number > c){
        a = b;
        b = c;
        c = a + b;
    }
    return a;
}

/** 
 *@brief Função que gera um numero 2^n_sima
 * @param tam           refencia ao tamanho do vetor
 * @param n             define o tamanho do vetor em 2^n
*/
void tamanho(long int &tam, int n){
    for(int i(0); i < n; ++i){
        tam *= 2;
    }
}

/** 
 *@brief Função de busca ternária iterativa
 * @param V             referencia do vetor
 * @param first         posição inicial do vetor
 * @param last          posição final do vetor
*/
void preencher(std::vector <long int> &V, int first, int last){
    int size = last - first;

    for(int i(0); i < size; ++i){
        V[i] = i+1;
    }
}
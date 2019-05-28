/**
 * @file main.cpp
 * @author Janeto Erick
 * @author Julio Cesar
 * @brief Classe Main
*/

#include <vector>
#include "buscar.h"
#include "complemento.h"
#include "Test.cpp"

int main(){

    // Definindo um tamanho, que sera usado como tamanho do vetor, de valor inicial 1
    long int sizeArray(1);

    /*  definindo um tamanho maior para o sizeArray, em potencia de 2
        utilizando 2^29 como tamanho do vetor. (capacidade maxima da maquina de teste)
    */
    tamanho(sizeArray, 29);

    // Criando um Array e alocando o tamanho sizeArray
    std::vector <long int> V(sizeArray);

    // Preenchendo o vetor
    preencher(V, 0, sizeArray);

    // Chave de pesquisa
    int key = -1;

    // Fazendo a medicao do tempo de execucao
    contador(V, key, 0, sizeArray);

    return 0;
}
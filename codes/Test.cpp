/**
 * @file Test.cpp
 * @author Janeto Erick
 * @author Julio Cesar
*/

#include <iostream>
#include <chrono>
#include <vector>
#include "complemento.h"

void contador(std::vector<long int> &V, long int key, int first, int last);

/**
 * @brief Contador de tempo para rodar uma função
 * @param V         O Array que vai ser usado nos testes.
 * @param key       Número a ser procurado no Array.
 * @param first     Primeira posição do Array
 * @param last      Ultima posição do Array
*/
void contador(std::vector<long int> &V, long int key, int first, int last){
    int resultado(0); // pegar o resultado das funcoes

    // Pegando o tamanho do vetor
    int size = last - first;

    // variavel para definir qual algoritmo testar
    int funcao = 7;

    std::cout << "N:\t\t\tTempo:\n";
    // for para modificar o tamanho do vetor de teste
    for(auto i(32); i <= size; i *= 2){
        std::chrono::duration<double, std::milli> total(0);
        std::chrono::duration<double, std::milli> execucoes(0);

        // executar o codigo 100x, para pegar a media
        for(auto j(1); j <= 100; ++j){
            // pegando o tempo de execucao ate agora
            auto inicio = std::chrono::steady_clock::now();
            
            //verificar qual a funcao que deve ser executada
            switch(funcao){
                case 1:
                    resultado = buscaLinearIterativa(V, key, first, i);
                    break;
                case 2:
                    resultado = buscaBinariaIterativa(V, key, first, i);
                    break;
                case 3:
                    resultado = buscaBinariaRecursiva(V, (i + first)/2+1, first, i);
                    break;
                case 4:
                    resultado = buscaTernariaIterativa(V, key, first, i);
                    break;
                case 5:
                    resultado = buscaTernariaRecursiva(V, key, first, i);
                    break;
                case 6:
                    resultado = buscaJump(V, key, first, i);
                    break;
                case 7:
                    resultado = buscaFibonacci(V, i+1, first, i);
                    break;
            }
            // Pegando o tempo ate aqui
            auto fim = std::chrono::steady_clock::now();

            // Pegando apenas o tempo de execucao da funcao
            total = fim - inicio;

            // calculando a media ate o momento
            execucoes = execucoes + (total - execucoes)/static_cast<double>(j);
        }

        std::cout << i << "\t\t\t" << std::chrono::duration <double, std::milli> (execucoes).count() << " ms"<<std::endl;
    }
}
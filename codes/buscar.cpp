/**
 * @file buscar.cpp
 * @author Janeto Erick
 * @author Julio Cesar
 * @brief Classes de busca 
*/

#include <vector>
#include <math.h> 
#include "buscar.h"
#include "complemento.cpp"

/**
 * @brief Função de busca linear iterativa.
 * @param V         O Array que vai ser usado nos testes.
 * @param key       Número a ser procurado no Array.
 * @param first     Primeira posição do Array.
 * @param last      Ultima posição do Array.
*/
int buscaLinearIterativa(std::vector <long int> &V, int key, int first, int last){
    int size = last - first;

    for(int i(first); i < size; ++i){
        if(V[i] == key)
            return 1;
    }
    return -1;
}


/**
 * @brief Função de busca binária iterativa.
 * @param V         O Array que vai ser usado nos testes.
 * @param key       Número a ser procurado no Array.
 * @param first     Primeira posição do Array.
 * @param last      Ultima posição do Array.
*/
int buscaBinariaIterativa(std::vector <long int> &V, int key, int first, int last){
    int med = 0;
    while(first < last){
        med = (last + first)/2;
        if(V[med] == key)
            return 1;
        else if (V[med] < key)
            first = med + 1;
        else if(V[med] > key)
            last = med - 1;
    }
    // Caso nao haja o elemento, retorna -1
    return -1;
}

/**
 * @brief Função de busca binária recursiva.
 * @param V         O Array que vai ser usado nos testes.
 * @param key       Número a ser procurado no Array.
 * @param first     Primeira posição do Array.
 * @param last      Ultima posição do Array.
*/
int buscaBinariaRecursiva(std::vector <long int> &V, int key, int first, int last){
    
    int med = (last + first)/2;
    
    if(first >= last)
        return -1;
    else if(V[med] == key)
        return 1;
    else if(V[med] < key)
        return buscaBinariaRecursiva(V, key, med+1, last);
    else if(V[med] > key)
        return buscaBinariaRecursiva(V, key, first, med-1);
}

/**
 * @brief Função de busca ternária iterativa.
 * @param V         O Array que vai ser usado nos testes.
 * @param key       Número a ser procurado no Array.
 * @param first     Primeira posição do Array.
 * @param last      Ultima posição do Array.
*/
int buscaTernariaIterativa(std::vector <long int> &V, int key, int first, int last){

	int t1, t2;
	while (first < last){
		t1 = first + (last-first)/3;
		t2 = last - (last-first)/3;		
        
		if(V[t1] == key || V[t2] == key)
			return 1;

		if(key < V[t1])
			last = t1 - 1;
		else if(key > V[t2])
			first = t2 + 1;
		else if(key > V[t1] && key < V[t2]){
			last = t2-1;
			first = t1+1;
		}
	}
	return -1;
}

/** 
 *@brief Função de busca ternária recursiva.
 * @param V         O Array que vai ser usado nos testes.
 * @param key       Número a ser procurado no Array.
 * @param first     Primeira posição do Array.
 * @param last      Ultima posição do Array.
*/
int buscaTernariaRecursiva(std::vector <long int> &V, int key, int first, int last){
	int t1 = first + (last-first)/3;
	int t2 = last - (last-first)/3;
	if(first >= last)
		return -1;

	if(V[t1] == key || V[t2] == key)
		return 1;

	if(key < V[t1])
		return buscaTernariaRecursiva(V, key, first, t1-1);
	else if(key > V[t2])
		return buscaTernariaRecursiva(V, key, t2+1, last);
	else
		return buscaTernariaRecursiva(V, key, t1+1, t2-1);
}

/**
 * @brief Função de busca "Jump".
 * @param V         O Array que vai ser usado nos testes.
 * @param key       Número a ser procurado no Array.
 * @param first     Primeira posição do Array.
 * @param last      Ultima posição do Array.
*/
int buscaJump(std::vector <long int> &V, int key, int first, int last){
    int jump = sqrt(last - first);
    int count = 1;
    while(first < last){
        if(V[count*jump] == key)
            return 1;
        else if(V[count*jump] > key)
            return buscaLinearIterativa(V, key, first, (count*jump));
        else{
            first = count*jump + 1;
            count++;
        }
    }
    return -1;
}

/**
 * @brief Função de busca fibonacci.
 * @param V         O Array que vai ser usado nos testes.
 * @param key       Número a ser procurado no Array.
 * @param first     Primeira posição do Array.
 * @param last      Ultima posição do Array.
*/
int buscaFibonacci(std::vector <long int> &V, int key, int first, int last){
    int med = 0;
    while(first <= last){
        med = first + fibonacci(last-first); // Funcao criada para pegar o numero na sequencia de fibonacci necessario para a funcao
        if(V[med] == key)
            return 1;
        else if(V[med] < key)
            first = med + 1;
        else
            last = med - 1;
    }   
    return -1;
}



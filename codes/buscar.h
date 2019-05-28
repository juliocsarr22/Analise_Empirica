/**
 * @file buscar.h
 * @author Janeto Erick
 * @author Julio Cesar
 * @brief Definindo as funções de busca 
*/

#ifndef __SEARCH_H__
#define __SEARCH_H__

    int buscaLinearIterativa(std::vector <long int> &V, int key, int first, int last);
    int buscaBinariaIterativa(std::vector <long int> &V, int key, int first, int last);
    int buscaBinariaRecursiva(std::vector <long int> &V, int key, int first, int last);    
    int buscaTernariaIterariva(std::vector <long int> &V, int key, int first, int last);        
    int buscaTernariaRecursiva(std::vector <long int> &V, int key, int first, int last);        
    int buscaJump(std::vector <long int> &V, int key, int first, int last);        

#endif    
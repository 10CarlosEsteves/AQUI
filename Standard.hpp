#ifndef STANDARD_HPP
#define STANDARD_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../Produto/Produto.hpp"

using namespace std;

//Esta função carrega um vetor através de uma rquivo txt informado no argumento.
vector<Produto> Carregar(string arquivoLocal);

//Estas funções adicionam um objeto do tipo produto ao vector
//de objetos.
void Adicione(vector<Produto> &esteVetor, Produto novoProduto);
void Adicione(vector<Produto> &esteVetor, string nome, string descricao, float preco, int quantidade);

//Esta função encarrega-se de remover um produto 
//em uma posição específicada do vector.
void Remova(vector<Produto>& esteVetor, int pos);

//Esta função destina-se a atualizar valores presentes
//no vector.
void Atualize(vector<Produto> &esteVetor, int pos, Produto novoProduto);
void Atualize(vector<Produto> &esteVetor, int pos, string nome, string descricao, float preco, int quantidade);

//Esta função destina-se a printar o vector.
void PrintVector(vector<Produto> &esteVetor);

//Função Heapify do HeapSort1.
void Heapify1(vector<Produto>& arr, int n, int i);

// Função principal para fazer a ordenação HeapSort em ordem crescente.
void HeapSort1(vector<Produto>& arr);

//Função Heapify do HeapSort2.
void Heapify2(vector<Produto>& arr, int n, int i);

// Função principal para fazer a ordenação HeapSort em ordem decrescente.
void HeapSort2(vector<Produto>& arr);


//BubbleSort Modificado para ordenar os
//nomes em ordem alfabetica crescente.
void Bubblesort1(vector<Produto>& arr);

//BubbleSort Modificado para ordenar os
//nomes em ordem alfabetica crescente.
void Bubblesort2(vector<Produto>& arr);

//Algoritmo de busca binária com nomes inseridos e um vector de produtos ordenados.
int BuscaBinaria(vector<Produto>& arr, string busca);

#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Standard.hpp"
#include "../Produto/Produto.hpp"

using namespace std;

vector<Produto> Carregar(string arquivoLocal) {
    vector<Produto> carga;
    
    Produto produtoNovo;
    string nome;
    string descricao;
    float preco;
    int quantidade;

    ifstream leitura;
    leitura.open(arquivoLocal);
    
    // Se o arquivo conseguiu abrir, recupere as informações.
    if (!leitura.fail()) {
        while (getline(leitura, nome) && getline(leitura, descricao)) {
            leitura >> preco;
            leitura >> quantidade;
            leitura.ignore(); // Descartar o caractere de nova linha
            
            produtoNovo = Produto(nome, descricao, preco, quantidade);
            Adicione(carga, produtoNovo);
        }    
    }
    else {
        cout << "FALHA AO CARREGAR, O ARQUIVO ESTA CORROMPIDO OU NAO EXISTE" << endl;
    }

    leitura.close();
    return carga;
}


void Adicione(vector<Produto> &esteVetor, Produto novoProduto){
	esteVetor.push_back(novoProduto);
}


void Adicione(vector<Produto> &esteVetor, string nome, string descricao, float preco, int quantidade){
	Produto novoProduto(nome, descricao, preco, quantidade);
	esteVetor.push_back(novoProduto);
}


void Remova(vector<Produto>& esteVetor, int pos){
	
	//Se estiver vazio, não faça nada
	if(esteVetor.empty()){
		cout<<"ERROR: A tabela de produtos esta vazia!"<<endl;
	}
	
	//Se a posição for maior que o tamanho do vetor,
	//você especificou fora do intervalo permitido.
	//Alerte o usuário
	else if(pos >= esteVetor.size()){
		cout<<"ERROR: Posicao fora do intervalo permitido!"<<endl;
	}
	
	//Se o indice for negativo, informe o usuário do erro.
	else if(pos < 0){
		cout<<"ERROR: Insira um indice valido!"<<endl;
	}
	
	//Se o indice for 0, remova do início.
	else if(pos == 0){
		esteVetor.erase(esteVetor.begin());
	}
	
	//Se o indice especificado for o do último elemento, remova do final.
	else if(pos == esteVetor.size() - 1){
		esteVetor.erase(esteVetor.end());
	}
	//Se tudo falhar, isto significa que o objeto está no meio do vector.
	else{
		esteVetor.erase(esteVetor.begin() + pos);
	}

}


void Atualize(vector<Produto> &esteVetor, int pos, Produto novoProduto){
	
	//Se o vetor estiver vazio, acrescente
	//o novoProduto no vetor.
	if(esteVetor.empty()){
		esteVetor.push_back(novoProduto);
	}
	
	//Se a posição for maior que o tamanho do vetor,
	//você especificou fora do intervalo permitido.
	//Alerte o usuário
	else if(pos >= esteVetor.size()){
		cout<<"ERROR: Posicao fora do intervalo permitido!"<<endl;
	}
	
	//Se o indice for negativo, informe o usuário do erro.
	else if(pos < 0){
		cout<<"ERROR: Insira um indice valido!"<<endl;
	}
	
	//Se o indice for 0, remova do início.
	else if(pos == 0){
		esteVetor.at(pos) = novoProduto;
	}
	
	//Se o indice especificado for o do último elemento, remova do final.
	else if(pos == esteVetor.size() - 1){
        esteVetor.at(pos) = novoProduto;
	}
	//Se tudo falhar, isto significa que o objeto está no meio do vector.
	else{
		esteVetor.at(pos) = novoProduto;
	}
}


void Atualize(vector<Produto> &esteVetor, int pos, string nome, string descricao, float preco, int quantidade){
	
	Produto novoProduto(nome, descricao, preco, quantidade);
	Atualize(esteVetor,pos, novoProduto);
	
}



void PrintVector(vector<Produto> &esteVetor) {
    cout << "______________________________________________" << endl;
    cout << "                                              " <<endl;
    cout << "        TABELA DE PRODUTOS CADASTRADOS        " << endl;
    cout << "______________________________________________" << endl;
    cout << "TAMANHO TOTAL: " << esteVetor.size() << endl;

    if (!esteVetor.empty()) {
        cout << "PRIMEIRO PRODUTO: " << esteVetor.front().getNome() << endl;
        cout << "ULTIMO PRODUTO: " << esteVetor.back().getNome() << endl;
        cout << "______________________________________________" << endl;

        for (int pos = 0; pos < esteVetor.size(); pos++) {
            cout << "==============================================" << endl;
            cout << "                  PRODUTO " << pos << endl;
            esteVetor[pos].Print();
        }
    }

    cout << "______________________________________________" << endl;
}


void Heapify1(vector<Produto>& arr, int n, int i){
	
    int maior = i; //Inicializa o maior como a raiz. Desde que usemos indexação baseada em 0.
    int esquerda = 2 * i + 1; // esquerda = 2*i + 1
    int direita = 2 * i + 2; // direita = 2*i + 2
 
 	//Se o nó da esquerda é maior que o da raiz.
    if (esquerda < n && arr[esquerda].getPreco() > arr[maior].getPreco())
        maior = esquerda;
 
 	//Se o nó da direita é o maior que maior atual.
    if (direita < n && arr[direita].getPreco() > arr[maior].getPreco())
        maior = direita;
 
	//Se o maior não for a raiz
    if (maior != i) {
        swap(arr[i], arr[maior]);
 
 		//Recursivamente, heapifique a sub-arvore afetada.
        Heapify1(arr, n, maior);
    }
}


void HeapSort1(vector<Produto>& arr){

	int n = arr.size();

    //Construa o heap (reorganize o vetor).
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify1(arr, n, i);
 	
 	//Um por um, extraia um elemento do heap.
    for (int i = n - 1; i >= 0; i--) {
        //Mova a raiz atual para o fim.
        swap(arr[0], arr[i]);
 		//Chame maximo heapify no heap reduzido.
        Heapify1(arr, i, 0);
    }
}


void Heapify2(vector<Produto>& arr, int n, int i){
	
    int maior = i; //Inicializa o maior como a raiz. Desde que usemos indexação baseada em 0.
    int esquerda = 2 * i + 1; // esquerda = 2*i + 1
    int direita = 2 * i + 2; // direita = 2*i + 2
 
 	//Se o nó da esquerda é maior que o da raiz.
    if (esquerda < n && arr[esquerda].getPreco() < arr[maior].getPreco())
        maior = esquerda;
 
 	//Se o nó da direita é o maior que maior atual.
    if (direita < n && arr[direita].getPreco() < arr[maior].getPreco())
        maior = direita;
 
	//Se o maior não for a raiz
    if (maior != i) {
        swap(arr[i], arr[maior]);
 
 		//Recursivamente, heapifique a sub-arvore afetada.
        Heapify2(arr, n, maior);
    }
}


void HeapSort2(vector<Produto>& arr){
	int n = arr.size();
    //Construa o heap (reorganize o vetor).
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify2(arr, n, i);
 	
 	//Um por um, extraia um elemento do heap.
    for (int i = n - 1; i >= 0; i--) {
        //Mova a raiz atual para o fim.
        swap(arr[0], arr[i]);
 		//Chame maximo heapify no heap reduzido.
        Heapify2(arr, i, 0);
    }
}


void Bubblesort1(vector<Produto>& arr) {
    int size = arr.size();
    bool sorted = false;

    while (!sorted) {
        sorted = true;

        for (int atual = 0; atual < size - 1; atual++) {
            if (arr[atual].getNome().compare(arr[atual + 1].getNome()) > 0) {
                swap(arr[atual], arr[atual + 1]);
                sorted = false;
            }
        }
        size--;
    }
}


void Bubblesort2(vector<Produto>& arr) {
    int size = arr.size();
    bool sorted = false;

    while (!sorted) {
        sorted = true;

        for (int atual = 0; atual < size - 1; atual++) {
            if (arr[atual].getNome().compare(arr[atual + 1].getNome()) < 0) {
                swap(arr[atual], arr[atual + 1]);
                sorted = false;
            }
        }
        size--;
    }
}


int BuscaBinaria(vector<Produto>& arr, string busca) {
        
        int inicio = 0;
        int fim = arr.size() - 1;

        while (inicio <= fim) {
            int meio = (fim + inicio) / 2;
            int comparacao = busca.compare(arr[meio].getNome());

            if (comparacao == 0) {
                return meio;
            }

            if (comparacao < 0) {
                fim = meio - 1;
            } else {
                inicio = meio + 1;
            }
        }
        return -1;
}

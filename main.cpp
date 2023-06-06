#include <iostream>
#include <stdlib.h>
#include <vector>

#include "Produto/Produto.hpp"
#include "Standard/Standard.hpp"

using namespace std;

int main() {
	system("color 0A");
	
	vector <Produto> vetor = Carregar("Carga de Produtos.txt");

	Bubblesort2(vetor);
	PrintVector(vetor);

	
	
	
	return 0;
}
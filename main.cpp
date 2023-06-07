#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <fstream>


#include "Produto/Produto.hpp"
#include "Standard/Standard.hpp"

using namespace std;

int main() {
	system("color 06");
	int escolha;
	
	string nome;
	string descricao;
   	float  preco;
    int quantidade;
    string nomeArquivo;
    ifstream inputFile;
	
	int posicao;
	
	vector <Produto> Produtos = Carregar("Carga de Produtos.txt");
	
	while(true){
		system("cls");
		
		cout << "______________________________________________________________________________________"<<endl;
		cout << "                             TERMINAL CONTROLE DE ESTOQUE LTDA                        "<<endl;
		cout << "______________________________________________________________________________________"<<endl;
		cout << "                                      MENU PRINCIPAL                                  "<<endl;
		cout << "______________________________________________________________________________________"<<endl;
		cout << "                                                                                      "<<endl;
	    cout << "                           [1] ADICIONAR UM PRODUTO A LISTA                           "<<endl;
	    cout << "                           [2] ATUALIZAR UM PRODUTO DA LISTA                          "<<endl;
	    cout << "                           [3] REMOVER UM PRODUTO DA LISTA                            "<<endl;
	    cout << "                           [4] BUSCAR POR UM PRODUTO                                  "<<endl;
	    cout << "                           [5] VISUALIZAR OS PRODUTOS                                 "<<endl;
	    cout << "                           [6] IMPORTAR CARGA DE DADOS (txt somente)                  "<<endl;
	    cout << "                           [7] SAIR                                                   "<<endl;
	    cout << "______________________________________________________________________________________"<<endl;
	    cout << "                           COMANDO>> ";
	    escolha = getch();
	    
	    switch (escolha){
	        
			
	        
	        //Chaveamento para adicionar um novo produto a lista.
			case 49:
				system("cls");
	        	cout << "______________________________________________________________________________________"<<endl;
	        	fflush(stdin);
	        	cout << "Insira o nome do novo produto: ";
	        	getline(cin, nome);
	        	cout << "Insira a descricao do novo produto: ";
	        	getline(cin, descricao);
	        	fflush(stdin);
	        	cout << "Insira o valor do novo produto: ";
	        	cin >> preco;
	        	cout << "Insira a quantidade do novo produto: ";
	        	cin >> quantidade;
				Adicione(Produtos, nome, descricao, preco, quantidade);
				cout << "______________________________________________________________________________________"<<endl;
	        	cout << "                         SUCESSO AO ADICIONAR O PRODUTO A LISTA!                      "<<endl;
	        	break;
	        
	        //Chaveamento para atualizar um produto da lista.
	        case 50:
	        	system("cls");
	        	cout <<"______________________________________________________________________________________"<<endl;
	        	cout <<"Por favor, informe o nome do produto para atualizarmos: ";
	        	cin  >>nome;
	        	
	        	nome[0] = toupper(nome[0]);
	        	
	        	Bubblesort1(Produtos);
	        	posicao = BuscaBinaria(Produtos, nome);
	        	
	        	if(posicao == -1){
	        		cout<<"ERROR: Produto nao encontrado!"<<endl;
				}
				
				else{
					cout << "______________________________________________________________________________________"<<endl;
					cout << "                       PRODUTO "<<nome<<" ENCONTRADO COM SUCESSO!                     "<<endl;
					cout << "______________________________________________________________________________________\n"<<endl;
					Produtos[posicao].Print();
					cout<<"\n";
					cout << "______________________________________________________________________________________"<<endl;
					cout << "                            DESEJA ALTERAR ESTE PRODUTO?                              "<<endl;
					cout << "                                 [1] SIM [2] NAO                                      "<<endl;
					cout<<">> ";
					cin>>escolha;
					
					if(escolha == 1){
						cout << "______________________________________________________________________________________"<<endl;
		        		fflush(stdin);
						cout << "Insira o nome atualizado do produto: ";
		        		getline(cin, nome);
		        		cout << "Insira a descricao atualizada do produto: ";
			        	getline(cin, descricao);
			        	fflush(stdin);
			        	cout << "Insira o valor atualizado do produto: ";
			        	cin >> preco;
			        	cout << "Insira a quantidade atualizada do produto: ";
			        	cin >> quantidade;
			        	Atualize(Produtos, posicao, nome, descricao, preco, quantidade);
			        	cout << "______________________________________________________________________________________"<<endl;
	        			cout << "                         SUCESSO AO ATUALIZAR O PRODUTO NA LISTA!                     "<<endl;
					}
				}
	        	
	        	break;
	        
	        //Chaveamento para remover um produto da lista.
	        case 51:
	        	system("cls");
	        	cout <<"______________________________________________________________________________________"<<endl;
	        	cout <<"Por favor, informe o nome do produto a ser removido: ";
	        	cin  >>nome;
	        	
	        	nome[0] = toupper(nome[0]);
	        	
	        	Bubblesort1(Produtos);
	        	posicao = BuscaBinaria(Produtos, nome);
	        	
	        	if(posicao == -1){
	        		cout<<"\nERROR: Produto nao encontrado!\n"<<endl;
				}
				
				else{
					cout << "______________________________________________________________________________________"<<endl;
					cout << "                       PRODUTO "<<nome<<" ENCONTRADO COM SUCESSO!                     "<<endl;
					cout << "______________________________________________________________________________________\n"<<endl;
					Produtos[posicao].Print();
					cout<<"\n";
					cout << "______________________________________________________________________________________"<<endl;
					cout << "                            DESEJA REMOVER ESTE PRODUTO?                              "<<endl;
					cout << "                                 [1] SIM [2] NAO                                      "<<endl;
					cout<<">> ";
					cin>>escolha;
					
					if(escolha == 1){
						Remova(Produtos, posicao);
			        	cout << "______________________________________________________________________________________"<<endl;
	        			cout << "                         SUCESSO AO REMOVER O PRODUTO DA LISTA!                       "<<endl;
					}
				}

	        	
				break;
			
			//Chaveamento para pesquisar/buscar um produto da lista.					
	        case 52:
	        	system("cls");
	        	cout <<"______________________________________________________________________________________"<<endl;
	        	cout <<"Informe o nome do produto que deseja buscar: ";
	        	cin  >>nome;
	        	
	        	nome[0] = toupper(nome[0]);
	        	
	        	Bubblesort1(Produtos);
	        	posicao = BuscaBinaria(Produtos, nome);
	        	
	        	if(posicao == -1){
	        		cout<<"\nERROR: Produto nao encontrado!\n"<<endl;
				}
				
				else{
					cout << "______________________________________________________________________________________"<<endl;
					cout << "                       PRODUTO "<<nome<<" ENCONTRADO COM SUCESSO!                     "<<endl;
					cout << "______________________________________________________________________________________\n"<<endl;
					Produtos[posicao].Print();
					cout << "______________________________________________________________________________________"<<endl;
				}
			break;	
	        
	        //Chaveamento para visualizar a lista de produtos.
	        case 53:
	        	system("cls");
	        	cout <<"______________________________________________________________________________________"<<endl;
	        	cout << "                ESCOLHA UM MODO DE VISUALIZACAO DA LISTA DE PRODUTOS                 "<<endl;
				cout <<"______________________________________________________________________________________"<<endl;
	        	cout << "                       [1] POR ORDEM CRESCENTE DE NOME                               "<<endl;
	        	cout << "                       [2] POR ORDEM DECRESCENTE DE NOME                             "<<endl;
	        	cout << "                       [3] POR ORDEM CRESCENTE DE PRECO                              "<<endl;
	        	cout << "                       [4] POR ORDEM DECRESCENTE DE PRECO                            "<<endl;
	        	cout <<"______________________________________________________________________________________"<<endl;
	        	cout << "                       COMANDO>> ";
	    		escolha = getch();
	        	
				system("cls");
	        	
				switch (escolha){
	        		case 49: 
	        			Bubblesort1(Produtos);
	        			PrintVector(Produtos);
	        		break;
	        		
	        		case 50:
	        			Bubblesort2(Produtos);
	        			PrintVector(Produtos);
					break;	
					
					case 51:
	        			HeapSort1(Produtos);
	        			PrintVector(Produtos);
					break;
					
					case 52:
	        			HeapSort2(Produtos);
	        			PrintVector(Produtos);
					break;
					
					default:
						cout<<"COMANDO INVALIDO!"<<endl;
				}
			break;
	        
			//Importar carga de dados	
			case 54:
				cout << "Digite o nome do arquivo que deseja abrir: ";
	        	getline(cin, nomeArquivo);

				Produtos = Carregar(nomeArquivo);
		        break;
	        	
	        case 55:
	        cout<<"\n\n                           PROGRAMA FINALIZADO!"<<endl;
	        return 0;
	        break;
				
		}
	
		system("pause");
	}
	
	
	return 0;

}

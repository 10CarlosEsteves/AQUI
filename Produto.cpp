#include <iostream>
#include  <string>

#include "Produto.hpp"


using namespace std;

//Implementações dos Métodos Getters
string Produto::getNome() const{
    return nome;
}

string Produto::getDescricao() const{
    return descricao;
}

float Produto::getPreco() const{
    return preco;
}

int Produto::getQuantidade() const{
    return quantidade;
}


//Implementações dos Métodos Setters
void Produto::setNome(string nom){
    nome = nom;
}

void Produto::setDescricao(string descri){
    descricao = descri;
}

void Produto::setPreco(float prec){
    preco = prec;
}

void Produto::setQuantidade(int quant){
	quantidade = quant;
}




//Implementações dos Métodos Construtores

Produto::Produto(){
    setNome("Nao Definido");
    setDescricao("Nao Definido");
    setPreco(0.0);
	setQuantidade(0);
}

Produto::Produto(string nom, string descri, float prec, int quant){
    setNome(nom);
    setDescricao(descri);
    setPreco(prec);
	setQuantidade(quant);	
}


//Funções ordinárias
void Produto::Print(){
    cout<<"NOME: "<<getNome()<<endl;
    cout<<"DESCRICAO: "<<getDescricao()<<endl;
    cout<<"PRECO: "<<getPreco()<<endl;
    cout<<"QUANTIDADE: "<<getQuantidade()<<endl;

}
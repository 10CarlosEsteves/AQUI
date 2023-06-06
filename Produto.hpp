#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <iostream>

using namespace std;

class Produto{
    private:
        string nome;
        string descricao;
        float preco;
        int quantidade;

    public:
        //Métodos Getters
        string getNome() const;
        string getDescricao() const;
        float getPreco() const;
        int getQuantidade() const;


        //Métodos Setters
        void setNome(string nom);
        void setDescricao(string descri);
        void setPreco(float prec);
        void setQuantidade(int quant);


        //Construtores
        Produto();
        Produto(string nom, string descri, float prec, int quant);

        //Funções Debug
        void Print();

};

#endif
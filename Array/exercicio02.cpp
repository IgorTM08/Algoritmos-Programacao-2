#include <iostream>
#include <array>

using namespace std;

struct Produto{
    int codigo;
    string nome;
    double preco;
    int estoque;
};

void cadastrarProdutos(array<Produto, 5>& produtos);
void exibirProdutos(const array<Produto, 5>& produtos);
int buscarPorCodigo(const array<Produto, 5>& produtos, int code);
int contarEstoqueBaixo(const array<Produto, 5>& produtos, int lim);

int main(){

    array<Produto, 5> produtos{};
    int code = 0, lim = 0, retorno = 0;

    cadastrarProdutos(produtos);
    exibirProdutos(produtos);

    cout << "\nInsira um codigo de produto: ";
    cin >> code;
    retorno = buscarPorCodigo(produtos, code);

    if(retorno == -1) cout << "Produto nao encontrado!\n";
    else{
        cout << "\nCodigo: " << produtos[retorno].codigo;
        cout << "\nNome: " << produtos[retorno].nome;
        cout << "\nValor: " << produtos[retorno].preco;
        cout << "\nEstoque: " << produtos[retorno].estoque;
    }

    cout << "\nInforme um limite de estoque: ";
    cin >> lim;

    cout << "\nHa " << contarEstoqueBaixo(produtos, lim) << " produtos com estoque abaixo do valor informado.\n";

    return 0;
}

void cadastrarProdutos(array<Produto, 5>& produtos){
    for(int i = 0; i < produtos.size(); i++){
        cout << "Informe o codigo: ";
        cin >> produtos[i].codigo;

        while(produtos[i].codigo < 1){
            cout << "Codigo invalido! Insira um valor maior ou igual a 1: ";
            cin >> produtos[i].codigo;
        }

        cout << "Informe o nome: ";
        getline(cin >> ws, produtos[i].nome);
        cout << "Informe o valor: ";
        cin >> produtos[i].preco;

        while(produtos[i].preco < 1){
            cout << "Preco invalido! Insira um valor maior que 0: ";
            cin >> produtos[i].preco;
        }

        cout << "Informe o estoque: ";
        cin >> produtos[i].estoque;
    }
}

void exibirProdutos(const array<Produto, 5>& produtos){
    for(int i = 0; i < produtos.size(); i++){
        cout << "\n\n==Produto " << i+1 << "==";
        cout << "\nCodigo: " << produtos[i].codigo;
        cout << "\nNome: " << produtos[i].nome;
        cout << "\nValor: " << produtos[i].preco;
        cout << "\nEstoque: " << produtos[i].estoque;
    }
}

int buscarPorCodigo(const array<Produto, 5>& produtos, int code){
    for(int i = 0; i < produtos.size(); i++){
        if(code == produtos[i].codigo) return i;
    }
    return -1;
}

int contarEstoqueBaixo(const array<Produto, 5>& produtos, int lim){
    int cont = 0;
    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].estoque < lim){
            cont++;
        }
    }
    return cont;
}
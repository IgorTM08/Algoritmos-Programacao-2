#include <iostream>
#include <string>
using namespace std;

struct Produto {
    int codigo;
    string nome;
    double preco;
};

void imprimirProduto(const Produto& p);
void imprimirProdutos(const Produto produtos[5]);
double calcularMediaPrecos(const Produto produtos[5]);
int buscarProduto(const Produto produtos[5], int codigo);

int main(){

    Produto produtos[5];
    int codigo = 0, posicao = 0;

    for(int i = 0; i < 5; i++){
        cout << "Informe o codigo do produto " << i + 1 << ": ";
        cin >> produtos[i].codigo;
        
        cout << "Informe o nome do produto " << i + 1 << ": ";
        getline(cin >> ws, produtos[i].nome);
        
        cout << "Informe o preco do produto " << i + 1 << ": ";
        cin >> produtos[i].preco;
        cout << endl;
    }

    cout << "\n--- Lista de Produtos ---\n";
    imprimirProdutos(produtos);

    cout << "\nA media dos valores e: R$ " << calcularMediaPrecos(produtos) << endl;

    cout << "\nInsira o codigo de um produto para buscar: ";
    cin >> codigo;

    posicao = buscarProduto(produtos, codigo);

    if(posicao == -1){
        cout << "Produto nao encontrado!\n";
    } else {
        cout << "Produto encontrado: ";
        imprimirProduto(produtos[posicao]);
    }

    return 0;
}

void imprimirProduto(const Produto& p){
    cout << p.codigo << " | "
         << p.nome << " | R$ "
         << p.preco << endl; 
}

void imprimirProdutos(const Produto produtos[5]){
    for(int i = 0; i < 5; i++){
        cout << produtos[i].codigo << " | "
             << produtos[i].nome << " | R$ "
             << produtos[i].preco << endl;
    }
}

double calcularMediaPrecos(const Produto produtos[5]){
    double mediaValores = 0;
    for(int i = 0; i < 5; i++){
        mediaValores += produtos[i].preco;
    }
    return mediaValores / 5.0;
}

int buscarProduto(const Produto produtos[5], int codigo){
    for(int i = 0; i < 5; i++){
        if(codigo == produtos[i].codigo){
            return i;
        }
    }
    return -1;
}
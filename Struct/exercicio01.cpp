#include <iostream>
using namespace std;

struct Produto {
    int codigo;
    string nome;
    float preco;
    int quantidade;
};

void imprimirProduto(const Produto& produto);
double calcularValorEstoque(const Produto& produto);
void adicionarEstoque(Produto& produto, int qtd);
bool removerEstoque(Produto& produto, int qtd);

int main(){

    int qtd = 0, opc = 0;
    Produto produto;

    produto.codigo = 1;
    produto.nome = "Cafe";
    produto.preco = 6.50;
    produto.quantidade = 20;

    do{
    
        imprimirProduto(produto);

        cout << "\n1. Calcular valor em estoque" << endl
             << "2. Adicionar ao estoque" << endl
             << "3. Remover do estoque" << endl
             << "4. Sair" << endl
             << "Opcao: ";

        cin >> opc;

        switch(opc){
            case 1:
                cout << "Valor total em estoque: R$ " << calcularValorEstoque(produto) << endl;
                break;
            
            case 2:
                cout << "Quantos produtos deseja adicionar ao estoque? ";
                cin >> qtd;

                if (qtd > 0) {
                    adicionarEstoque(produto, qtd);
                    cout << "Estoque atualizado com sucesso!" << endl;
                } else {
                    cout << "Quantidade invalida!" << endl;
                }
                break;

            case 3:
                if(produto.quantidade <= 0){
                    cout << "Nao ha produto em estoque." << endl;
                } else {
                    cout << "Quantos produtos deseja retirar do estoque? ";
                    cin >> qtd;

                    if (removerEstoque(produto, qtd)) {
                        cout << "Produtos removidos com sucesso!" << endl;
                    } else {
                        cout << "Nao foi possivel remover os produtos." << endl;
                    }
                }
                break;

            case 4:
                cout << "Sessao encerrada." << endl;
                break;

            default:
                cout << "Opcao invalida, tente novamente." << endl;
                break;
        }

    }while(opc != 4);

    return 0;
}

void imprimirProduto(const Produto& produto){
    cout << endl << produto.codigo << ". " << produto.nome
         << " | R$ " << produto.preco << " | Estoque: " << produto.quantidade << endl;
}

double calcularValorEstoque(const Produto& produto){
    return produto.quantidade * produto.preco;
}

void adicionarEstoque(Produto& produto, int qtd){
    produto.quantidade += qtd;
}

bool removerEstoque(Produto& produto, int qtd) {
    if (qtd <= 0) return false;
    if (qtd > produto.quantidade) return false;

    produto.quantidade -= qtd;
    return true;
}
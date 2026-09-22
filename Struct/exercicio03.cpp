#include <iostream>
#include <string>
using namespace std;

struct Livro {
    int codigo;
    string titulo;
    string autor;
    int ano;
    bool disponivel;
};

void cadastrarLivro(Livro (&estante)[10]);
bool removerLivro(Livro (&estante)[10], int posicao);
void exibirLivro(const Livro (&estante)[10], int posicao);
void exibirLivros(const Livro (&estante)[10]);
int buscarLivro(const Livro (&estante)[10], int codigoLido);
bool emprestarLivro(Livro (&estante)[10], int posicao);
bool devolverLivro(Livro (&estante)[10], int posicao);
int totalDisponiveis(const Livro (&estante)[10]);

int main(){

    Livro estante[10];
    int esc = 0;

    for(int i = 0; i < 10; i++){
        estante[i].codigo = -1;
    }

    do{

        int posicao = 0, codigoLido = 0;

        cout << "\n1 - Cadastrar livro\n"
             << "2 - Remover livro\n"
             << "3 - Exibir livros\n"
             << "4 - Exibir livro por codigo\n"
             << "5 - Emprestar livro\n"
             << "6 - Devolver livro\n"
             << "7 - Total de livros disponiveis\n"
             << "0 - Sair\n\nOpcao: ";

        cin >> esc;
        
        switch(esc){
            case 1:
                cadastrarLivro(estante);
                break;
            
            case 2:
                cout << "Digite o codigo do livro para remover: ";
                cin >> codigoLido;
                
                posicao = buscarLivro(estante, codigoLido);

                if(posicao == -1){
                    cout << "Livro nao encontrado!\n";
                }else{
                    removerLivro(estante, posicao);
                    cout << "Livro removido com sucesso!\n";
                }
                break;

            case 3:
                exibirLivros(estante);
                break;
            
            case 4:
                cout << "Digite o codigo do livro: ";
                cin >> codigoLido;

                posicao = buscarLivro(estante, codigoLido);

                if(posicao == -1){
                    cout << "Livro nao encontrado!\n";
                }else{
                    exibirLivro(estante, posicao);
                }
                break;

            case 5:
                cout << "Digite o codigo do livro que deseja emprestar: ";
                cin >> codigoLido;

                posicao = buscarLivro(estante, codigoLido);

                if(posicao == -1){
                    cout << "Livro nao encontrado!\n";
                }else if(estante[posicao].disponivel == false){
                    cout << "Livro indisponivel!\n";
                }else{
                    emprestarLivro(estante, posicao);
                    cout << "Livro emprestado com sucesso!\n";
                }
                break;

            case 6:
                cout << "Digite o codigo do livro que deseja devolver: ";
                cin >> codigoLido;

                posicao = buscarLivro(estante, codigoLido);

                if(posicao == -1){
                    cout << "Livro nao encontrado!\n";
                }else if(estante[posicao].disponivel == true){
                    cout << "Livro ja esta disponivel!\n";
                }else{
                    devolverLivro(estante, posicao);
                    cout << "Livro devolvido com sucesso!\n";
                }
                break;

            case 7:
                cout << "Total de livros disponiveis: " << totalDisponiveis(estante) << "\n";
                break;

            case 0:
                cout << "Saindo do programa...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }
    }while(esc != 0);

    return 0;
}

void cadastrarLivro(Livro (&estante)[10]){
    for(int i = 0; i < 10; i++){
        if(estante[i].codigo == -1){
            cout << "Digite o codigo do livro: ";
            cin >> estante[i].codigo;

            if(estante[i].codigo <= 0){
                cout << "Codigo invalido! Deve ser um numero positivo.\n";
                estante[i].codigo = -1;
                return;
            }

            cout << "Digite o titulo do livro: ";
            getline(cin >> ws, estante[i].titulo);
            cout << "Digite o autor do livro: ";
            getline(cin, estante[i].autor);
            cout << "Digite o ano do livro: ";
            cin >> estante[i].ano;
            estante[i].disponivel = true;
            cout << "Livro cadastrado com sucesso!\n";
            return;
        }
    }
    cout << "Estante cheia!\n";
}

bool removerLivro(Livro (&estante)[10], int posicao){
    estante[posicao].codigo = -1;
    estante[posicao].disponivel = false;
    return true;
}

void exibirLivro(const Livro (&estante)[10], int posicao){
    cout << "--------Estante " << posicao + 1 << "--------\n"
         << "Codigo: " << estante[posicao].codigo << "\n"
         << "Titulo: " << estante[posicao].titulo << "\n"
         << "Autor: " << estante[posicao].autor << "\n"
         << "Ano: " << estante[posicao].ano << "\n"
         << "Disponivel: " << (estante[posicao].disponivel ? "Sim" : "Nao") << "\n\n";
}

void exibirLivros(const Livro (&estante)[10]){
    bool encontrou = false;
    for(int i = 0; i < 10; i++){
        if(estante[i].codigo != -1){
            encontrou = true;
            cout << "\n--------Estante " << i + 1 << "--------\n"
                 << "Codigo: " << estante[i].codigo << "\n"
                 << "Titulo: " << estante[i].titulo << "\n"
                 << "Autor: " << estante[i].autor << "\n"
                 << "Ano: " << estante[i].ano << "\n"
                 << "Disponivel: " << (estante[i].disponivel ? "Sim" : "Nao") << "\n\n";
        }
    }
    if(!encontrou){
        cout << "\nNenhum livro cadastrado na estante.\n";
    }
}

int buscarLivro(const Livro (&estante)[10], int codigoLido){
    for(int i = 0; i < 10; i++){
        if(codigoLido != -1 && codigoLido == estante[i].codigo){
            return i;
        }
    }
    return -1;
}

bool emprestarLivro(Livro (&estante)[10], int posicao){
    estante[posicao].disponivel = false;
    return true;
}

bool devolverLivro(Livro (&estante)[10], int posicao){
    estante[posicao].disponivel = true;
    return true;
}

int totalDisponiveis(const Livro (&estante)[10]){
    int total = 0;

    for(int i = 0; i < 10; i++){
        if(estante[i].codigo != -1 && estante[i].disponivel){
            total++;
        }
    }
    return total;
}
#include <iostream>
using namespace std;

template <size_t M, size_t N>
void exibirEstacionamento(const int (&estacionamento)[M][N]);

template <size_t M, size_t N>
bool vagaValida(int vaga, const int (&estacionamento)[M][N]);

template <size_t M, size_t N>
void ocuparVaga(int (&estacionamento)[M][N], int vaga);

template <size_t M, size_t N>
void liberarVaga(int (&estacionamento)[M][N], int vaga);

template <size_t M, size_t N>
int contarVagasLivres(const int (&estacionamento)[M][N]);

template <size_t M, size_t N>
int contarVagasLivres(const int (&estacionamento)[M][N], int linha);

int main(){
 
    int estacionamento[4][5] = {}, opcao = 0, vaga = 0, linha = 0, coluna = 0;

    do{
    cout << "\n===== ESTACIONAMENTO =====\n"
         << "Escolha uma opção:\n"
         << "1. Exibir estacionamento\n"
         << "2. Ocupar vaga\n"
         << "3. Liberar vaga\n"
         << "4. Contar vagas livres\n"
         << "5. Contar vagas livres em uma linha específica\n"
         << "6. Sair\n";
    
    cin >> opcao;

        switch(opcao){
            case 1:
                exibirEstacionamento(estacionamento);
                break;

            case 2:
                vaga = 0;
                cout << "Digite o número da vaga que deseja ocupar (1 a 20): ";
                cin >> vaga;

                if(vagaValida(vaga, estacionamento)){

                    linha = (vaga - 1) / 5;
                    coluna = (vaga - 1) % 5;

                    if(estacionamento[linha][coluna] == 1){
                        cout << "Vaga já ocupada. Escolha outra vaga.\n";
                    } else {
                    ocuparVaga(estacionamento, vaga);
                    }
                } else { 
                    cout << "Vaga inválida. Escolha uma vaga entre 1 e 20.\n"; 
                }
                break;

            case 3:
                vaga = 0;
                cout << "Digite o número da vaga que deseja liberar (1 a 20): ";
                cin >> vaga;

                if(vagaValida(vaga, estacionamento)){

                    linha = (vaga - 1) / 5;
                    coluna = (vaga - 1) % 5;

                    if(estacionamento[linha][coluna] == 0){
                        cout << "Vaga já liberada. Escolha outra vaga.\n";
                    } else {
                    liberarVaga(estacionamento, vaga);
                    }
                } else { 
                    cout << "Vaga inválida. Escolha uma vaga entre 1 e 20.\n"; 
                }
                break;

            case 4:
                cout << "Número de vagas livres: " << contarVagasLivres(estacionamento);
                break;

            case 5:
                linha = 0;
                cout << "Digite o número da linha que deseja contar (1 a 4): ";
                cin >> linha;
                if(linha >= 1 and linha <= 4){
                    cout << "Número de vagas livres da linha " << linha << ": " << contarVagasLivres(estacionamento, linha - 1);
                } else {
                    cout << "Linha inválida. Escolha uma linha entre 1 e 4.\n";
                }
                break;

            case 6:
                cout << "Sessão encerrada.";
                return 0;

            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    } while(opcao != 6);
    
    return 0;
}

template <size_t M, size_t N>
void exibirEstacionamento(const int (&estacionamento)[M][N]){
    for(size_t i = 0; i < M; i++){
        for(size_t j = 0; j < N; j++){
            cout << estacionamento[i][j] << "\t";
        }
        cout << endl;
    }
}

template <size_t M, size_t N>
bool vagaValida(int vaga, const int (&estacionamento)[M][N]){
    return vaga >= 1 and vaga <= M*N;
}

template <size_t M, size_t N>
void ocuparVaga(int (&estacionamento)[M][N], int vaga){
        int linha = (vaga - 1) / 5;
        int coluna = (vaga - 1) % 5;
        estacionamento[linha][coluna] = 1;
}

template <size_t M, size_t N>
void liberarVaga(int (&estacionamento)[M][N], int vaga){
        int linha = (vaga - 1) / 5;
        int coluna = (vaga - 1) % 5;
        estacionamento[linha][coluna] = 0;
}

template <size_t M, size_t N>
int contarVagasLivres(const int (&estacionamento)[M][N]){
    int vagaLivre = 0;
    for(size_t i = 0; i < M; i++){
        for(size_t j = 0; j < N; j++){
            if(estacionamento[i][j] == 0) vagaLivre++;
        }
    }
    return vagaLivre;
}

template <size_t M, size_t N>
int contarVagasLivres(const int (&estacionamento)[M][N], int linha){
    int vagaLivre = 0;
        for(size_t j = 0; j < N; j++){
            if(estacionamento[linha][j] == 0) vagaLivre++;
        }
    return vagaLivre;
}
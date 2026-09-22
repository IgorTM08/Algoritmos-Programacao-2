#include <iostream>
#include <array>

using namespace std;

void preencherMatriz(array<array<int, 3>, 3>& matriz);
void exibirMatriz(const array<array<int, 3>, 3>& matriz);
int somarElementos(const array<array<int, 3>, 3>& matriz);
int maiorElemento(const array<array<int, 3>, 3>& matriz);
int somarLinha(const array<array<int, 3>, 3>& matriz, int linha);

int main(){

    array<array<int, 3>, 3> matriz{};
    int linha = 0;

    preencherMatriz(matriz);
    exibirMatriz(matriz);

    cout << "\nSoma dos elementos da matriz: " << somarElementos(matriz);
    cout << "\nMaior numero presente na matriz: " << maiorElemento(matriz);
    cout << "\nInforme uma linha para ser somada: ";
    cin >> linha;

    if (linha < 1 || linha > 3) {
        cout << "Linha invalida! Escolha entre 1 e 3.\n";
    } else {
        cout << "A linha '" << linha << "' somada resulta em: " << somarLinha(matriz, linha - 1) << "\n";
    }

    return 0;
}

void preencherMatriz(array<array<int, 3>, 3>& matriz){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "Numero posicao [" << i+1 << "][" << j+1 << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void exibirMatriz(const array<array<int, 3>, 3>& matriz){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

int somarElementos(const array<array<int, 3>, 3>& matriz){
    int soma = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            soma += matriz[i][j];
        }
    }
    return soma;
}

int maiorElemento(const array<array<int, 3>, 3>& matriz){
    int maior = matriz[0][0];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(maior < matriz[i][j]){
                maior = matriz[i][j];
            }
        }
    }
    return maior;
}

int somarLinha(const array<array<int, 3>, 3>& matriz, int linha){
    int soma = 0;
    for(int j = 0; j < 3; j++){
        soma += matriz[linha][j];
    }
    return soma;
}
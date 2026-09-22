#include <iostream>
#include <array>

using namespace std;

void preencherNotas(array<double, 8>& notas);
void exibirNotas(const array<double, 8>& notas);
double calcularMedia(const array<double, 8>& notas);
double maiorNota(const array<double, 8>& notas);
double menorNota(const array<double, 8>& notas);
int contarAprovados(const array<double, 8>& notas);

int main(){

    array<double, 8> notas{};

    preencherNotas(notas);
    cout << endl;
    exibirNotas(notas);
    cout << "Media: " << calcularMedia(notas) << endl;
    cout << "Maior: " << maiorNota(notas) << endl;
    cout << "Menor: " << menorNota(notas) << endl;
    cout << "Aprovados: " << contarAprovados(notas) << endl;

    return 0;
}

void preencherNotas(array<double, 8>& notas){
    for(size_t i = 0; i < notas.size(); i++){
        cout << "Informe a nota " << i + 1 << ": ";
        cin >> notas[i];
        if(notas[i] < 0 || notas[i] > 10){
            cout << "Insira uma nota entre 0 e 10!\n";
            i--;
        }
    }
}

void exibirNotas(const array<double, 8>& notas){
    for(size_t i = 0; i < notas.size(); i++){
        cout << "Nota " << i + 1 << ": " << notas[i] << endl;
    }
}

double calcularMedia(const array<double, 8>& notas){
    double media = 0;
    for(size_t i = 0; i < notas.size(); i++){
        media += notas[i];
    }
    return media / notas.size();
}

double maiorNota(const array<double, 8>& notas){
    double maior = notas[0];
    for(size_t i = 1; i < notas.size(); i++){
        if(maior < notas[i]) maior = notas[i];
    }
    return maior;
}

double menorNota(const array<double, 8>& notas){
    double menor = notas[0];
    for(size_t i = 1; i < notas.size(); i++){
        if(menor > notas[i]) menor = notas[i];
    }
    return menor;
}

int contarAprovados(const array<double, 8>& notas){
    int cont = 0;
    for(size_t i = 0; i < notas.size(); i++){
        if(notas[i] >= 6) cont++;
    }
    return cont;
}
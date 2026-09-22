#include <iostream>
using namespace std;

void preencherTemperaturas(double (&temperaturas)[7]);
void exibirTemperaturas(const double (&temperaturas)[7]);
double calcularMedia(const double (&temperaturas)[7]);
double maiorTemperatura(const double (&temperaturas)[7]);
double menorTemperatura(const double (&temperaturas)[7]);
void corrigirTemperatura(double (&temperaturas)[7], int dia, double correcao);
int contarAcima(const double (&temperaturas)[7], double obj);

int main(){

    double temperaturas[7] = {}, correcao = 0, obj = 0;
    int dia = 0;

    preencherTemperaturas(temperaturas);
    
    cout << "\n\nA media das temperaturas e: " << calcularMedia(temperaturas);
    cout << "\nA maior temperatura e: " << maiorTemperatura(temperaturas);
    cout << "\nA menor temperatura e: " << menorTemperatura(temperaturas);

    cout << "\n\nConferir valores acima de: ";
    cin >> obj;

    cout << "Ha " << contarAcima(temperaturas, obj) << " valor/valores acima de " << obj;

    cout << "\n\nInforme o dia que deseja corrigir: ";
    cin >> dia;

    if(dia < 1 or dia > 7){
        cout << "Dia invalido!";
        return 0;
    }

    cout << "Informe a nova temperatura: ";
    cin >> correcao;
    corrigirTemperatura(temperaturas, dia - 1, correcao);

    cout << "\n\n\n";
    exibirTemperaturas(temperaturas);

    return 0;
}

void preencherTemperaturas(double (&temperaturas)[7]){
    for(int i = 0; i < 7; i++){
        cout << "Dia " << 1 + i << ": ";
        cin >> temperaturas[i];
    }
}

void exibirTemperaturas(const double (&temperaturas)[7]){
    for(int i = 0; i < 7; i++){
        cout << "Dia " << 1 + i << ": " << temperaturas[i] << " C\n";
    }
}

double calcularMedia(const double (&temperaturas)[7]){
    double media = 0;
    for(int i = 0; i < 7; i++){
        media += temperaturas[i];
    }
    return media / 7;
}

double maiorTemperatura(const double (&temperaturas)[7]){
    double maior = temperaturas[0];

    for(int i = 1; i < 7; i++){
        if(maior < temperaturas[i]){
            maior = temperaturas[i];
        }
    }
    return maior;
}

double menorTemperatura(const double (&temperaturas)[7]){
    double menor = temperaturas[0];

    for(int i = 1; i < 7; i++){
        if(menor > temperaturas[i]){
            menor = temperaturas[i];
        }
    }
    return menor;
}

void corrigirTemperatura(double (&temperaturas)[7], int dia, double correcao){
    temperaturas[dia] = correcao;
}

int contarAcima(const double (&temperaturas)[7], double obj){
    int cont = 0;
    for(int i = 0; i < 7; i++){
        if(temperaturas[i] > obj){
            cont++;
        }
    }
    return cont;
}
#include <iostream>
using namespace std;

double lerValor();
bool valorValido(double valor);
double calcularCombustivel(double distancia, double consumoMedio);
double calcularCustoCombustivel(double quantidadeCombustivel, double precoLitro);
double calcularCustoPorPessoa(double custoTotal, int quantidadePessoas);
void exibirResultado(double quantidadeCombustivel, double custoTotal, double custoPorPessoa);

int main(){

    double precoLitro = 0, distancia = 0, consumoMedio = 0, quantidadeCombustivel = 0, custoTotal = 0, custoPorPessoa = 0;
    int quantidadePessoas = 0;

    cout << "Informe a distancia total da viagem, em quilometros: ";
    distancia = lerValor();

    if(!valorValido(distancia)){
        cout << "Valor invalido!";
        return 0;
    }

    cout << "Informe o valor do combustivel: ";
    precoLitro = lerValor();

    if(!valorValido(precoLitro)){
        cout << "Valor invalido!";
        return 0;
    }

    cout << "Informe o valor do KM/L de seu veiculo: ";
    consumoMedio = lerValor();

    if(!valorValido(consumoMedio)){
        cout << "Valor invalido!";
        return 0;
    }

    cout << "Informe a quantidade de pessoas: ";
    cin >> quantidadePessoas;

    if(!valorValido(quantidadePessoas)){
        cout << "Valor invalido!";
        return 0;
    }

    quantidadeCombustivel = calcularCombustivel(distancia, consumoMedio);
    custoTotal = calcularCustoCombustivel(quantidadeCombustivel, precoLitro);
    custoPorPessoa = calcularCustoPorPessoa(custoTotal, quantidadePessoas);

    exibirResultado(quantidadeCombustivel, custoTotal, custoPorPessoa);

    return 0;
}

double lerValor(){
    double valor = 0;
    cin >> valor;
    return valor;
}

bool valorValido(double valor){
    return valor > 0;
}

double calcularCombustivel(double distancia, double consumoMedio){
    return distancia / consumoMedio;
}

double calcularCustoCombustivel(double quantidadeCombustivel, double precoLitro){
    return quantidadeCombustivel * precoLitro;
}

double calcularCustoPorPessoa(double custoTotal, int quantidadePessoas){
    return custoTotal / quantidadePessoas;
}

void exibirResultado(double quantidadeCombustivel, double custoTotal, double custoPorPessoa){
    cout << "\nA quantidade de combustivel gasta em litros sera de: " << quantidadeCombustivel;
    cout << "\nO valor total em combustivel gasto sera de: R$" << custoTotal;
    cout << "\nO valor medio por pessoa e de: R$" << custoPorPessoa;
}
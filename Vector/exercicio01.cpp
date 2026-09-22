#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Animal{
    int codigo;
    string nome;
    string especie;
    string raca;
    double peso;
    string nomeTutor;
};

int buscarAnimal(const vector<Animal>& animais, int codigo);
void cadastrarAnimal(vector<Animal>& animais);
void exibirAnimal(const Animal& animal);
void exibirAnimais(const vector<Animal>& animais);
void consultarAnimal(const vector<Animal>& animais, int codigo);
void modificarAnimal(vector<Animal>& animais, int codigo);
void removerAnimal(vector<Animal>& animais, int codigo);

int main(){

    vector<Animal> animais{};
    int codigo = 0, esc = 0;

    do{
        cout << "\n1. Cadastrar animal"
             << "\n2. Exibir todos os animais"
             << "\n3. Consultar animal pelo codigo"
             << "\n4. Modificar animal"
             << "\n5. Remover animal"
             << "\n0. Sair\n";

        cin >> esc;

        switch(esc){
            case 1:
                cadastrarAnimal(animais);
                break;
            case 2:
                exibirAnimais(animais);
                break;

            case 3:
                cout << "\nInsira o codigo do animal que deseja consultar: ";
                cin >> codigo;

                consultarAnimal(animais, codigo);
                break;

            case 4:
                cout << "\nInsira o codigo do animal que deseja modificar: ";
                cin >> codigo;

                modificarAnimal(animais, codigo);
                break;

            case 5:
                cout << "\nInsira o codigo do animal que deseja remover: ";
                cin >> codigo;

                removerAnimal(animais, codigo);
                break;

            case 0:
                cout << "\nSaindo...";
                break;

            default:
                cout << "\nOpcao invalida!\nTente novamente!";
        }

    }while(esc != 0);

    return 0;
}

int buscarAnimal(const vector<Animal>& animais, int codigo){
    for(int i = 0; i < animais.size(); i++){
        if(codigo == animais.at(i).codigo) return i;
    }
    return -1;
}

void cadastrarAnimal(vector<Animal>& animais){
    Animal animal;

    cout << "\nInforme o codigo: ";
    cin >> animal.codigo;

    if(buscarAnimal(animais, animal.codigo) != -1){
        cout << "\nCodigo ja registrado.";
        return;
    }

    cout << "Informe o nome: ";
    getline(cin >> ws, animal.nome);

    cout << "Informe a especie: ";
    getline(cin >> ws, animal.especie);

    cout << "Informe a raca: ";
    getline(cin >> ws, animal.raca);

    cout << "Informe o peso(KG): ";
    cin >> animal.peso;

    if(animal.peso < 1){
        cout << "\nPeso invalido!";
        return;
    }

    cout << "Informe o nome do tutor: ";
    getline(cin >> ws, animal.nomeTutor);

    animais.push_back(animal);
}

void exibirAnimal(const Animal& animal){
    cout << "\nCodigo : " << animal.codigo;
    cout << "\nNome   : " << animal.nome;
    cout << "\nEspecie: " << animal.especie;
    cout << "\nRaca   : " << animal.raca;
    cout << "\nPeso   : " << fixed << setprecision(2) << animal.peso << "Kg";
    cout << "\nTutor  : " << animal.nomeTutor << endl;
}

void exibirAnimais(const vector<Animal>& animais){
    if(animais.empty()) cout << "\nNao ha animais cadastrados";
    else{
        for(const Animal& animal : animais){
            exibirAnimal(animal);
        }
    }
    cout << "\nA quantidade de animais cadastrados e: " << animais.size() << endl;
}

void consultarAnimal(const vector<Animal>& animais, int codigo){
    if(buscarAnimal(animais, codigo) == -1) cout << "\nAnimal nao encontrado";
    else{
        exibirAnimal(animais[buscarAnimal(animais, codigo)]);
    }
}

void modificarAnimal(vector<Animal>& animais, int codigo){
    int posicao = buscarAnimal(animais, codigo);
    if(posicao == -1) {
        cout << "\nAnimal nao encontrado";
        return;
    }

    cout << "\nDados atuais do animal: ";
    exibirAnimal(animais[posicao]);

    string nome, especie, raca, tutor;
    double novoPeso;

    cout << "Modifique o nome: ";
    getline(cin >> ws, nome);

    cout << "Modifique a especie: ";
    getline(cin >> ws, especie);

    cout << "Modifique a raca: ";
    getline(cin >> ws, raca);

    cout << "Modifique o peso: ";
    cin >> novoPeso;

    if(novoPeso < 1){
        cout << "Peso invalido!";
        return;
    }

    cout << "Novo tutor: ";
    getline(cin >> ws, tutor);

    animais[posicao].nome = nome;
    animais[posicao].especie = especie;
    animais[posicao].raca = raca;
    animais[posicao].peso = novoPeso;
    animais[posicao].nomeTutor = tutor;
}

void removerAnimal(vector<Animal>& animais, int codigo){
    int posicao = buscarAnimal(animais, codigo);
    string escDel = "";
    if(posicao == -1) cout << "\nAnimal nao encontrado";
    else{
        cout << "\nAnimal encontrado: ";
        exibirAnimal(animais[posicao]);

        cout << "\nDeseja remover este animal?";
        cout << "\nSim[S/s] - Nao[N/n]: ";
        cin >> escDel;

        if(escDel != "S" && escDel != "s") cout << "\nOperacao cancelada!";
        else{
            animais.erase(animais.begin() + posicao);
        }
    }
}

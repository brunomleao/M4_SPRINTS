// TESTE!
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente
// entre dois valores mínimo e máximo e retorna esse valor
void ajuste()
{
    int minimo = 0;
    int maximo = 0;
    float valor = 0;
    cout << "Insira aqui o valor minimo(intervalo inferior)!";
    cin >> minimo;
    cout << "Insira aqui o valor máximo(intervalo superior)!";
    cin >> maximo;
    cout << "Insira aqui o valor a ser ajustado percentualmente!";
    cin >> valor;

    if (valor > maximo || valor < minimo)
    {
        cout << "Valor inserido está fora do intervalo!\n";
    }
    else
    {
        float ajuste = ((valor - minimo) / (maximo - minimo)) * 100;
        cout << "O valor " << valor << " ajustado percentualmente no intervalo [" << minimo << "," << maximo << "]"
             << " será = " << ajuste << "%"
             << "\n";
    }
}
// 2 - Faça uma função que simule a leitura de um sensor lendo o
// valor do teclado ao final a função retorna este valor
int scanner()
{
    int contador = 1;
    char valor = 0;

    cout << "Pressione em algum botão do teclado numérico para o sensor ler e o programa retornar esse valor;\n";
    cin >> valor;
    cout << "Valor lido pelo sensor: " << valor << "\n";
    return valor;
}
// 3 - Faça uma função que armazena uma medida inteira qualquer
// em um vetor fornecido. Note que como C não possui vetores
// nativos da linguagem, lembre-se que você precisa passar o
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em
// uma área de memória fora do vetor
vector<int> vetor;
void adicionarvetor(int valor)
{
    vetor.push_back(valor);
}

// 4 - Faça uma função que recebe um vetor com 4 posições que contém
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a
// segunda é esta maior distância.
string posicao[4] = {"direita", "esquerda", "frente", "tras"};
int max_index = 0;
void posicoes()
{
    
    int distancia[4];
    
    int valor;
    for (int i = 0; i < 4; i++)
    {
        cout << "Insira a distancia do robo para seu lado da " << posicao[i] << "\n";
        cin >> valor;
        adicionarvetor(valor);
        //cin >> distancia[i];
    }
    //int max = distancia[0];
    int max = vetor[0];
    for (int i = 0; i < 4; i++)
    {
        if (vetor[i] > max)
        {
            //max = distancia[i];
            max = vetor[i];
            max_index = i;
        }
    }
    //cout << "A direção de maior distância corresponde a: " << posicao[max_index] << " e ela corresponde a: " << vetor[max_index] << "\n";
}
    // 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e
    // retorna verdadeiro ou falso
    int continuar()
    {
        char valor;
        cout << "Deseja continuar o mapeamento? Digite S para sim e N para não.\n";
        cin >> valor;
        valor = tolower(valor);
        if (valor == 's')
        {
            cout << "Se deseja continuar!\n";
            return 1;
        }
        if (valor=='n')
        {
            cout << "Se deseja encerrar!\n";
            return 0;
        }
        else
        {
            cout << "Valor inválido!\n";
            return 0;
        }
    }

    void andar(){
        int max = vetor[0];
        for (int i = 0; i < 4; i++)
        {
            if (vetor[i] > max)
            {
                max = vetor[i];
                max_index = i;
            }
        }
        int distancia = 0;
        if (posicao[max_index] == "direita"){
            cout<<"Insira a distancia a ser percorrida pelo robo: ";
            cin>>distancia;
            vetor[max_index]-=distancia;
            vetor[1]+=distancia;
        }
        if (posicao[max_index] == "esquerda"){
            cout<<"Insira a distancia a ser percorrida pelo robo: ";
            cin>>distancia;
            vetor[max_index]-=distancia;
            vetor[0]+=distancia;
        }
        if (posicao[max_index] == "frente"){
            cout<<"Insira a distancia a ser percorrida pelo robo: ";
            cin>>distancia;
            vetor[max_index]-=distancia;
            vetor[3]+=distancia;
        }
        if (posicao[max_index] == "tras"){
            cout<<"Insira a distancia a ser percorrida pelo robo: ";
            cin>>distancia;
            vetor[max_index]-=distancia;
            vetor[2]+=distancia;
        }
        for (int i = 0; i < 4; i++)
        {
            if (vetor[i] <= 0)
            {
                cout<<"O robo está na parede!\n";
                exit(0);
            }
        }
            
    }


void printposicoes(){
    cout<<"Posicao atual do robo: \n";
    for (int i = 0; i < 4; i++)
    {
        cout<<posicao[i]<<": "<<vetor[i]<<"\n";
    }
}
    int main()
    {
        posicoes();
        printposicoes();
        andar();
        printposicoes();
        while(continuar()==1){
            andar();
            printposicoes();
        }
        cout << "Encerrando o mapeamento!\n";
        
    }

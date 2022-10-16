#include <iostream>
#include <string>

using namespace std;
// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor
void ajuste(){
    int minimo = 0;
    int maximo = 0;
    float valor = 0;
    cout<<"Insira aqui o valor minimo(intervalo inferior)!";
    cin >> minimo;
    cout<<"Insira aqui o valor máximo(intervalo superior)!";
    cin >> maximo;
    cout<<"Insira aqui o valor a ser ajustado percentualmente!";
    cin >> valor;

    if (valor>maximo || valor<minimo) {
        cout<<"Valor inserido está fora do intervalo!\n";
    }
    else {
        float ajuste = ((valor - minimo)/(maximo - minimo))*100;
        cout<< "O valor "<< valor<<" ajustado percentualmente no intervalo [" << minimo <<","<<maximo <<"]"<<" será = "<< ajuste<<"%"<<"\n";
    }
}
// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor
void scanner(){
int contador = 1;
char valor = 0;
    
    cout <<"Pressione em algum botão do teclado numérico para o sensor ler e o programa retornar esse valor;\n";
    cin>>valor;
    cout<<"Valor lido pelo sensor: "<<valor<<"\n";

    
}
// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor
void vetor(){
    int i = 0;
    cout<<"Insira a medida inteira a ser armazenada em um vetor: ";
    cin>>i;
    int vetor[]={i};
    cout<<vetor[0];
}


// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.
void posicoes(){
    string posicao[4] = {"direita", "esquerda", "frente", "tras"};
    int distancia[4];
    int max_index = 0;
    for(int i=0;i<4;i++){
        cout<<"Insira a distancia do robo para seu lado da "<<posicao[i]<<"\n";
        cin>>distancia[i];
    }
    int max = distancia[0];
    for(int i=0;i<4;i++){
        if(distancia[i]>max){
            max = distancia[i];
            max_index = i;
        }
    }
    cout<<"A direção de maior distância corresponde a: "<<posicao[max_index]<< " e ela corresponde a: "<<distancia[max_index]<<"\n";



// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso
int continuar(){
    char valor;
    cout<<"Deseja continuar o mapeamento? Digite S para sim e N para não.\n";
    cin>>valor;
    if(valor=='S') {
        cout<<"Se deseja continuar!\n";
        return 1;
    }
    else {
        cout<<"Se deseja encerrar!\n";
        return 0;
    }
}

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas
int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;		
	while(dirigindo){		
		int medida = /// .. Chame a função de de leitura da medida para a "Direita"
		medida = converteSensor(medida,0,830);
		posAtualVetor = // Chame a função para armazenar a medida no vetor
        ///////////////////////////////////////////////////////////////////////////		
		// Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
		// ................
		///////////////////////////////////////////////////////////////////////////
		dirigindo = leComando();		
	}
	return posAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;
	int maiorDir = 0;
	
	for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = direcaoMenorCaminho(&(vetorMov[i]),&maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	}
}

int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}
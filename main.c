

#include "calculator.h"

int main(){
	
	float resultado=0, valor;
	char opcao;
	
	while(opcao != 'S'){
		
	#ifdef _WIN32
        system("cls");  // para Windows
    #else
        system("clear");  // para Unix/Linux
    #endif
		//Sua funC'C#o C) de limpar a tela de saC-da do programa,
		//ou seja, funciona como um "apagador" para tudo que jC! foi escrito.
		banner();
		//printf("\nValor atual: %.2f", resultado); 
		
		printf("\n\nOperacao: ");
		scanf(" %c", &opcao);
		
		calcule(opcao);
		
		//return 0;
		
	
	}
}




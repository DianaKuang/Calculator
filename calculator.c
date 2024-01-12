
#include "calculator.h"

void gravar(char guardar[1000]){
    FILE *arq;
    arq = fopen("arquivo_leitura.txt", "a");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(arq, "\n%s", guardar);
    fclose(arq);
}

void ler(){
    FILE *arq;
    char linha[50];
    int i=1, pegar, cont=1;
    
    arq = fopen("arquivo_leitura.txt", "r");
    
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while(fgets(linha, sizeof(linha), arq) != NULL){
        printf("%d - %s", i, linha);
        if(cont % 2 == 0){
            i++;
        }
        cont++;
    }        
    
    fclose(arq);
    
    printf("\n\nDigite 1 para sair: ");
    scanf("%d", &pegar);
}

void operacoesbasicas(){
    float valor1, valor2, resultado;
    char op, guardar[1000];

    printf("\nInforme um valor: "); 
    scanf("%f", &valor1);
    printf("\nInforme Operacao (ou 0 para sair): "); 
    scanf(" %c", &op);

    while(op != '0'){
        switch(op){
            case '+':
                printf("\nInforme valor: ");
                scanf(" %f", &valor2); 
                resultado = valor1 + valor2;
                sprintf(guardar, "%.2f %c %.2f = %.2f", valor1, op, valor2, resultado);
                gravar(guardar);
                valor1 = resultado;
                break;
            case '-': 
                printf("\nInforme valor: ");
                scanf(" %f", &valor2); 
                resultado = valor1 - valor2;
                sprintf(guardar, "%.2f %c %.2f = %.2f", valor1, op, valor2, resultado);
                gravar(guardar);
                valor1 = resultado;
                break;
            case '/': 
                printf("\nInforme valor: ");
                scanf(" %f", &valor2); 
                resultado = (valor1 / valor2);
                sprintf(guardar, "%.2f %c %.2f = %.2f", valor1, op, valor2, resultado);
                gravar(guardar);
                valor1 = resultado;
                break;
            case '*': 
                printf("\nInforme valor: ");
                scanf(" %f", &valor2); 
                resultado = (valor1 * valor2);
                sprintf(guardar, "%.2f %c %.2f = %.2f", valor1, op, valor2, resultado);
                gravar(guardar);
                valor1 = resultado;
                break;
        }
        printf("\n\nResultado: %.2f", resultado);
        printf("\n\nInforme Operacao (ou 0 para sair): "); 
        scanf(" %c", &op);
    }
}

void distancia(){
    float x1, x2, y1, y2;
    float resposta;
    char guardar[1000], letra='S';

    while(letra != 'N'){
        printf("\nInforme x1: "); 
        scanf("%f", &x1);
        printf("\nInforme x2: "); 
        scanf("%f", &x2);
        printf("\nInforme y1: "); 
        scanf("%f", &y1);
        printf("\nInforme y2: "); 
        scanf("%f", &y2);

        resposta = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));

        printf("\nDistancia = %.2f", resposta);

        sprintf(guardar, "Distancia: x1: %.2f x2: %.2f y1: %.2f y2: %.2f = %.2f", x1 , x2, y1 ,y2, resposta);

        gravar(guardar);

        printf("\n\nRealizar novo calculo? (S - Sim, N - Nao)");
        scanf(" %c", &letra);
    }
}

void calcule(char op){
	
	int n, delta, x1, x2, contador = 1, fatorial = 1;
	float resultado, valor, x, y, a, b, c;
	char guardar[1000], letra;
	//scanf("%c", &letra);
	switch(op){
	    
		case '1':
			operacoesbasicas();			
			break;
			
		case '2':
			distancia();			
			break;
			
		case '3':
			
			while(letra != 'N'){
				
				contador = 1;
				fatorial = 1;
	            printf("Digite um valor para n:\n");
	            scanf("%d", &n);
	            while(contador <= n) {
	               fatorial = fatorial*contador;
	               contador = contador + 1;
	    		}
	           //printf("Resultado = %d\n", fatorial);
				sprintf(guardar, "%d ! = %d", n, fatorial);
				gravar(guardar);
				
				printf("\nFatorial: %d", fatorial);
				
				printf("\n\n\nRealizar novo calculo? (S - Sim, N - Nao)");
			
				scanf(" %c", &letra);
			
			}
		
            break;
            
        case '4':
        	while(letra != 'N'){
				printf("Digite um numero:\n");
	            scanf("%f", &y);
	            resultado = sqrt(y);
	            printf("Raiz quadrada = %.2f.", resultado);
	            sprintf(guardar, "%.2d = %.2f", n, resultado);
				gravar(guardar);
				printf("\n\n\nRealizar novo calculo? (S - Sim, N - Nao)");
				scanf(" %c", &letra);
			}
			break;
        case '5':
        	while(letra != 'N'){
                printf("Numero:\n");
                scanf("%f", &y);
                resultado = pow(y, 2);
                printf("Resultado = %.2f.", resultado);
                //retorno = resultado;
                sprintf(guardar, "%.2d^ = %.2f", n, resultado);
				gravar(guardar);
				printf("\n\n\nRealizar novo calculo? (S - Sim, N - Nao)");
				scanf(" %c", &letra);
			}
        	break;
        case '6':
        	while(letra != 'N'){
        		
				printf("Total x: ");
				scanf("%f", &a);
				printf("Porcento de x: ");
				scanf("%f", &b);
				resultado = (a * b)/100;
				printf("Resultado = %.2f", resultado);
				//retorno = resultado;
				sprintf(guardar, "%.2f * %.2f / 100 = %.2f", a, b, resultado);
				gravar(guardar);
				
				printf("\n\n\nRealizar novo calculo? (S - Sim, N - Nao)");
				scanf(" %c", &letra);
			}
        	break;
        case '7':
            while(letra != 'N'){
        	   printf("Valor para a: ");
               scanf("%f", &a);
               printf("Valor para b: ");
               scanf("%f", &b);
               printf("Valor para c: ");
               scanf("%f", &c);
    
               //funciona mesmo sem o if 
               delta = (b * b - 4 * a * c);
               x1 = (- b + sqrt(delta))/(2 * a);
               x2 = (- b - sqrt(delta))/(2 * a);
    
                printf("Resultado = %d %d %d", delta, x1, x2);
				//retorno = resultado;
				sprintf(guardar, "%d %d %d", delta, x1, x2);
				gravar(guardar);
				
				printf("\n\n\nRealizar novo calculo? (S - Sim, N - Nao)");
				scanf(" %c", &letra);
            }
				break;
				
		case 'Q':
		while(letra != 'N'){
				printf("\nLados: ");
				scanf("%f", &a); 
				resultado = a*a;
				printf("area do quadrado: %.2f", resultado);
				sprintf(guardar, "%f * %f = %.2f", a, a, resultado);
				gravar(guardar);
				printf("\n\n\nRealizar novo calculo? (S - Sim, N - Nao)");
				scanf(" %c", &letra);
		}
				break;
				
		case 'T': 
		while(letra != 'N'){
				printf("\nBase: ");
				scanf("%f", &a);
				printf("\nAltura: ");
				scanf("%f", &b);
				resultado = (a*b)/2;
				printf("area do triangulo: %.2f", resultado);
				sprintf(guardar, "%f * %f / 2 = %.2f", a, b, resultado);
				gravar(guardar);
				printf("\n\n\nRealizar novo calculo? (S - Sim, N - Nao)");
				scanf(" %c", &letra);
		}
				break;
				
		case 'C': 
		while(letra != 'N'){
				printf("\nRaio: ");
				scanf(" %f", &a); 
				resultado = PI*(a*a);
				printf("area da circunferencia: %f", resultado);
				sprintf(guardar, "Pi * %f * %f = %f", a, a, resultado);
				gravar(guardar);
				printf("\n\n\nRealizar novo calculo? (S - Sim, N - Nao)");
				scanf(" %c", &letra);
		}
				break;
		case 'R':
		while(letra != 'N'){
		    printf("\nBase: ");
		    scanf("%f", &a);
		    printf("\nAltura: ");
	        scanf("%f", &b);
		    resultado = a*b;
		    printf("area do retangulo: %.2f", resultado);
		    sprintf(guardar, "%f * %f = %.2f", a, b, resultado);
		    gravar(guardar);
		    printf("\n\n\nRealizar novo calculo? (S - Sim, N - Nao)");
		    scanf(" %c", &letra);
		}
		    break;
		case 'H':
			ler();
			break;
	}	
		
	//return retorno;
}

void banner(){
	
	printf("\n*******************************");
	printf("\n          CALCULADORA          ");
	printf("\n*******************************");
	printf("\n");
	
	printf("\n[1]: Operacoes Basicas");
	printf("\n[2]: Distancia ");
	printf("\n[3]: Fatorial ");
	printf("\n[4]: Raiz quadrada ");
	printf("\n[5]: potencia ");
	printf("\n[6]: porcentagem c/ regra de 3");
	printf("\n[7]: bhaskara");
	printf("\n[Q]: area do quadrado");
	printf("\n[C]: area da circunferencia");
	printf("\n[T]: area do triangulo ");
	printf("\n[R]: area do retangulo");
	printf("\n[H]: Historico");
	printf("\n[S]: Sair ");
	
	printf("\n\nCaso seja calculado mais de 1 operador, dar prioridade a multiplicaC'ao e a divisao");
	printf("\nCaso queira resgatar alguma equaC'ao ja inserida, aperte H, veja o histC3rico e insira novamente");
	printf("\n");
	printf("\n");
}
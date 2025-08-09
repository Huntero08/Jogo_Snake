#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include "snake.h"
#include "funcoes.h"


int main() {
	setlocale(LC_ALL, "Portuguese"); // Colocar o idioma em Portugu�s
    srand(time(NULL)); // Gerar numero aleat�rio
    Jogo jogo;
    
    // Array com os nomes dos arquivos de fases
    const char *arquivosFases[] = {
        "niveis/nivel1.txt",
        "niveis/nivel2.txt",
        "niveis/nivel3.txt",
        "niveis/nivel4.txt",
        "niveis/nivel5.txt"
    };

    int opcao, nivel, chave;
    // Tela principal
    do {    
        limpar_tela();
        printf("-----------------------------------------");
        printf("\n*BEM-VINDO AO JOGO DA COBRA DO JEFFERSON*");
        printf("\n-----------------------------------------");
        printf("\n1. Iniciar Jogo\n2. Estat�sticas\n3. Instru��es\n0. Sair\nEscolha uma op��o: ");
        scanf("%d", &opcao);
		
		
		// Op��es 
        switch (opcao) {
			case 1:
				system("cls");
				do{
				    printf("Escolha o nivel (1-5): ");
				    scanf("%d", &nivel);
				    if (nivel >= 1 && nivel <= 5) {
				    	system("cls");
				        printf("Digite o nome da sua cobra: ");
				        getchar();
				        fgets(jogo.cobra.nome, sizeof(jogo.cobra.nome), stdin);
				        jogo.cobra.nome[strcspn(jogo.cobra.nome, "\n")] = 0;
				         // Carregar a fase selecionada
                        Fase fase;
                        carregarFase(arquivosFases[nivel - 1], &fase);
                        iniciar_jogo(&jogo, fase);
				    } else {
				    	chave++;
				        printf("Nivel invalido.\n");
				        getchar();
	        			getchar();
	        			system("cls");
				    }
				} while(chave == 0);
			    break;

            case 2:
            	system("cls");
                exibir_estatisticas();
                break;
            case 3:
            	system("cls");
                exibir_instrucoes();
                break;
            case 0:
                printf("Saindo...\n");
                break;;
            default:
                printf("Op��o invalida!\n");
                getchar();
                getchar();
        }
    } while (opcao != 0);

    return 0;
}

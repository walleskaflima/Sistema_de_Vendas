#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int total_Baixa = 0;
    int total_IngressosAdquiridos = 0;
    float valor_Total = 0.0;
    int ingressos_Comprados[100];
    float valores_Ingressos[100];
    int exposicao_Selecionada = 0;
    int total_Ingressos[4] = {0};
    char nome_Arquivo[] = "Controle_Vendas.csv";

    char nomes_Exposicoes[4][100] = {
		"150 anos de Santos Dumont",
        "100 anos da Semana da Arte Moderna",
        "Jogos Olimpicos de Paris 2024",
        "A evolucao da Inteligencia Artificial"
    };

    char descricoes_Exposicoes[4][500] = {
		"Uma homenagem ao pioneiro da aviacao Alberto Santos-Dumont",
        "Uma exposicao que celebra o movimento artistico do seculo XX",
        "Prepare-se para os Jogos Olimpicos de Paris em 2024",
        "Uma jornada pela evolucao da tecnologia ao longo dos anos"
    };

    float precos_Exposicoes[4] = {50.0, 30.0, 25.0, 40.0};

    FILE *controle_Vendas;

    if ((controle_Vendas = fopen(nome_Arquivo, "a")) == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    printf("============= MUSEU ==============\n");

    printf("Bem-vindo(a) ao nosso museu multitematico\n\n");
    printf("Aqui teremos as seguintes exposicoes:\n\n");
    printf("1 - %s\n", nomes_Exposicoes[0]);
    printf("2 - %s\n", nomes_Exposicoes[1]);
    printf("3 - %s\n", nomes_Exposicoes[2]);
    printf("4 - %s\n", nomes_Exposicoes[3]);
    printf("\n");

    while (1) {
        int opcao;
        printf("Escolha uma opcao:\n");
        printf("1 - Mostrar informacoes das exposicoes\n");
        printf("2 - Comprar Ingresso(s)\n");
        printf("3 - Calcular Pagamento\n");
        printf("4 - Dar Baixa em Ingresso(s)\n");
        printf("5 - Informacoes finais\n");
        printf("6 - Fim\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1){
            for (int i = 0; i < 4; i++){
                    printf("Exposicao %d:\n", i + 1);
                    printf("Nome: %s\n", nomes_Exposicoes[i]);
                    printf("Descricao: %s\n", descricoes_Exposicoes[i]);
                    printf("Preco do ingresso: R$%.2f\n", precos_Exposicoes[i]);
                    printf("\n");
                }
            }

        if (opcao == 2){
            do{
                printf("Escolha a exposicao (1 a 4) que deseja visitar: ");
                scanf("%d", &exposicao_Selecionada);
                if (exposicao_Selecionada < 1 || exposicao_Selecionada > 4){
                    printf("Exposicao invalida. Escolha uma exposicao de 1 a 4\n");
                }
            }

            while (exposicao_Selecionada < 1 || exposicao_Selecionada > 4);

            int quantidade;
            printf("Quantos ingressos deseja comprar para esta exposicao? ");
            scanf("%d", &quantidade);
            printf("\n");

            for (int i = 0; i < quantidade; i++){
                int tipo_Ingresso;
                do{
                    printf("Escolha o tipo de ingresso para o ingresso %d (1 - Inteira, 2 - Meia, 3 - Isencao): ", i + 1);
                    scanf("%d", &tipo_Ingresso);
                    if (tipo_Ingresso < 1 || tipo_Ingresso > 3){
                        printf("Tipo de ingresso invalido. Escolha 1 para Inteira, 2 para Meia ou 3 para Isencao.\n");
                    }
                }

                while (tipo_Ingresso < 1 || tipo_Ingresso > 3);

                int numero_Ingresso = total_IngressosAdquiridos;

                if (tipo_Ingresso == 1){
                    valores_Ingressos[numero_Ingresso] = precos_Exposicoes[exposicao_Selecionada - 1];
                } 
                else if (tipo_Ingresso == 2){
                    valores_Ingressos[numero_Ingresso] = precos_Exposicoes[exposicao_Selecionada - 1] / 2;
                }
                else{
                    valores_Ingressos[numero_Ingresso] = 0.0;
                }

                ingressos_Comprados[numero_Ingresso] = tipo_Ingresso;
                valor_Total += valores_Ingressos[numero_Ingresso];
                total_Ingressos[exposicao_Selecionada - 1]++;
                total_IngressosAdquiridos++;

                printf("Ingresso %d adquirido com sucesso para a exposicao %s! Se nao desejar adquirir ingressos para mais exposicoes, pode prosseguir\n\n", numero_Ingresso + 1, nomes_Exposicoes[exposicao_Selecionada - 1]);
            }
        } 
        else if (opcao == 3){
            printf("Valor total a ser pago: R$%.2f\n\n", valor_Total);
        } 
        else if (opcao == 4){
            if (total_IngressosAdquiridos > 0){
                total_Baixa += total_IngressosAdquiridos;
                printf("Baixa realizada em %d ingresso(s)\n\n", total_Baixa);
                total_IngressosAdquiridos = 0;
            } 
            else{
                printf("Nenhum ingresso comprado. Nao e possivel dar baixa\n\n");
            }
        } 
        else if (opcao == 5){
            printf("Quantidade de ingresso(s) adquirido(s) em cada exposicao:\n");
            for (int i = 0; i < 4; i++){
                if (total_Ingressos[i] > 0){
                printf("%s: %d\n", nomes_Exposicoes[i], total_Ingressos[i]);
                }
            }
            printf("\nValor total a ser pago: R$%.2f. Lembre-se de apresentar o documento de comprovacao na entrada\n", valor_Total);
            printf("\nBaixa realizada em %d ingresso(s)\n", total_Baixa);
            printf("\nAproveite a exposicao\n\n");

        } 
        else if (opcao == 6){
            printf("Fim\n");
            break;
        }
        else if(!(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5 || opcao == 6)){
            printf("Erro. Escolha um numero de 1 a 6\n");
            break;
            }

    }

    if (controle_Vendas != NULL){
        for (int i = 0; i < 4; i++){
            if (total_Ingressos[i] > 0) {
                fprintf(controle_Vendas, "Exposicao: %s - %d ingresso(s)\n", nomes_Exposicoes[i], total_Ingressos[i]);
            }
        }
        fprintf(controle_Vendas, "Quantidade de ingressos que deram baixas: %d\n", total_Baixa);
        fprintf(controle_Vendas, "Valor obtido dos ingressos: R$%.2f\n\n", valor_Total);
        fclose(controle_Vendas);
    }
    return 0;
}
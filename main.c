#include <stdio.h>
#include <string.h> // APARENTEMENTE INUTIL, MAS DEIXEI POR HORA

int main(){
    float valorTotal[4];
    char nomes[4][77];
    char sexos[4];
    int codigo[4];

    for(int i = 0; i < 4; i++){

        printf("\nCadastro %d:\n", i + 1);

        printf("Nome do cliente: ");
        scanf("%s",nomes[i]);
        printf("Valor da venda: ");
        scanf("%f", &valorTotal[i]);
        while(valorTotal[i] < 0){
            printf("Error: valor negativo nao permitido.\n");
            printf("Valor da venda: ");
            scanf("%f", &valorTotal[i]);
        }

        printf("Sexo (m/f/o): ");
        scanf(" %c", &sexos[i]);
        while(sexos[i] != 'm' && sexos[i] != 'f' && sexos[i] != 'o'){
            printf("Error: sexo invalido.\n");
            printf("Sexo (m/f/o): ");
            scanf(" %c", &sexos[i]);
        }
        printf("Codigo do pedido (1 a 10): ");
        scanf("%d", &codigo[i]);
        while(codigo[i] < 1 || codigo[i] > 10){
            printf("Error: codigo fora do permitido.\n");
            printf("Codigo do pedido (1 a 10): ");
            scanf("%d", &codigo[i]);
        }

        printf("Pedido cadastrado com sucesso!\n");
    }

    int opcao = 0;
    char nomeBusca[77];

    while(opcao != 5){

        printf("\n─── MENU ───\n");
        printf("(1) ➜  Ver pedidos por nome\n");
        printf("(2) ➜  Ver todos os pedidos\n");
        printf("(3) ➜  Pesquisar um pedido\n");
        printf("(4) ➜  Ver informacoes dos pedidos\n");
        printf("(5) ➜  Encerrar Programa\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){

            printf("Digite o nome: ");
            scanf("%s",nomeBusca);

        int achou = 0;

            for(int i = 0; i < 4; i++){
                if(strcmp(nomes[i], nomeBusca) == 0){
                    printf("Cliente: %s | Sexo: %c | Valor: R$%.2f | Codigo: %d\n",
                        nomes[i], sexos[i], valorTotal[i], codigo[i]);
                    achou = 1;
                }
            }

            if(achou == 0){
                printf("Nenhum pedido encontrdo.\n");
            }

        }else if (opcao == 2){

        int i = 0;
            do{
                printf("Cliente: %s | Sexo: %c | Valor: R$%.2f | Codigo: %d\n",
                    nomes[i], sexos[i], valorTotal[i], codigo[i]);
                i++;
            }while (i < 4);

        }else if(opcao == 3){

            printf("Digite o nome do cliente para pesquisar: ");
            scanf("%s", nomeBusca);

        int achou = 0;
        float soma = 0;

        for(int i = 0; i < 4; i++){
                if(strcmp(nomes[i], nomeBusca) == 0){
                printf("Pedido - Valor: R$%.2f | Codigo: %d\n", valorTotal[i], codigo[i]);
                soma += valorTotal[i];
                achou = 1;
                }
            }

        if(achou){
                printf("Soma total dos pedidos de %s: R$%.2f\n", nomeBusca, soma);
            }else{
                printf("Nao tem compras com ess nome.\n");
            }

    char voltar;
            printf("Deseja voltar ao menu?(s/n): ");
            scanf(" %c", &voltar);
            if(voltar != 's' && voltar != 'S'){
                opcao = 5;
            }

        }else if(opcao == 4){

            float valorRef;
            printf("Valor de referencia para saber quais são mais caros que o mesmo: ");
            scanf("%f", &valorRef);

            int acima = 0, entre = 0, outro = 0, cod1ou2 = 0;
            float totalF = 0, soma = 0;
            float maior = valorTotal[0];
            float menor = valorTotal[0];
            int codMais = 0;
            int codigos[11] = {0};

            for(int i = 0; i < 4; i++){
                if(valorTotal[i] > valorRef) acima++;
                if(valorTotal[i] >= 20 && valorTotal[i] <= 30) entre++;
                if(sexos[i] == 'o') outro++;
                if(sexos[i] == 'f') totalF += valorTotal[i];

                soma += valorTotal[i];

                if(valorTotal[i] > maior) maior = valorTotal[i];
                if(valorTotal[i] < menor) menor = valorTotal[i];

                if(codigo[i] == 1 || codigo[i] == 2) cod1ou2++;

                codigos[codigo[i]]++;
            }

            for(int i = 1; i <= 10; i++){
                if(codigos[i] > codigos[codMais]){
                    codMais = i;
                }
            }
            printf("\nPedidos acima de :%.2f: %d\n", valorRef, acima);
            printf("Pedidos entre 20 e 30: %d\n", entre);
            printf("Clientes com sexo 'o': %d\n", outro);
            printf("Total comprado por mulheres: %.2f\n", totalF);
            printf("Media dos pedidos: %.2f\n", soma / 4);
            printf("Pedido mais caro: %.2f\n", maior);
            printf("Codigos 1 ou 2 vendidos: %d\n", cod1ou2);
            printf("Codigo mais vendido: %d\n", codMais);
            
            
            char voltar;
            printf("Deseja voltar ao menu?(s/n): ");
            scanf(" %c", &voltar);
            if(voltar != 's' && voltar != 'S'){
                opcao = 5;
            }


        }else if(opcao != 5){
            printf("invalido.\n");
        }
        
    }
    
    printf("Programa encerrado.\n");
    
    return 0;
}

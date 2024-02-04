#include <stdio.h>
#include <string.h>
#include <math.h>

struct valores1 {
    int capital;
    float taxa;
    float taxaPronta;
    int tempo;
    int resultado;
    int montante;
    int simnao;
};

struct valores2 {
    int P;
    float taxa;
    int escolha;
    float n;
    float r;
    float result1;
    float serPotenciado;
    int potencia;
    float potenciado;
    int T;
    float M;
};

    void opcao1(float *n){
        *n = 12.0;
    };

    void opcao2(float *n){
        *n = 4.0;
    };

    void opcao3(float *n){
        *n = 2.0;
    };

    void opcao4(float *n){
        *n = 1.0;
    };



int main() {

    int continuar = 1;

    while (continuar == 1){

        char compostoOuSimples[9];

        printf("Digite [composto] para calcular juros composto, e, [simples] para calcular juros simples: \n");
        scanf("%s", &compostoOuSimples);


        if (strlen(compostoOuSimples) == 7 ) {

            struct valores1 juros;

            printf("Quanto foi investido?\n");
            scanf("%d", &juros.capital);

            printf("Qual e a taxa do juros simples? (em percentual)\n");
            scanf("%f", &juros.taxa);

            juros.taxaPronta = juros.taxa / 100.0;

            printf("Quantos meses ? \n");
            scanf("%d", &juros.tempo);

            juros.resultado = juros.capital * juros.taxaPronta * juros.tempo;

            juros.montante = juros.capital + juros.resultado;

            printf("Juros acumulado de %d \n", juros.resultado);
            printf("O montante que tera depois de %d meses e de %d \n", juros.tempo, juros.montante);


            printf("Deseja fazer mais calculos ? 1[sim] 2[nao]\n");
            scanf("%d", &continuar);

        }else{

            struct valores2 juros;

            printf("Qual e o capital investido?\n");
            scanf("%d", &juros.P);

            printf("Qual o valor da taxa (Em Porcentagem)? \n");
            scanf("%f", &juros.taxa);


            printf("Os juros serao compostos: \n");
            printf("[1] Mensalmente. \n");
            printf("[2] Trimestralmente. \n");
            printf("[3] Semestralmente. \n");
            printf("[4] Anualmente. \n");
            scanf("%d", &juros.escolha);

            switch(juros.escolha){
                case 1:
                    opcao1(&juros.n);
                    break;
                case 2:
                    opcao2(&juros.n);
                    break;
                case 3:
                    opcao3(&juros.n);
                    break;
                case 4:
                    opcao4(&juros.n);
                    break;
                default:
                    printf("Opcao invalida. \n");
                    return 1;
            };

            printf("Por quantos anos os juros serao cobrados?\n");
            scanf("%d", &juros.T);

            juros.r = juros.taxa / 100;

            juros.result1 = 1 + (juros.r / juros.n);

            juros.potencia = juros.n * juros.T;

            juros.potenciado = pow(juros.result1, juros.potencia + 1);

            juros.M = juros.P * juros.potenciado;

            printf("O Montante depois de %d anos e de R$%.4f \n", juros.T, juros.M);

            printf("Deseja fazer mais calculos ? 1[sim] 2[nao]\n");
            scanf("%d", &continuar);

        };
    };

     printf("Fim do programa...\n");
     return 0;

};



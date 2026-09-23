#include <stdio.h>

#define MIN_TEMPERATURA -50.0
#define MAX_TEMPERATURA 100.0
#define CONSECUTIVAS_LIMITE 3

int main(void) {
    double limite;
    double temperatura;
    double soma = 0.0;
    double maior = 0.0;
    double menor = 0.0;
    int quantidade = 0;
    int acimaLimite = 0;
    int consecutivas = 0;
    int primeiraLeitura = 1;

    printf("=== SISTEMA DE MONITORAMENTO DE TEMPERATURA ===\n\n");

    /* do...while garante que o limite seja solicitado pelo menos uma vez. */
    do {
        printf("Digite o limite de temperatura (%.1f a %.1f C): ",
               MIN_TEMPERATURA, MAX_TEMPERATURA);

        if (scanf("%lf", &limite) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            while (getchar() != '\n') {
                /* Limpa o restante da entrada invalida. */
            }
            limite = MAX_TEMPERATURA + 1.0;
            continue;
        }

        if (limite < MIN_TEMPERATURA || limite > MAX_TEMPERATURA) {
            printf("Limite invalido! Tente novamente.\n");
        }
    } while (limite < MIN_TEMPERATURA || limite > MAX_TEMPERATURA);

    printf("\nMonitoramento iniciado.\n");
    printf("Digite uma temperatura entre %.1f e %.1f C.\n",
           MIN_TEMPERATURA, MAX_TEMPERATURA);
    printf("Digite 999 para encerrar manualmente.\n\n");

    /* while mantém o monitoramento ativo até uma condição de parada. */
    while (1) {
        printf("Digite a temperatura: ");

        if (scanf("%lf", &temperatura) != 1) {
            printf("Entrada invalida! Digite um numero.\n\n");
            while (getchar() != '\n') {
                /* Limpa o restante da entrada invalida. */
            }
            continue;
        }

        if (temperatura == 999) {
            printf("\nMonitoramento encerrado manualmente.\n");
            break;
        }

        if (temperatura < MIN_TEMPERATURA || temperatura > MAX_TEMPERATURA) {
            printf("Temperatura invalida! Informe um valor entre %.1f e %.1f C.\n\n",
                   MIN_TEMPERATURA, MAX_TEMPERATURA);
            continue;
        }

        /* Atualiza os dados estatisticos das leituras validas. */
        soma += temperatura;
        quantidade++;

        if (primeiraLeitura) {
            maior = temperatura;
            menor = temperatura;
            primeiraLeitura = 0;
        } else {
            if (temperatura > maior) {
                maior = temperatura;
            }
            if (temperatura < menor) {
                menor = temperatura;
            }
        }

        /* Controla temperaturas acima do limite e a sequencia consecutiva. */
        if (temperatura > limite) {
            acimaLimite++;
            consecutivas++;

            printf("ALERTA: temperatura acima do limite!\n");
            printf("Sequencia atual acima do limite: %d\n", consecutivas);

            if (consecutivas == CONSECUTIVAS_LIMITE) {
                printf("\n*** ENCERRAMENTO AUTOMATICO ***\n");
                printf("Foram detectadas %d temperaturas consecutivas acima do limite.\n",
                       CONSECUTIVAS_LIMITE);
                break;
            }
        } else {
            consecutivas = 0;
            printf("Temperatura dentro do limite.\n");
        }

        printf("\n");
    }

    printf("\n=== RELATORIO FINAL ===\n");

    if (quantidade > 0) {
        double media = soma / quantidade;
        double percentual = ((double)acimaLimite / quantidade) * 100.0;

        printf("Quantidade de leituras validas: %d\n", quantidade);
        printf("Maior temperatura: %.2f C\n", maior);
        printf("Menor temperatura: %.2f C\n", menor);
        printf("Media das temperaturas: %.2f C\n", media);
        printf("Temperaturas acima do limite: %d\n", acimaLimite);
        printf("Percentual acima do limite: %.2f%%\n", percentual);
    } else {
        printf("Nenhuma leitura valida foi registrada.\n");
    }

    return 0;
}

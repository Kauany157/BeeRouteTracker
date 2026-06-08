#include <stdio.h>
#include "functions.h"

int main(void) {
    int opcao, saiu = 0;

    do {
        menu();

        if (scanf("%d", &opcao) != 1) {
            scanf("%*[^\n]");
            getchar();
            printf("Comando invalido.\n");
            pausar();
            continue;
        }
        scanf("%*[^\n]");
        getchar();

        if (opcao >= 1 && opcao <= 4) {
            if (!confirmarOpcao1(opcao)) {
                pausar();
                continue;
            }
        }

        switch (opcao) {
            case 1:
               gerenciarAbelhas();
                break;
            case 2:
                gerenciarSensores();
                break;
            case 3:
               gerenciarRelatorios();
                break;
            case 4:
                printf("Voce saiu.\n");
                saiu = 1;
                break;
            default:
                printf("Comando invalido.\n");
                pausar();
        }
    } while (!saiu);

    return 0;
}

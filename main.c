#include <stdio.h>
#include "functions.h"

int main(void) {
    int ler, saiu = 0;

    do {
        menu();

        if (scanf("%d", &ler) != 1) {
            scanf("%*[^\n]");
            getchar();
            printf("Comando invalido, por favor, tente novamente.\n");
            pausar();
            continue;
        }

        scanf("%*[^\n]");
        getchar();

        if (ler >= 1 && ler <= 4) {
            if (!confirmarOpcao1(ler)) {
                pausar();
                continue;
            }
        }

        switch (ler) {
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
                printf("Comando invalido, por favor, tente novamente.\n");
                pausar();
        }
    } while (saiu == 0);

    return 0;
}

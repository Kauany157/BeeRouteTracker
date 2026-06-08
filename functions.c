#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

Abelha abelhas[MAX_ABELHAS];
Sensor sensores[MAX_SENSORES];

int qtdAbelhas = 0;
int qtdSensores = 0;

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void lerTexto(char texto[], int tamanho) {
    fgets(texto, tamanho, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}

void menu() {
    limpar_tela();
    printf("===== SISTEMA BEEROUTE TRACKER =====\n");
    printf("1. Gerenciar Abelhas\n");
    printf("2. Gerenciar Sensores\n");
    printf("3. Relatorios\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

int confirmarOpcao1(int opcao) {
    char confirmacao;

    printf("Voce quer mesmo ");
    switch (opcao) {
        case 1:
            printf("acessar Gerenciar Abelhas");
            break;
        case 2:
            printf("acessar Gerenciar Sensores");
            break;
        case 3:
            printf("acessar Relatorios");
            break;
        case 4:
            printf("sair");
            break;
        default:
            return 1;
    }

    printf("? (Y/N): ");

    while (1) {
        scanf(" %c", &confirmacao);
        limparBuffer();

        if (confirmacao == 'Y' || confirmacao == 'y') {
            return 1;
        } else if (confirmacao == 'N' || confirmacao == 'n') {
            printf("Operacao cancelada.\n");
            return 0;
        } else {
            printf("Digite uma opcao valida. (Y/N): ");
        }
    }
}

void manageAbelhas_menu() {
    limpar_tela();
    printf("===== GERENCIAR ABELHAS =====\n");
    printf("6. Cadastrar Abelha\n");
    printf("7. Listar Todas\n");
    printf("8. Buscar por Nome Popular\n");
    printf("9. Alterar Dados\n");
    printf("10. Remover\n");
    printf("11. Voltar\n");
    printf("Escolha uma opcao: ");
}

void manageSensores_menu() {
    limpar_tela();
    printf("===== GERENCIAR SENSORES =====\n");
    printf("6. Cadastrar Sensor\n");
    printf("7. Listar Sensores\n");
    printf("8. Buscar por ID da Abelha\n");
    printf("9. Alterar Leitura\n");
    printf("10. Remover\n");
    printf("11. Voltar\n");
    printf("Escolha uma opcao: ");
}

void manageRelatorios_menu() {
    limpar_tela();
    printf("===== RELATORIOS =====\n");
    printf("4. Media Geral de Producao de Mel\n");
    printf("5. Media de Temperatura dos Sensores\n");
    printf("6. Quantidade de Abelhas por Regiao\n");
    printf("7. Distancia Total Percorrida\n");
    printf("8. Regiao Mais Produtiva\n");
    printf("9. Relatorio Comparativo por Regioes\n");
    printf("10. Voltar\n");
    printf("Escolha uma opcao: ");
}

int procurarAbelhaPorId(Abelha abelhas[], int qtdAbelhas, int id) {
    for (int i = 0; i < qtdAbelhas; i++) {
        if (abelhas[i].id == id) {
            return i;
        }
    }
    return -1;
}

void atualizarIdsAbelhas(Abelha abelhas[], int qtdAbelhas) {
    for (int i = 0; i < qtdAbelhas; i++) {
        abelhas[i].id = i + 1;
    }
}

void atualizarIdsSensores(Sensor sensores[], int qtdSensores) {
    for (int i = 0; i < qtdSensores; i++) {
        sensores[i].id = i + 1;
    }
}

void gerenciarAbelhas(Abelha abelhas[], int *qtdAbelhas, Sensor sensores[], int *qtdSensores) {
    int opcao;

    do {
        manageAbelhas_menu();

        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("Comando invalido.\n");
            pausar();
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 6:
                cadastrarAbelha(abelhas, qtdAbelhas);
                break;
            case 7:
                listarAbelhas(abelhas, *qtdAbelhas);
                break;
            case 8:
                buscarAbelhaPorNome(abelhas, *qtdAbelhas);
                break;
            case 9:
                alterarAbelha(abelhas, *qtdAbelhas);
                break;
            case 10:
                removerAbelha(abelhas, qtdAbelhas, sensores, qtdSensores);
                break;
            case 11:
                return;
            default:
                printf("Opcao invalida.\n");
        }

        pausar();
    } while (opcao != 11);
}

void gerenciarSensores(Sensor sensores[], int *qtdSensores, Abelha abelhas[], int qtdAbelhas) {
    int opcao;

    do {
        manageSensores_menu();

        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("Comando invalido.\n");
            pausar();
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 6:
                cadastrarSensor(sensores, qtdSensores, abelhas, qtdAbelhas);
                break;
            case 7:
                listarSensores(sensores, *qtdSensores);
                break;
            case 8:
                buscarSensorPorIdAbelha(sensores, *qtdSensores);
                break;
            case 9:
                alterarSensor(sensores, *qtdSensores);
                break;
            case 10:
                removerSensor(sensores, qtdSensores);
                break;
            case 11:
                return;
            default:
                printf("Opcao invalida.\n");
        }

        pausar();
    } while (opcao != 11);
}

void gerenciarRelatorios(Abelha abelhas[], int qtdAbelhas, Sensor sensores[], int qtdSensores) {
    int opcao;

    do {
        manageRelatorios_menu();

        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("Comando invalido.\n");
            pausar();
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 4:
                mediaProducaoMel(abelhas, qtdAbelhas);
                break;
            case 5:
                mediaTemperaturaSensores(sensores, qtdSensores);
                break;
            case 6:
                quantidadeAbelhasPorRegiao(abelhas, qtdAbelhas);
                break;
            case 7:
                relatorioDistanciaTotal(abelhas, qtdAbelhas);
                break;
            case 8:
                relatorioRegiaoMaisProdutiva(abelhas, qtdAbelhas);
                break;
            case 9:
                relatorioComparativoRegioes(abelhas, qtdAbelhas);
                break;
            case 10:
                return;
            default:
                printf("Opcao invalida.\n");
        }

        pausar();
    } while (opcao != 10);
}

void cadastrarAbelha(void) {
    if (*qtdAbelhas >= MAX_ABELHAS) {
        printf("Limite maximo de abelhas atingido.\n");
        return;
    }

    Abelha nova;
    nova.id = *qtdAbelhas + 1;

    printf("Nome popular: ");
    lerTexto(nova.nomePopular, 40);

    printf("Nome cientifico: ");
    lerTexto(nova.nomeCientifico, 50);

    printf("Regiao: ");
    lerTexto(nova.regiao, 30);

    printf("Producao media de mel (kg/mes): ");
    scanf("%f", &nova.producaoMel);
    limparBuffer();

    printf("Distancia percorrida na coleta (km): ");
    scanf("%f", &nova.distanciaColeta);
    limparBuffer();

    nova.IA = 0;

    abelhas[*qtdAbelhas] = nova;
    (*qtdAbelhas)++;

    printf("Abelha cadastrada com sucesso.\n");
}

void listarAbelhas(void) {
    if (qtdAbelhas == 0) {
        printf("Nenhuma abelha cadastrada.\n");
        return;
    }

    printf("===== LISTA DE ABELHAS =====\n");

    for (int i = 0; i < qtdAbelhas; i++) {
        printf("\nID: %d\n", abelhas[i].id);
        printf("Nome popular: %s\n", abelhas[i].nomePopular);
        printf("Nome cientifico: %s\n", abelhas[i].nomeCientifico);
        printf("Regiao: %s\n", abelhas[i].regiao);
        printf("Producao de mel: %.2f kg/mes\n", abelhas[i].producaoMel);
        printf("Distancia de coleta: %.2f km\n", abelhas[i].distanciaColeta);
    }
}

void buscarAbelhaPorNome(void) {
    char nome[40];
    int encontrou = 0;

    printf("Digite o nome popular para buscar: ");
    lerTexto(nome, 40);

    for (int i = 0; i < qtdAbelhas; i++) {
        if (strcmp(abelhas[i].nomePopular, nome) == 0) {
            printf("\nID: %d\n", abelhas[i].id);
            printf("Nome popular: %s\n", abelhas[i].nomePopular);
            printf("Nome cientifico: %s\n", abelhas[i].nomeCientifico);
            printf("Regiao: %s\n", abelhas[i].regiao);
            printf("Producao de mel: %.2f kg/mes\n", abelhas[i].producaoMel);
            printf("Distancia de coleta: %.2f km\n", abelhas[i].distanciaColeta);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma abelha encontrada com esse nome.\n");
    }
}

void alterarAbelha(void) {
    int id, pos;

    if (qtdAbelhas == 0) {
        printf("Nenhuma abelha cadastrada.\n");
        return;
    }

    listarAbelhas(abelhas, qtdAbelhas);

    printf("\nDigite o ID da abelha que deseja alterar: ");
    scanf("%d", &id);
    limparBuffer();

    pos = procurarAbelhaPorId(abelhas, qtdAbelhas, id);

    if (pos == -1) {
        printf("Abelha nao encontrada.\n");
        return;
    }

    printf("Novo nome popular: ");
    lerTexto(abelhas[pos].nomePopular, 40);

    printf("Novo nome cientifico: ");
    lerTexto(abelhas[pos].nomeCientifico, 50);

    printf("Nova regiao: ");
    lerTexto(abelhas[pos].regiao, 30);

    printf("Nova producao media de mel (kg/mes): ");
    scanf("%f", &abelhas[pos].producaoMel);
    limparBuffer();

    printf("Nova distancia percorrida na coleta (km): ");
    scanf("%f", &abelhas[pos].distanciaColeta);
    limparBuffer();

    printf("Dados alterados com sucesso.\n");
}

void removerAbelha(void) {
    int id, pos;
    char confirmar;

    if (*qtdAbelhas == 0) {
        printf("Nenhuma abelha cadastrada.\n");
        return;
    }

    listarAbelhas(abelhas, *qtdAbelhas);

    printf("\nDigite o ID da abelha que deseja remover: ");
    scanf("%d", &id);
    limparBuffer();

    pos = procurarAbelhaPorId(abelhas, *qtdAbelhas, id);

    if (pos == -1) {
        printf("Abelha nao encontrada.\n");
        return;
    }

    printf("Deseja realmente remover essa abelha? (Y/N): ");
    scanf(" %c", &confirmar);
    limparBuffer();

    if (confirmar != 'Y' && confirmar != 'y') {
        printf("Remocao cancelada.\n");
        return;
    }

    for (int i = pos; i < *qtdAbelhas - 1; i++) {
        abelhas[i] = abelhas[i + 1];
    }

    (*qtdAbelhas)--;
    atualizarIdsAbelhas(abelhas, *qtdAbelhas);

    for (int i = 0; i < *qtdSensores; i++) {
        if (sensores[i].idAbelha == id) {
            for (int j = i; j < *qtdSensores - 1; j++) {
                sensores[j] = sensores[j + 1];
            }
            (*qtdSensores)--;
            i--;
        } else if (sensores[i].idAbelha > id) {
            sensores[i].idAbelha--;
        }
    }

    atualizarIdsSensores(sensores, *qtdSensores);

    printf("Abelha removida com sucesso.\n");
}

void cadastrarSensor(Sensor sensores[], int *qtdSensores, Abelha abelhas[], int qtdAbelhas) {
    Sensor novo;
    int idAbelha;

    if (*qtdSensores >= MAX_SENSORES) {
        printf("Limite maximo de sensores atingido.\n");
        return;
    }

    if (qtdAbelhas == 0) {
        printf("Cadastre uma abelha antes de cadastrar sensores.\n");
        return;
    }

    listarAbelhas(abelhas, qtdAbelhas);

    printf("\nDigite o ID da abelha vinculada: ");
    scanf("%d", &idAbelha);
    limparBuffer();

    if (procurarAbelhaPorId(abelhas, qtdAbelhas, idAbelha) == -1) {
        printf("ID de abelha invalido.\n");
        return;
    }

    novo.id = *qtdSensores + 1;

    printf("Tipo do sensor (temperatura, umidade ou luminosidade): ");
    lerTexto(novo.tipo, 30);

    printf("Valor da leitura: ");
    scanf("%f", &novo.valor);
    limparBuffer();

    novo.idAbelha = idAbelha;
    novo.Abelha = 0;

    sensores[*qtdSensores] = novo;
    (*qtdSensores)++;

    printf("Sensor cadastrado com sucesso.\n");
}

void listarSensores(Sensor sensores[], int qtdSensores) {
    if (qtdSensores == 0) {
        printf("Nenhum sensor cadastrado.\n");
        return;
    }

    printf("===== LISTA DE SENSORES =====\n");

    for (int i = 0; i < qtdSensores; i++) {
        printf("\nID do sensor: %d\n", sensores[i].id);
        printf("Tipo: %s\n", sensores[i].tipo);
        printf("Valor: %.2f\n", sensores[i].valor);
        printf("ID da abelha vinculada: %d\n", sensores[i].idAbelha);
    }
}

void buscarSensorPorIdAbelha(Sensor sensores[], int qtdSensores) {
    int idAbelha;
    int encontrou = 0;

    printf("Digite o ID da abelha: ");
    scanf("%d", &idAbelha);
    limparBuffer();

    for (int i = 0; i < qtdSensores; i++) {
        if (sensores[i].idAbelha == idAbelha) {
            printf("\nID do sensor: %d\n", sensores[i].id);
            printf("Tipo: %s\n", sensores[i].tipo);
            printf("Valor: %.2f\n", sensores[i].valor);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum sensor encontrado para essa abelha.\n");
    }
}

void alterarSensor(Sensor sensores[], int qtdSensores) {
    int id, pos = -1;

    if (qtdSensores == 0) {
        printf("Nenhum sensor cadastrado.\n");
        return;
    }

    listarSensores(sensores, qtdSensores);

    printf("\nDigite o ID do sensor que deseja alterar: ");
    scanf("%d", &id);
    limparBuffer();

    for (int i = 0; i < qtdSensores; i++) {
        if (sensores[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Sensor nao encontrado.\n");
        return;
    }

    printf("Novo tipo do sensor: ");
    lerTexto(sensores[pos].tipo, 30);

    printf("Nova leitura: ");
    scanf("%f", &sensores[pos].valor);
    limparBuffer();

    printf("Sensor alterado com sucesso.\n");
}

void removerSensor(Sensor sensores[], int *qtdSensores) {
    int id, pos = -1;
    char confirmar;

    if (*qtdSensores == 0) {
        printf("Nenhum sensor cadastrado.\n");
        return;
    }

    listarSensores(sensores, *qtdSensores);

    printf("\nDigite o ID do sensor que deseja remover: ");
    scanf("%d", &id);
    limparBuffer();

    for (int i = 0; i < *qtdSensores; i++) {
        if (sensores[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Sensor nao encontrado.\n");
        return;
    }

    printf("Deseja realmente remover esse sensor? (Y/N): ");
    scanf(" %c", &confirmar);
    limparBuffer();

    if (confirmar != 'Y' && confirmar != 'y') {
        printf("Remocao cancelada.\n");
        return;
    }

    for (int i = pos; i < *qtdSensores - 1; i++) {
        sensores[i] = sensores[i + 1];
    }

    (*qtdSensores)--;
    atualizarIdsSensores(sensores, *qtdSensores);

    printf("Sensor removido com sucesso.\n");
}

void mediaProducaoMel(Abelha abelhas[], int qtdAbelhas) {
    float soma = 0;

    if (qtdAbelhas == 0) {
        printf("Nenhuma abelha cadastrada.\n");
        return;
    }

    for (int i = 0; i < qtdAbelhas; i++) {
        soma += abelhas[i].producaoMel;
    }

    printf("Media geral de producao de mel: %.2f kg/mes\n", soma / qtdAbelhas);
}

void mediaTemperaturaSensores(Sensor sensores[], int qtdSensores) {
    float soma = 0;
    int qtdTemperatura = 0;

    for (int i = 0; i < qtdSensores; i++) {
        if (strcmp(sensores[i].tipo, "temperatura") == 0 || strcmp(sensores[i].tipo, "Temperatura") == 0) {
            soma += sensores[i].valor;
            qtdTemperatura++;
        }
    }

    if (qtdTemperatura == 0) {
        printf("Nenhum sensor de temperatura cadastrado.\n");
        return;
    }

    printf("Media de temperatura dos sensores: %.2f\n", soma / qtdTemperatura);
}

void quantidadeAbelhasPorRegiao(Abelha abelhas[], int qtdAbelhas) {
    int jaContada;

    if (qtdAbelhas == 0) {
        printf("Nenhuma abelha cadastrada.\n");
        return;
    }

    printf("===== QUANTIDADE DE ABELHAS POR REGIAO =====\n");

    for (int i = 0; i < qtdAbelhas; i++) {
        jaContada = 0;

        for (int j = 0; j < i; j++) {
            if (strcmp(abelhas[i].regiao, abelhas[j].regiao) == 0) {
                jaContada = 1;
                break;
            }
        }

        if (!jaContada) {
            int contador = 0;

            for (int k = 0; k < qtdAbelhas; k++) {
                if (strcmp(abelhas[i].regiao, abelhas[k].regiao) == 0) {
                    contador++;
                }
            }

            printf("Regiao: %s | Quantidade: %d\n", abelhas[i].regiao, contador);
        }
    }
}

void relatorioDistanciaTotal(Abelha abelhas[], int qtdAbelhas) {
    float total = 0;

    if (qtdAbelhas == 0) {
        printf("Nenhuma abelha cadastrada.\n");
        return;
    }

    for (int i = 0; i < qtdAbelhas; i++) {
        total += abelhas[i].distanciaColeta;
    }

    printf("Distancia total percorrida nas coletas: %.2f km\n", total);
}

void relatorioRegiaoMaisProdutiva(Abelha abelhas[], int qtdAbelhas) {
    char melhorRegiao[30];
    float maiorProducao = -1;

    if (qtdAbelhas == 0) {
        printf("Nenhuma abelha cadastrada.\n");
        return;
    }

    for (int i = 0; i < qtdAbelhas; i++) {
        int jaVerificada = 0;
        float somaRegiao = 0;

        for (int j = 0; j < i; j++) {
            if (strcmp(abelhas[i].regiao, abelhas[j].regiao) == 0) {
                jaVerificada = 1;
                break;
            }
        }

        if (!jaVerificada) {
            for (int k = 0; k < qtdAbelhas; k++) {
                if (strcmp(abelhas[i].regiao, abelhas[k].regiao) == 0) {
                    somaRegiao += abelhas[k].producaoMel;
                }
            }

            if (somaRegiao > maiorProducao) {
                maiorProducao = somaRegiao;
                strcpy(melhorRegiao, abelhas[i].regiao);
            }
        }
    }

    printf("Regiao mais produtiva: %s\n", melhorRegiao);
    printf("Producao total da regiao: %.2f kg/mes\n", maiorProducao);
}

void relatorioComparativoRegioes(Abelha abelhas[], int qtdAbelhas) {
    if (qtdAbelhas == 0) {
        printf("Nenhuma abelha cadastrada.\n");
        return;
    }

    printf("===== RELATORIO COMPARATIVO POR REGIOES =====\n");

    for (int i = 0; i < qtdAbelhas; i++) {
        int jaVerificada = 0;
        int quantidade = 0;
        float producaoTotal = 0;
        float distanciaTotal = 0;

        for (int j = 0; j < i; j++) {
            if (strcmp(abelhas[i].regiao, abelhas[j].regiao) == 0) {
                jaVerificada = 1;
                break;
            }
        }

        if (!jaVerificada) {
            for (int k = 0; k < qtdAbelhas; k++) {
                if (strcmp(abelhas[i].regiao, abelhas[k].regiao) == 0) {
                    quantidade++;
                    producaoTotal += abelhas[k].producaoMel;
                    distanciaTotal += abelhas[k].distanciaColeta;
                }
            }

            printf("\nRegiao: %s\n", abelhas[i].regiao);
            printf("Quantidade de abelhas: %d\n", quantidade);
            printf("Producao total: %.2f kg/mes\n", producaoTotal);
            printf("Media de producao: %.2f kg/mes\n", producaoTotal / quantidade);
            printf("Distancia total: %.2f km\n", distanciaTotal);
            printf("Media de distancia: %.2f km\n", distanciaTotal / quantidade);
        }
    }
}

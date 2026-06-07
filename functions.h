#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_ABELHAS 50
#define MAX_SENSORES 100

typedef struct {
    int id;
    char tipo[30];
    float valor;
    int idAbelha;
    int Abelha;
} Sensor;

typedef struct {
    int id;
    char nomePopular[40];
    char nomeCientifico[50];
    char regiao[30];
    float producaoMel;
    float distanciaColeta;
    int IA;
} Abelha;

typedef struct {
    int option;
} Menu;

void limpar_tela(void);
void pausar(void);
void menu(void);
int confirmarOpcao1(int opcao);
void manageAbelhas_menu(void);
void manageSensores_menu(void);
void manageRelatorios_menu(void);

void gerenciarAbelhas(Abelha abelhas[], int *qtdAbelhas, Sensor sensores[], int *qtdSensores);
void gerenciarSensores(Sensor sensores[], int *qtdSensores, Abelha abelhas[], int qtdAbelhas);
void gerenciarRelatorios(Abelha abelhas[], int qtdAbelhas, Sensor sensores[], int qtdSensores);

void cadastrarAbelha(Abelha abelhas[], int *qtdAbelhas);
void listarAbelhas(Abelha abelhas[], int qtdAbelhas);
void buscarAbelhaPorNome(Abelha abelhas[], int qtdAbelhas);
void alterarAbelha(Abelha abelhas[], int qtdAbelhas);
void removerAbelha(Abelha abelhas[], int *qtdAbelhas, Sensor sensores[], int *qtdSensores);

void cadastrarSensor(Sensor sensores[], int *qtdSensores, Abelha abelhas[], int qtdAbelhas);
void listarSensores(Sensor sensores[], int qtdSensores);
void buscarSensorPorIdAbelha(Sensor sensores[], int qtdSensores);
void alterarSensor(Sensor sensores[], int qtdSensores);
void removerSensor(Sensor sensores[], int *qtdSensores);

void mediaProducaoMel(Abelha abelhas[], int qtdAbelhas);
void mediaTemperaturaSensores(Sensor sensores[], int qtdSensores);
void quantidadeAbelhasPorRegiao(Abelha abelhas[], int qtdAbelhas);
void relatorioDistanciaTotal(Abelha abelhas[], int qtdAbelhas);
void relatorioRegiaoMaisProdutiva(Abelha abelhas[], int qtdAbelhas);
void relatorioComparativoRegioes(Abelha abelhas[], int qtdAbelhas);

#endif

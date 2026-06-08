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

void gerenciarAbelhas(void);
void gerenciarSensores(void);
void gerenciarRelatorios(void);

void cadastrarAbelha(void);
void listarAbelhas(void);
void buscarAbelhaPorNome(void);
void alterarAbelha(void);
void removerAbelha(void);

void cadastrarSensor(void);
void listarSensores(void);
void buscarSensorPorIdAbelha(void);
void alterarSensor(void);
void removerSensor(void);

void mediaProducaoMel(void);
void mediaTemperaturaSensores(void);
void quantidadeAbelhasPorRegiao(void);
void relatorioDistanciaTotal(void);
void relatorioRegiaoMaisProdutiva(void);
void relatorioComparativoRegioes(void);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char login[30];
    char senha[30];
} pessoa; pessoa p[1];

int numeroMenu;

int main (void) {

    char login[30];
    char senha[30];
    char acesso;
    int rsk = 0;
    char conteudoArquivo[100];

    struct cadastro {
        char nome[250];
        char email[250];
        int dia, mes, ano;
        char cpf[250], telefone[250], cep[250], dataDiagnostico[30];
        char rua[250], numero[250], bairro[250], cidade[250], estado[250], comorbidade[250], quais[250];
    };

    struct cadastro paciente;

    strcpy(p[0].login, "Walter");
    strcpy(p[0].senha, "unip12345");

    printf("\n=================================\n");
    printf(" Sistema de Cadastro de pacientes");
    printf("\n=================================\n");
    printf("LOGIN: ");
    scanf("%s", login);
    printf("SENHA: ");
    scanf("%s", senha);

    if ((strcmp(login, p[0].login) == 0) && (strcmp(senha, p[0].senha) == 0)) {
        printf("Usuário Logado\n\n");
        acesso = 'S';
    }else{
        printf("Login e/ou senha incorretos");
    }

    if (acesso == 'S') {
        system("pause");
        printf("\n\nMENU");
        printf("\n\n1- Cadastrar Pacientes");
        printf("\n2- Listar Pacientes");
        printf("\n3- Sair");
        printf("\n\nDigite uma opcao: ");
        scanf("%d", &numeroMenu);
        FILE *ponteiroArquivoPrincipal;
        switch(numeroMenu)
        {
        case 1:
            system("cls");
            fflush(stdin);
            printf("\n=================================\n");
            printf(" FORMULARIO DE CADASTRO");
            printf("\n=================================\n\n");
            printf("Nome: ");
            fgets(paciente.nome, 250, stdin);
            printf("CPF: ");
            fflush(stdin);
            fgets(paciente.cpf, 250, stdin);
            printf("Data de Nascimento");
            printf("\nDia: ");
            fflush(stdin);
            scanf("%02d", &paciente.dia);
            printf("Mes: ");
            fflush(stdin);
            scanf("%02d", &paciente.mes);
            printf("Ano: ");
            fflush(stdin);
            scanf("%d", &paciente.ano);
            printf("Telefone: ");
            fflush(stdin);
            scanf("%s", paciente.telefone);
            printf("Endereco");
            printf("\nRua: ");
            fflush(stdin);
            fgets(paciente.rua, 250, stdin);
            printf("Numero: ");
            fflush(stdin);
            scanf("%s", paciente.numero);
            printf("Bairro: ");
            fflush(stdin);
            fgets(paciente.bairro, 250, stdin);
            printf("Cidade: ");
            fflush(stdin);
            fgets(paciente.cidade, 250, stdin);
            printf("Estado: ");
            fflush(stdin);
            fgets(paciente.estado, 250, stdin);
            printf("E-mail: ");
            fflush(stdin);
            scanf("%s", paciente.email);
            printf("Data do diagnostico: ");
            fflush(stdin);
            scanf(" %30[^\n]s", &paciente.dataDiagnostico);
            setbuf(stdin, NULL);

            printf("O paciente tem alguma comorbidade? [1] SIM ou [2] NAO ");
            scanf("%d", &rsk);
            setbuf(stdin, NULL);

            if (rsk == 1) {
                strcpy(paciente.comorbidade, "SIM");
                printf("Quais? ");
                fflush(stdin);
                fgets(paciente.quais, 250, stdin);

            }else{
                strcpy(paciente.comorbidade, "NAO");
                strcpy(paciente.quais, "Nenhum\n");
            }

            printf("\n");
            ponteiroArquivoPrincipal = fopen("lista.txt", "a");
            fprintf(ponteiroArquivoPrincipal, "Nome: %s", paciente.nome);
            fprintf(ponteiroArquivoPrincipal, "CPF: %s", paciente.cpf);
            fprintf(ponteiroArquivoPrincipal, "Data de Nascimento: %d/%d/%d", paciente.dia, paciente.mes, paciente.ano);
            fprintf(ponteiroArquivoPrincipal, "\nTelefone: %s", paciente.telefone);
            fprintf(ponteiroArquivoPrincipal, "\nEndereço: ");
            fprintf(ponteiroArquivoPrincipal, "\nRua: %s", paciente.rua);
            fprintf(ponteiroArquivoPrincipal, "\nNumero: %s", paciente.numero);
            fprintf(ponteiroArquivoPrincipal, "\nBairro: %s", paciente.bairro);
            fprintf(ponteiroArquivoPrincipal, "\nCidade: %s", paciente.cidade);
            fprintf(ponteiroArquivoPrincipal, "\nEstado: %s", paciente.estado);
            fprintf(ponteiroArquivoPrincipal, "\nE-mail: %s", paciente.email);
            fprintf(ponteiroArquivoPrincipal, "\nData do diagnostico: %s", paciente.dataDiagnostico);
            fprintf(ponteiroArquivoPrincipal, "\nPossui comorbidades? %s", paciente.comorbidade);
            fprintf(ponteiroArquivoPrincipal, "\nQuais? %s", paciente.quais);
            fprintf(ponteiroArquivoPrincipal, "========================================================\n\n");
            fclose(ponteiroArquivoPrincipal);
            break;
        case 2:
            system("cls");
            ponteiroArquivoPrincipal = fopen("lista.txt", "r");

            if (ponteiroArquivoPrincipal == NULL) {
                printf("Nao foi possivel abrir o arquivo.\n");
                getchar();
                exit(0);
            }

            while (fgets(conteudoArquivo, 100, ponteiroArquivoPrincipal) != NULL ){
                printf("%s", conteudoArquivo);
            }

            fclose(ponteiroArquivoPrincipal);
            printf("\n");
            system("pause");
            break;
        case 3:
            system("cls");
            printf("Ate a proxima!\n");
            break;
        default:
            printf("Opcao invalida\n");
        }

    }

    return 0;

}


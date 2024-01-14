/*
TDE Analise de Dados Do IBGE 

Integrantes:
Joaquim Luis Malacarne Lima de Oliveira, 4418365
Davi Sousa Alves, 9071649
Edwin Minoru dos Santos Sasaki, 7782429
Guilherme Souza Santos, 7329394
Gustavo Santiago de Almeida, 3754665
Raul Santos da Silva, 8883414
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void alinhar(float num[], int qnt) //alinha os valores em float em ordem crescente
{
    int x, y;
    float ordem;

    for (x = 0; x < qnt - 1; x++) {
        for (y = 0; y < qnt - 1 - x; y++) 
        {
            if (num[y] < num[y + 1]) 
            {
                ordem = num[y];
                num[y] = num[y + 1];
                num[y + 1] = ordem;
            }
        }
    }
}

void swicths(escolha) //junto ao menu possibilita voltar ou fechar o programa
{
    switch (escolha) 
                    {
                case 1:
                break;

                case 2:
                break;

                case 3:
                break;

                default:
                 printf("Escolha invalida tente novamente!!\n");
                break;
             }
}

int lerLinha(char paragrafo[], int tamanho, int linha)// pega todo o texto da linha escolida
{
    FILE* arquivo;
    arquivo = fopen("niveis_bacias.csv", "r");

    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int contador = 1;
    while (fgets(paragrafo, tamanho, arquivo) != NULL)
    {
        if (contador == linha) {
            break;
        }
        contador++;
    }

    fclose(arquivo);
}

void pegarvariavel(char objetivo[][100], int coluna) // pega a variavel da coluna escrita e armazena no vetor char
{
    FILE *arquivo;
    arquivo = fopen("niveis_bacias.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char *token;
    char linha[800];
    int i = 0, j = 0;

    fgets(linha, 800, arquivo);

    while (fgets(linha, 800, arquivo) != NULL) {
        token = strtok(linha, ";");
        while (token != NULL) {
            strcpy(objetivo[i], token);
            token = strtok(NULL, ";");
            if (j == coluna) {
                j = 0;
                i++;
                break;
            }
            j++;
        }
    }

    fclose(arquivo);
}

void pulalinha() //pula linha e deixa mais bonitinho
{
    printf("\n");
    printf("+----------------------------|-|----------------------------+\n");
    printf("\n");
}

void menu() // printa o menu de saida
{
    printf("\n+-----------------SAIR?-----------------+\n");
    printf("|                                       |\n");
    printf("|[1] Para voltar ao Menu inicial        |\n");
    printf("|[2] Sair                               |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n");
}

void inicio() // printa o menu inicial
{
    printf("+------------------TDE------------------+\n");
    printf("|                                       |\n");
    printf("|[1] Entrar com Codigo Otto             |\n");
    printf("|[2] Processamento                      |\n");
    printf("|[3] Para sair                          |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n");
}

void header() // printa o menu de processamento
{
    printf("+-----------TDE-Processamento-----------+\n");
    printf("|                                       |\n");
    printf("|[1] As 5 bacias de maiores areas       |\n");
    printf("|[2] As 5 bacias de menores areas       |\n");
    printf("|[3] As 5 bacias de maiores Populacao   |\n");
    printf("|[4] As 5 bacias de menores Populacao   |\n");
    printf("|[5] Para sair                          |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n");
}

void printar(float num[], char nome[][100], int ponteiro[], int qnt,char frase[]) //printa as bacias 
{
    int i;
    for (i = 0; i < qnt; i++)
    {
        printf("%i: %s com %.0f %s\n\n", i + 1, nome[ponteiro[i]], num[i],frase);
    }
}

int main() 
{ 
//----------------------------||-----------------------------------

            // variaveis do main
    int i = 0, j = 0, k = 0, sair = 0, ponteiro[130], coluna = 0, escolha, linha, Otto,Ottos[130],achouOtto = 0;
    char area[130][100], nome[130][100], populacao[130][100], Ottoscod[130][100], frase[]="", paragrafo[800],descricao[130][100],cabecalho[130][100];
    float comparacao1[130], comparacao2[130];
    FILE *saida;

//----------------------------||-----------------------------------

    do // roda o swicth principal ate sair
    {
        i = 0, j = 0, k = 0, sair = 0, coluna = 0,achouOtto = 0;

        system("cls");
        inicio();
        printf("[R]=");
        scanf("%i", &escolha);

        if ((escolha < 0) || (escolha > 3))
        {
            do 
                {
                    printf("Escolha invalida tente novamente!!\n");
                    printf("[R]=");
                    scanf("%i", &escolha);
                    
                } 
                while ((escolha < 0) || (escolha > 3));
        }
//----------------------------||-----------------------------------

      switch (escolha)
        {
        case 1://entrar com codigo Otto

    system("cls");
    printf("+----------------TDE-Entrada--------------+\n");
    printf("|                                         |\n");
    printf("| DIgite o Codigo Otto da Bacia escolhida |\n");
    printf("|                                         |\n");
    printf("+-----------------------------------------+\n");

        
        pegarvariavel(nome,3);
        pegarvariavel(Ottoscod, 1);

        printf("[R]=");
        scanf("%i", &Otto);

            

            for (i = 0; i < 129; i++)
            {
                 Ottos[i] = atoi(Ottoscod[i]);
                if (Ottos[i] == Otto)
                {
                    linha = i;
                    achouOtto++;
                }
            }

            if (achouOtto == 0)
            {
                do
                {
                printf("Codigo invalido tente outro\n");
                printf("[R]=");
                scanf("%i", &Otto);
                    for (i = 0; i < 129; i++)
                    {
                     Ottos[i] = atoi(Ottoscod[i]); //compara se o cod digitado existe no arquivo
                     if (Ottos[i] == Otto)
                    {
                         linha = i;
                         achouOtto++;
                     }
                    }
                } while (achouOtto != 1);
                
            }
            
            lerLinha(paragrafo, 800, linha + 2);//pega todo o texto da linha q o codigo otto foi achado
            k = 0;
            i = 0;
            j = 0;
           while (paragrafo[i] != '\0')
    {
        if (paragrafo[i] != ';')
        {
            descricao[k][j] = paragrafo[i];
            i++;
            j++;
        }
        else
        {
            descricao[k][i] = '\0';
            k++;
            i++;
            j = 0;
        }
    }

    lerLinha(paragrafo, 800, 1);//pega o cabeçalho
    k = 0;
    i = 0;
    j = 0;
           while (paragrafo[i] != '\0')
    {
        if (paragrafo[i] != ';')
        {
            cabecalho[k][j] = paragrafo[i];
            i++;
            j++;
        }
        else
        {
            cabecalho[k][i] = '\0';
            k++;
            i++;
            j = 0;
        }
    }

    system("cls"); 
    
            for (i = 0; i < 34; i++)
            {
                printf("*%s\n", cabecalho[i]);//printa os dois
                printf("%s\n", descricao[i]);
                printf("\n");
            }


            pulalinha();

    printf("\n+-----------------SAIR?-----------------+\n");
    printf("|                                       |\n");
    printf("|[1] Para voltar ao Menu inicial        |\n");
    printf("|[2] Imprimir dados                     |\n");
    printf("|[3] Sair                               |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n");

                do 
                {
                    printf("[R]=");
                    scanf("%i", &escolha);
                    swicths(escolha);
                    
                } 
                while ((escolha < 0) || (escolha > 3));

            if (escolha == 3)
                {
                    sair++;
                }
            if (escolha == 2)
                {
                    saida = fopen("BaciaOtto.csv", "w");  

                     if(saida == NULL) 
                    {
                         printf("Erro ao tentar abrir o arquivo de saida !\n");
                        return 2;
                    } 

                    for (i = 0; i < 34; i++)
            {
                fprintf(saida,"*%s\n", cabecalho[i]);//printa no arquivo novo todas as informações da bacia
                fprintf(saida,"%s\n", descricao[i]);
                fprintf(saida,"\n");
                
            }
                fclose(saida);

                }

            break;

//----------------------------||-----------------------------------

        case 2://aba de processamentos

        system("cls");
        header();
        printf("[R]=");
        scanf("%i", &escolha);

        if ((escolha < 0) || (escolha > 5))
        {
            do
        {
            printf("Escolha invalida tente novamente!!\n");
            printf("[R]=");
            scanf("%i", &escolha);
        } while ((escolha < 0) || (escolha > 5));

        }
       
            switch (escolha) 
        {
        
//----------------------------||-----------------------------------

            case 1:// maiores areas
                pegarvariavel(area, 10);
                pegarvariavel(nome, 3);
                for (i = 0; i < 129; i++) 
                {
                    comparacao1[i] = atof(area[i]); //transforma em float e armazena em dois vetores 
                    comparacao2[i] = comparacao1[i];
                }

                alinhar(comparacao1, 129);
                system("cls");

                for (i = 0; i < 5; i++) // compara a coluna de numeros original com a de 5 maiores 
                {
                    for (k = 0; k < 129; k++) 
                    {
                        if (comparacao1[i] == comparacao2[k]) 
                        {
                            ponteiro[j] = k;
                            j++;
                        }
                    }
                }

                pulalinha();
                printf("Maiores Bacias Hidrograficas em area territorial:\n");
                printf("\n");
                strcpy(frase, "km quadrado");
                printar(comparacao1, nome, ponteiro, 5,frase);
                pulalinha();
                menu();

                do 
                {
                    printf("[R]=");
                    scanf("%i", &escolha);
                    swicths(escolha);
                } 
                while ((escolha < 0) || (escolha > 2));
                
                if (escolha == 2)
                {
                    sair++;
                }

                break;

//----------------------------||-----------------------------------

            case 2: //menores areas

                pegarvariavel(area, 10);
                pegarvariavel(nome, 3);
                for (i = 0; i < 129; i++) 
                {
                    comparacao1[i] = atof(area[i]); //transforma em float e armazena em dois vetores 
                    comparacao2[i] = comparacao1[i];
                }
                
                alinhar(comparacao1, 129);
                system("cls");

                for (i = 129; i > 123; i--) // compara a coluna de numeros original com a de 5 maiores 
                {
                    for (k = 0; k < 129; k++) 
                    {
                        if (comparacao1[i] == comparacao2[k]) 
                        {
                            ponteiro[j] = k;
                            j++;
                        }
                    }
                }

                pulalinha();
                printf("Menores Bacias Hidrograficas em area territorial:\n");
                printf("\n");
                j = 0;
                for (i = 128; i > 123; i--)
            {
                printf("%i: %s com %.0f km quadrados\n\n", i + 2, nome[ponteiro[j]], comparacao1[i]);
                j++;
            }

                pulalinha();
                menu();

                do 
                {
                    printf("[R]=");
                    scanf("%i", &escolha);
                    swicths(escolha);
                } 
                while ((escolha < 0) || (escolha > 2));

                if (escolha == 2)
                {
                    sair++;
                }

            break;

//----------------------------||-----------------------------------

            case 3:// maiores populações
            
                pegarvariavel(populacao, 22);
                pegarvariavel(nome, 3);
                for (i = 0; i < 129; i++) 
                {
                    comparacao1[i] = atof(populacao[i]); //transforma em float e armazena em dois vetores 
                    comparacao2[i] = comparacao1[i];
                }

                alinhar(comparacao1, 129);
                system("cls");

                for (i = 0; i < 5; i++) // compara a coluna de numeros original com a de 5 maiores 
                {
                    for (k = 0; k < 129; k++) 
                    {
                        if (comparacao1[i] == comparacao2[k]) 
                        {
                            ponteiro[j] = k;
                            j++;
                        }
                    }
                }

                pulalinha();
                printf("Maiores Bacias Hidrograficas em Populacao (2010):\n");
                printf("\n");
                 strcpy(frase, "de pessoas que utilizam a bacia");
                printar(comparacao1, nome, ponteiro, 5,frase);
                pulalinha();
                menu();

                do 
                {
                    printf("[R]=");
                    scanf("%i", &escolha);
                    swicths(escolha);
                } 
                while ((escolha < 0) || (escolha > 2));

                if (escolha == 2)
                {
                    sair++;
                }

                break;
                
                break;

            case 4:
                
                pegarvariavel(populacao, 22);
                pegarvariavel(nome, 3);
                for (i = 0; i < 129; i++) 
                {
                    comparacao1[i] = atof(populacao[i]); //transforma em float e armazena em dois vetores 
                    comparacao2[i] = comparacao1[i];
                }
                
                alinhar(comparacao1, 129);
                system("cls");

                for (i = 129; i > 123; i--) // compara a coluna de numeros original com a de 5 maiores 
                {
                    for (k = 0; k < 129; k++) 
                    {
                        if (comparacao1[i] == comparacao2[k]) 
                        {
                            ponteiro[j] = k;
                            j++;
                        }
                    }
                }

                pulalinha();
                printf("Menores numeros de populacao das Bacias (2010):\n");
                printf("\n");
                j = 0;
                for (i = 128; i > 123; i--)
            {
                printf("%i: %s com %.0f pessoas que utilizam a bacia\n\n", i + 2, nome[ponteiro[j]], comparacao1[i]);
                j++;
            }

                pulalinha();
                menu();

                do 
                {
                    printf("[R]=");
                    scanf("%i", &escolha);
                    swicths(escolha);
                } 
                while ((escolha < 0) || (escolha > 2));

                if (escolha == 2)
                {
                    sair++;
                }

            break;

//----------------------------||-----------------------------------            

            case 5:
                sair++;
                break;

            default:
                printf("Escolha invalida tente novamente!!\n");
                break;
        }
        

        break;

        case 3:
            sair++;
        break;

        default:
            break;
        }

    } 
    while (sair == 0);

//----------------------------||-----------------------------------

    // finaliza o programa
    system("cls");

    printf("+-------------TDE-------------+\n");
    printf("|                             |\n");
    printf("|            Davi             |\n");
    printf("|            Edwin            |\n");
    printf("|          Guilherme          |\n");
    printf("|           Gustavo           |\n");
    printf("|           Joaquim           |\n");
    printf("|            Raul             |\n");
    printf("|                             |\n");
    printf("+-----------------------------+\n");

    pulalinha();
    printf("Saindo do Programa, Ate mais!!\n");

    pulalinha();
    return 0;
}


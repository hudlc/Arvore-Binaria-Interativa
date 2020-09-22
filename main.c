#include "funcoes.h"
int main()
{
    Arvore *arv1 = NULL;
    int op,i;
    srand(time(NULL));
    while(1)
    {
        printf("Arvore Binaria Interativa!\n");
        printf("1-Insere numero\n");
        printf("2-Preencher arvore\n");
        printf("3-Remove Numero\n");
        printf("4-Busca numero\n");
        printf("5-Imprime em ordem crescente\n");
        scanf("%d",&op);
        if(op == 1)
        {
            printf("Insira o numero desejado\n");
            scanf("%d,",&i);
            arv1 = inserir(arv1,i);
            system("cls");
        }
        else if(op == 2)
        {
            i = 0;
            for(i; i<100; i++)
            {
                arv1 = inserir(arv1,(rand()%250));
            }
            system("cls");
            printf("100 valores inseridos!\n-----\n");
        }
        else if (op == 3)
        {
            printf("Qual numero?\n");
            scanf("%d",&i);
            remove_arv (arv1,i);
            system("cls");
            printf("%d removido!\n-----\n",i);
        }
        else if (op == 4)
        {
            printf("Qual numero?\n");
            scanf ("%d",&i);
            if(buscaNum(arv1,i))
            {
                system("cls");
                printf("Numero achado!\n-----\n");
            }
            else
            {
                system("cls");
                printf("Numero nao achado!\n-----\n");
            }
        }
        else if (op == 5)
        {

            system("cls");
            imprimeCresc(arv1);
            printf("\n-------\n");

        }


    }
    return 0;
}

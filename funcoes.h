#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int info;
    struct arvore *esq;
    struct arvore *dir;
}Arvore;

Arvore* inserir (Arvore *a, int n)
{
    if(a == NULL)
    {
        //Caso o n� atual esteja vazio,
        //um n� � alocado, recebe o valor n
        //e retorna seu endere�o
        Arvore *no = (Arvore*)malloc(sizeof(Arvore));
        no->esq = NULL;
        no->dir = NULL;
        no->info = n;
        return no;
    }
    else if(n > a->info)
    {
        //Caso o n� n�o esteja vazio
        //e n seja maior que o valor do n�
        //repete o processo mas com o n� da direita
        a->dir = inserir(a->dir,n);
    }
    else if(n< a->info)
    {
        //O mesmo que a condi��o anterior
        //mas para valor menor e com o n� da esquerda
        a->esq = inserir(a->esq,n);
    }
    else
    {
        //Se n�o for menor, maior, ou vazio
        //� o mesmo n�mero, nesse caso faz nada
        return a;
    }
};
void imprimeCresc (Arvore *a)
{
    if(a != NULL)
    {
        //Utiliza da pilha para visitar
        //primeiro os valores mais a esquerda
        //e imprimir eles primeiro
        imprimeCresc(a->esq);
        printf("%d,",a->info);
        imprimeCresc(a->dir);
    }
}
int buscaNum (Arvore *a, int n)
{


    if (a == NULL)
    {
        return 0;
    }
    else if(a->info == n)
    {
        return 1;
    }
    else if (n > a->info)
    {
        buscaNum(a->dir,n);
    }
    else if (n < a->info)
    {
        buscaNum(a->esq,n);
    }
}
Arvore* remove_arv (Arvore *a, int n)
{
    if (a == NULL)
    {
        return NULL;
    }
    else if(n > a->info)
    {
        a->dir = remove_arv (a->dir,n);
    }
    else if(n < a->info)
    {
        a->esq = remove_arv (a->esq,n);
    }
    else
    {
        //Entra aqui se achou o valor i em um n�
        if(a->esq == NULL && a->dir == NULL)
        {
            //se n�o tem filhos, libera e a recebe null pois n�o tem filhos
            free (a);
            a = NULL;
        }
        else if (a->esq == NULL)
        {
            //Ent�o tem algo na direita mas o da esqueda ta livre
            //salva o que tem na direita num temp
            //atribui o endere�o do atual com o que tem na direita
            //da um free com o que vc salvou no temp
            Arvore* temp = a;
            a = a->dir;
            free (temp);
        }
        else if (a->dir == NULL)
        {
            //Igual o de cima, mas com o esquerdo
            Arvore* temp = a;
            a = a->esq;
            free (temp);
        }
        else
        {
            //Ent�o esse n� tem 2 filhos
            //troca o valor do n� com o menor valor da direita
            //ou troca o valor do n� com o maior valor da esquerda (no caso foi feito esse)
            Arvore* temp = a->esq;
            while (temp->dir != NULL)
            {
                temp = a->dir;
            }
            a->info = temp->info;
            temp->info = n;
            a->esq = remove_arv(a->esq,n); //aqui ele remove o valor duplicado
            free(temp);
        }
    }
    return a;
}


#endif // FUNCOES_H_INCLUDED

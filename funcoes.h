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
        //Caso o nó atual esteja vazio,
        //um nó é alocado, recebe o valor n
        //e retorna seu endereço
        Arvore *no = (Arvore*)malloc(sizeof(Arvore));
        no->esq = NULL;
        no->dir = NULL;
        no->info = n;
        return no;
    }
    else if(n > a->info)
    {
        //Caso o nó não esteja vazio
        //e n seja maior que o valor do nó
        //repete o processo mas com o nó da direita
        a->dir = inserir(a->dir,n);
    }
    else if(n< a->info)
    {
        //O mesmo que a condição anterior
        //mas para valor menor e com o nó da esquerda
        a->esq = inserir(a->esq,n);
    }
    else
    {
        //Se não for menor, maior, ou vazio
        //é o mesmo número, nesse caso faz nada
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
        //Entra aqui se achou o valor i em um nó
        if(a->esq == NULL && a->dir == NULL)
        {
            //se não tem filhos, libera e a recebe null pois não tem filhos
            free (a);
            a = NULL;
        }
        else if (a->esq == NULL)
        {
            //Então tem algo na direita mas o da esqueda ta livre
            //salva o que tem na direita num temp
            //atribui o endereço do atual com o que tem na direita
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
            //Então esse nó tem 2 filhos
            //troca o valor do nó com o menor valor da direita
            //ou troca o valor do nó com o maior valor da esquerda (no caso foi feito esse)
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

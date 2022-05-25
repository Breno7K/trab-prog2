/**************************************************
 *
 * Nome do(a) estudante: Breno Ferreira Rodrigues
 * Trabalho 1
 * Professor(a): Nome do(a) professor(a)
 *
 */

#include <stdio.h>
#define MAX 50

/* Armazena informações de uma capivara */
typedef struct
{
    int numero;    /* Número da capivara = posição na largada */
    int ultrapass; /* Quantidade de ultrapassagens feitas */
} capivara;

/*funçao de troca*/
void troca(capivara *a, capivara *b)
{
    capivara aux = *a;
    *a = *b;
    *b = aux;
}

/*funçao para ordenar por ultapassagem*/

void cap_sort(capivara v[], int p, int r)
{
    int i = p;
    int j = r - 1;
    capivara aux = v[i];

    if (p < r)
    {
        while (i < j)
        {
            while ((v[j].ultrapass <= aux.ultrapass && i < j))
            {
                j--;
            }
            
            v[i] = v[j];

            while (v[i].ultrapass >= aux.ultrapass && i < j)
            {
                i++;
            }
            
            v[j] = v[i];
        }
        

        v[i] = aux;

        cap_sort(v, p, i - 1);
        cap_sort(v, j + 1, r);
    }
}


/*funçao para imprimir numero da capivara*/
void imprimir_cap(capivara v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", v[i].numero);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, x, i;
    capivara capivaras[MAX];

    /*numero de capivaras*/
    scanf("%d", &n);

    /*definindo numero das capivaras e zero para as ultrapassagens*/
    /*evitando problemas com endereço de memória de variaveis vazias e padronizando capivaras*/
    for (i = 0; i < n; i++)
    {
        capivaras[i].numero = i + 1;
        capivaras[i].ultrapass = 0;
    }

    /*registro de ultrapassagem*/
    while (scanf("%d", &x) != EOF)
    {
        /*definindo ordem de chegada*/
        if (x != 0)
        {
            for (i = 0; i < n; i++)
            {
                if (x == capivaras[i].numero)
                {
                    capivaras[i].ultrapass++;
                    troca(&capivaras[i], &capivaras[i - 1]);
                }
            }
        }
    }

    /*primeira saida*/
    imprimir_cap(capivaras, n);
    printf("\n");

    /*ordenando*/
    cap_sort(capivaras, 0, n);

    /*segunda saida*/
    imprimir_cap(capivaras, n);

    return 0;
}

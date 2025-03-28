#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;

struct Comanda_Cofetarie
{
    int id;
    int cantitate;
    float pretBucata;
    char* numeClient;
    char* tipPrajitura;

};
typedef struct Comanda_Cofetarie Comanda;

struct Nod
{
    Comanda info;
    struct Nod* next;
};
typedef struct Nod Nod;

Comanda citireComandaDinFisier(FILE* f)
{
    char buffer[100];
    char sep[3] = ",\n";
    fgets(buffer, 100, f);
    char* aux;
    Comanda c1;
    aux = strtok(buffer, sep);
    c1.id = atoi(aux);

    aux = strtok(NULL, sep);
    c1.numeClient = malloc(strlen(aux) + 1);
    strcpy_s(c1.numeClient, strlen(aux) + 1, aux);

    aux = strtok(NULL, sep);
    c1.tipPrajitura = malloc(strlen(aux) + 1);
    strcpy_s(c1.tipPrajitura, strlen(aux) + 1, aux);

    c1.cantitate = atoi(strtok(NULL, sep));

    c1.pretBucata = atof(strtok(NULL, sep));
    
    return c1;
}


void afisareComanda(Comanda c)
{
    printf("Id: %d\n", c.id);
    printf("Nume client: %s\n", c.numeClient);
    printf("Tip prajitura: %s\n", c.tipPrajitura);
    printf("Cantitate: %d\n", c.cantitate);
    printf("Pret bucata: %.2f\n", c.pretBucata);
}

void afisareListaComanezi(Nod* n)
{
    while (n)
    {
        afisareComanda(n->info);
        n = n->next;
    }
}

void adaugaComandaLaFinalInLista(Nod** lista, Comanda comandaNoua)
{
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    nou->info = comandaNoua;
    nou->next = NULL;
    if (*lista == NULL)
    {
        *lista = nou;
    }
    else
    {
        Nod* aux = (*lista);
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = nou;
    }

}

Nod* citireListaComenziDinFisier(const char* numeFisier)
{
    FILE* f = fopen(numeFisier, "r");
    Nod* lista = NULL;
    while (!feof(f))
    {
        Comanda c;
        c = citireComandaDinFisier(f);
        adaugaComandaLaFinalInLista(&lista, c);
    }
    fclose(f);
    return lista;
}

float totalIncasatDeLaUnClient(Nod* lista, const char* nume)
{
    float sum = 0;
    while (lista!=NULL)
    {
        if (strcmp(lista->info.numeClient, nume) == 0)
        {
            sum += (lista->info.pretBucata * lista->info.cantitate);
        }
        lista = lista->next;
    }
    return sum;

}
float valoareComanda(Comanda c) 
{
    return c.cantitate * c.pretBucata;
}


Comanda comandaCeaMaiScumpa(Nod* lista)
{
    Comanda max = lista->info;
    float maxVal = valoareComanda(max);
    while (lista)
    {
        float val = valoareComanda(lista->info);
        if (val > maxVal)
        {
            maxVal = val;
            max = lista->info;
        }
        lista = lista->next;
    }
    return max;
}

float valoareMedie(Nod* lista)
{
    float sum = 0;
    int count = 0;
    while (lista)
    {
        sum += lista->info.cantitate * lista->info.pretBucata;
        count++;
        lista = lista->next;
    }

    return (count > 0) ? (sum / count) : 0;
}

void dezalocare(Nod** lista)
{
    while (*lista)
    {
        Nod* p = *lista;
        *lista = (*lista)->next;
        free(p->info.numeClient);
        free(p->info.tipPrajitura);
        free(p);
    }
}
int main()
{
    Nod* n;
    n = citireListaComenziDinFisier("comenzi.txt");
    afisareListaComanezi(n);
    printf("\n");
    float sum = totalIncasatDeLaUnClient(n, "Ioana");
    printf("%.2f",sum);
    printf("\n");
    Comanda c1 = comandaCeaMaiScumpa(n);
    afisareComanda(c1);
    printf("\n");
    printf("Valoarea medie este: %.2f", valoareMedie(n));

    dezalocare(&n);
}
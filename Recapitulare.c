#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct CursaAeriana
{
	char* cod;
	char* destinatie;
	char* dataPlecare;
	char* oraPlecare;
	char* status;
};
typedef struct CursaAeriana CursaAeriana;

struct Nod
{
	CursaAeriana info;
	struct Nod* next;
};
typedef struct Nod Nod;

CursaAeriana citireCursaDinFisier(FILE* f)
{
	CursaAeriana c;
	char buffer[255];
	char sep[3] = ",\n";
	fgets(buffer, 255, f);
	char* aux=strtok(buffer,sep);
	c.cod = (char*)malloc(strlen(aux) + 1);
	strcpy_s(c.cod, strlen(aux) + 1, aux);
	aux = strtok(NULL, sep);
	c.destinatie = (char*)malloc(strlen(aux) + 1);
	strcpy_s(c.destinatie, strlen(aux) + 1, aux);
	aux = strtok(NULL, sep);
	c.dataPlecare = (char*)malloc(strlen(aux) + 1);
	strcpy_s(c.dataPlecare, strlen(aux) + 1, aux);
	aux = strtok(NULL, sep);
	c.oraPlecare = (char*)malloc(strlen(aux) + 1);
	strcpy_s(c.oraPlecare, strlen(aux) + 1, aux);
	aux = strtok(NULL, sep);
	c.status = (char*)malloc(strlen(aux) + 1);
	strcpy_s(c.status, strlen(aux) + 1, aux);
	return c;
}

void afisareCursaAeriana(CursaAeriana c)
{
	printf("Cod: %s\n", c.cod);
	printf("Destinatie: %s\n", c.destinatie);
	printf("Data plecare: %s\n", c.dataPlecare);
	printf("Ora plecare:  %s\n", c.oraPlecare);
	printf("Status: %s\n", c.status);
}

void afisareLista(Nod* lista)
{
	while (lista)
	{
		afisareCursaAeriana(lista->info);
		lista = lista->next;
	}
}

void adaugaInLista(Nod** lista, CursaAeriana cNou)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = cNou;
	nou->next = NULL;
	if (*lista)
	{
		Nod* aux = (*lista);
		while (aux->next)
		{
			aux = aux->next;
		}
		aux->next = nou;
	}
	else
	{
		(*lista) = nou;
	}
}


Nod* citireListaDinFisier(const char* numeFisier)
{
	FILE* f = fopen(numeFisier, "r");
	Nod* lista = NULL;
	while (!feof(f))
	{
		CursaAeriana c = citireCursaDinFisier( f);
		adaugaInLista(&lista, c);
	}
	fclose(f);
	return lista;
}

void stergereCurseCuAcelasiStatus(Nod** lista, const char* statusCautat)
{
	Nod* anterior = NULL;
	Nod* curent = *lista;

	while (curent)
	{
		if (strcmp(curent->info.status, statusCautat) == 0)
		{
			Nod* deSters = curent;
			if (anterior == NULL) 
			{
				*lista = curent->next;
			}
			else 
			{
				anterior->next = curent->next;
			}
			curent = curent->next;

			free(deSters->info.cod);
			free(deSters->info.destinatie);
			free(deSters->info.dataPlecare);
			free(deSters->info.oraPlecare);
			free(deSters->info.status);
			free(deSters);
		}
		else 
		{
			anterior = curent;
			curent = curent->next;
		}
	}
}

void dezalocareLista(Nod** lista) 
{
	while (*lista) 
	{
		Nod* temp = *lista;
		*lista = (*lista)->next;
		free(temp->info.cod);
		free(temp->info.destinatie);
		free(temp->info.dataPlecare);
		free(temp->info.oraPlecare);
		free(temp->info.status);
		free(temp);
	}
}


int main()
{
	Nod* n;
	n = citireListaDinFisier("curse.txt");
	afisareLista(n);
	printf("\n");
	stergereCurseCuAcelasiStatus(&n, "anulata");
	afisareLista(n);

}




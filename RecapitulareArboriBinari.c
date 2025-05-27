#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>;
#include <malloc.h>;
#include <string.h>;

struct PiesaTeatru
{
	char* titlu;
	int durata;
	int anPremiera;
	float popularitate;
};
typedef struct PiesaTeatru PiesaTeatru;

struct Nod
{
	PiesaTeatru info;
	struct Nod* st;
	struct Nod* dr;
};
typedef struct Nod Nod;

PiesaTeatru citirePiesaDinFisier(FILE* f)
{
	char buffer[224];
	char* aux;
	char sep[3] = ",";
	fgets(buffer, 224, f);
	
	PiesaTeatru pt;
	aux = strtok(buffer, sep);
	pt.titlu = malloc(strlen(aux) + 1);
	strcpy_s(pt.titlu, strlen(aux) + 1, aux);
	pt.durata = atoi(strtok(NULL, sep));
	pt.anPremiera = atoi(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	pt.popularitate = aux ? (float)atof(aux) : 0;
	return pt;


}

void afisarePT(PiesaTeatru pt)
{
	printf("Titlu: %s\n", pt.titlu);
	printf("Durata: %i\n", pt.durata);
	printf("An premiera: %i\n", pt.anPremiera);
	printf("Popularitate: %.2f\n\n", pt.popularitate);
}

void adaugaPTinArbore(Nod** arbore, PiesaTeatru pt)
{
	if (*arbore == NULL)
	{
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		nou->info = pt;
		nou->dr = NULL;
		nou->st = NULL;
		*arbore = nou;
	}
	else
	{
		if (strcmp((*arbore)->info.titlu, pt.titlu) > 0)
		{
			adaugaPTinArbore(&((*arbore)->st), pt);
		}
		else
		{
			if (strcmp((*arbore)->info.titlu, pt.titlu) < 0)
			{
				adaugaPTinArbore(&((*arbore)->dr), pt);
			}
		}
	}
}

Nod* citirePTdinFisier(const char* numeFisier)
{
	FILE* f = fopen(numeFisier, "r");
	Nod* arbore = NULL;
	while (!feof(f))
	{
		PiesaTeatru pt = citirePiesaDinFisier(f);
		adaugaPTinArbore(&arbore, pt);
	}
	fclose(f);
	return arbore;
}

//void afisarePTdinArbore(Nod* arbore)
//{
//
//}

void parcurgereInOrdine(Nod* arbore)
{
	if (arbore)
	{
		parcurgereInOrdine(arbore->st);
		afisarePT(arbore->info);
		parcurgereInOrdine(arbore->dr);
	}
}

float piesaCeaMaiPopulara(Nod* arbore)
{
	float maxim = arbore->info.popularitate;
	if (arbore)
	{
		if (arbore->info.popularitate > maxim)
		{
			return piesaCeaMaiPopulara(arbore->st);
		}
		else if (arbore->info.popularitate < maxim)
		{
				return piesaCeaMaiPopulara(arbore->dr);
		}
		else
		{
			return arbore->info.popularitate;
		}
		
	}
	return maxim;
}

PiesaTeatru cautaPiesaDupaTitlu(Nod* arbore, const char* titlu)
{
	if (arbore)
	{
		if (strcmp(arbore->info.titlu, titlu) == 0)
		{
			PiesaTeatru copie;
			copie.titlu = malloc(strlen(titlu) + 1);
			strcpy_s(copie.titlu, strlen(titlu) + 1, titlu);
			copie.anPremiera = arbore->info.anPremiera;
			copie.durata = arbore->info.durata;
			copie.popularitate = arbore->info.popularitate;
			return copie;
		}
		else
			if (strcmp(arbore->info.titlu, titlu) < 0)
				return cautaPiesaDupaTitlu(arbore->dr, titlu);
			else
				return cautaPiesaDupaTitlu(arbore->st, titlu);
	}

}

void dezalocare(Nod** arbore) {
	if (*arbore) {
		dezalocare(&((*arbore)->st));
		dezalocare(&((*arbore)->dr));
		free((*arbore)->info.titlu);
		free(*arbore);
		*arbore = NULL;
	}
}




int main() 
{
	/*FILE* f = fopen("piese_teatru.txt", "r");
	while (!(feof(f))) {
		PiesaTeatru pt1 = citirePiesaDinFisier(f);
		afisarePT(pt1);
	}
	fclose(f);*/

	Nod* arbore;
	arbore=citirePTdinFisier("piese_teatru.txt");
	parcurgereInOrdine(arbore);
	printf("\n");
	PiesaTeatru pt = cautaPiesaDupaTitlu(arbore, "Hamlet");
	afisarePT(pt);
}
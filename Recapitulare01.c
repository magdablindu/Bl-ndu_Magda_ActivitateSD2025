//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//
//struct AplicatieMobila
//{
//	char* denumireAplicatie;
//	float marimeMB;
//	int nrDescarcari;
//	int anLansare;
//};
//typedef struct AplicatieMobila AplicatieMobila;
//
//struct Nod
//{
//	AplicatieMobila info;
//	struct Nod* next;
//};
//typedef struct Nod Nod;
//
//AplicatieMobila initializeaza(const char* denumireAplicatie, float marimeMB, int nrDescarcari, int anLansare)
//{
//	AplicatieMobila a;
//	a.denumireAplicatie = malloc(strlen(denumireAplicatie) + 1);
//	strcpy_s(a.denumireAplicatie, strlen(denumireAplicatie) + 1, denumireAplicatie);
//	a.marimeMB = marimeMB;
//	a.nrDescarcari = nrDescarcari;
//	a.anLansare = anLansare;
//	return a;
//}
//
//void afisareAplicatieMobila(AplicatieMobila a)
//{
//	printf("Denumire: %s\n", a.denumireAplicatie);
//	printf("Marime in MB: %.2f\n", a.marimeMB);
//	printf("Nr descarcari: %i\n", a.nrDescarcari);
//	printf("An lansare: %i\n", a.anLansare);
//}
//
//void afisareLista(Nod* lista)
//{
//	while (lista)
//	{
//		afisareAplicatieMobila(lista->info);
//		lista = lista->next;
//	}
//}
//
//void inserareLaSfarsit(Nod** lista, AplicatieMobila ap)
//{
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = ap;
//	nou->next = NULL;
//	if ((*lista) == NULL)
//	{
//		*lista = nou;
//	}
//	else
//	{
//		Nod* aux = *lista;
//		while (aux->next)
//		{
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//}
//
//void dezalocare(Nod** lista)
//{
//	while (*lista)
//	{
//		Nod* temp = (*lista);
//		*lista = (*lista)->next;
//
//		free(temp->info.denumireAplicatie);
//		free(temp);
//	}
//
//}
//
//AplicatieMobila celMaiMicSpatiu(Nod* lista)
//{
//	AplicatieMobila ap;
//	ap.denumireAplicatie = malloc(strlen(lista->info.denumireAplicatie) + 1);
//	strcpy_s(ap.denumireAplicatie, strlen(lista->info.denumireAplicatie) + 1, lista->info.denumireAplicatie);
//	ap.marimeMB = lista->info.marimeMB;
//	ap.nrDescarcari = lista->info.nrDescarcari;
//	ap.anLansare = lista->info.anLansare;
//	float minim = lista->info.marimeMB;
//	while (lista)
//	{
//		if (lista->info.marimeMB<minim)
//		{
//			ap.denumireAplicatie = malloc(strlen(lista->info.denumireAplicatie) + 1);
//			strcpy_s(ap.denumireAplicatie, strlen(lista->info.denumireAplicatie) + 1, lista->info.denumireAplicatie);
//			minim = lista->info.marimeMB;
//			ap.marimeMB = lista->info.marimeMB;
//			ap.nrDescarcari = lista->info.nrDescarcari;
//			ap.anLansare = lista->info.anLansare;
//			ap.marimeMB = minim;
//		}
//		lista = lista->next;
//	}
//	return ap;
//}
//
//void stergereDupaDenumire(Nod** lista, const char* denumire)
//{
//	Nod* anterior = NULL;
//	Nod* curent = *lista;
//	while (curent)
//	{
//		if (strcmp(curent->info.denumireAplicatie, denumire) == 0)
//		{
//			Nod* deSters = curent;
//			if (anterior == NULL)
//			{
//				*lista = curent->next;
//			}
//			else
//			{
//				anterior->next = curent->next;
//			}
//			curent = curent->next;
//			free(deSters->info.denumireAplicatie);
//			free(deSters);
//		}
//		else
//		{
//			anterior = curent;
//			curent = curent->next;
//		}
//	}
//}
//
//int main()
//{
//	AplicatieMobila ap1 = initializeaza("Instagram", 3, 1000, 2012);
//	AplicatieMobila ap2 = initializeaza("Glovo", 150, 2000, 2014);
//	AplicatieMobila ap3 = initializeaza("Bolt", 80.5, 1750, 2019);
//	AplicatieMobila ap4 = initializeaza("Netflix", 175, 9000, 2011);
//	AplicatieMobila ap5 = initializeaza("Facebook", 345.78, 9976, 1998);
//	Nod* lista=NULL;
//	inserareLaSfarsit(&lista, ap1);
//	inserareLaSfarsit(&lista, ap2);
//	inserareLaSfarsit(&lista, ap3);
//	inserareLaSfarsit(&lista, ap4);
//	inserareLaSfarsit(&lista, ap5);
//	afisareLista(lista);
//	printf("\n");
//	AplicatieMobila ap6 = celMaiMicSpatiu(lista);
//	afisareAplicatieMobila(ap6);
//	printf("\n");
//	stergereDupaDenumire(&lista, "Glovo");
//	afisareLista(lista);
//	dezalocare(&lista);
//}

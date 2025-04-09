//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//
//struct CarteTarot
//{
//	char* nume;
//	int tipArcana;
//	char* simbol;
//	float energie;
//};
//typedef struct CarteTarot CarteTarot;
//
//struct Nod
//{
//	CarteTarot info;
//	struct Nod* next;
//	struct Nod* prev;
//};
//typedef struct Nod Nod;
//
//struct ListaDubla
//{
//	Nod* first;
//	Nod* last;
//};
//typedef struct ListaDubla ListaDubla;
//
//CarteTarot initializare(const char* nume, int tipArcana, const char* simbol, float energie)
//{
//	CarteTarot ct;
//	ct.nume = malloc(strlen(nume) + 1);
//	strcpy_s(ct.nume, strlen(nume) + 1, nume);
//	if (tipArcana == 0 || tipArcana == 1)
//	{
//		ct.tipArcana = tipArcana;
//	}
//	else
//	{
//		ct.tipArcana = -1;
//	}
//	ct.simbol = malloc(strlen(simbol) + 1);
//	strcpy_s(ct.simbol, strlen(simbol) + 1, simbol);
//	ct.energie = energie;
//	return ct;
//}
//
//void afisare(CarteTarot ct)
//{
//	printf("Nume: %s\n", ct.nume);
//	printf("Tip arcana: %d\n", ct.tipArcana);
//	printf("Simbol: %s\n", ct.simbol);
//	printf("Energie: %.2f\n", ct.energie);
//}
//
//void afisareLDDeLaInceput(ListaDubla lista)
//{
//	Nod* p = lista.first;
//	while (p)
//	{
//		afisare(p->info);
//		p = p->next;
//	}
//}
//
//void afisareLDDeLaSfarsit(ListaDubla lista)
//{
//	Nod* p = lista.last;
//	while (p)
//	{
//		afisare(p->info);
//		p = p->prev;
//	}
//}
//
//void inserareLaInceput(ListaDubla* lista, CarteTarot ct)
//{
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = ct;
//	nou->prev = NULL;
//	nou->next = lista->first;
//	if (lista->first != NULL)
//	{
//		lista->first->prev = nou;
//	}
//	else
//	{
//		lista->last = nou;
//	}
//	lista->first = nou;
//}
//
//CarteTarot ceaMaiMareEnergie(ListaDubla lista)
//{
//	float maxim = -1;
//	CarteTarot ct;
//	Nod* p = lista.first;
//	while (p)
//	{
//		if (p->info.energie > maxim)
//		{
//			ct = initializare(p->info.nume, p->info.tipArcana, p->info.simbol, p->info.energie);
//			maxim = p->info.energie;
//		}
//		p = p->next;
//	}
//	return ct;
//}
//
//void stergereDupaSimbol(ListaDubla* lista, const char* simbol)
//{
//	Nod* p = lista->first;
//	while (p)
//	{
//		if (strcmp(p->info.simbol, simbol) == 0)
//		{
//			if (p->prev)
//			{
//				p->prev->next = p->next;
//			}
//			else
//			{
//				lista->first = p->next;
//			}
//			if (p->next)
//			{
//				p->next->prev = p->prev;
//			}
//			else
//			{
//				lista->last = p->prev;
//			}
//			free(p->info.nume);
//			free(p->info.simbol);
//			free(p);
//			return;
//		}
//		p = p->next;
//	}
//}
//
//void dezalocare(ListaDubla* lista)
//{
//	Nod* p = lista->first;
//	while (p)
//	{
//		Nod* temp = p;
//		p = p->next;
//		free(temp->info.nume);
//		free(temp->info.simbol);
//		free(temp);
//	}
//	lista->first = NULL;
//	lista->last = NULL;
//}
//
//int main()
//{
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	CarteTarot ct1 = initializare("The fool", 1, "caine", 20.3);
//	CarteTarot ct2 = initializare("The tower", 1, "turn", 60);
//	CarteTarot ct3 = initializare("The lovers", 1, "inima", 57.53);
//	CarteTarot ct4 = initializare("Three of swords", 0, "sabie", 17);
//	CarteTarot ct5 = initializare("Two of cups", 0, "turn", 43);
//	inserareLaInceput(&lista, ct1);
//	inserareLaInceput(&lista, ct2);
//	inserareLaInceput(&lista, ct3);
//	inserareLaInceput(&lista, ct4);
//	inserareLaInceput(&lista, ct5);
//	afisareLDDeLaInceput(lista);
//	printf("---------------------------------");
//	printf("\n");
//	afisareLDDeLaSfarsit(lista);
//	printf("\n");
//	CarteTarot ct6=ceaMaiMareEnergie(lista);
//	afisare(ct6);
//	printf("\n");
//	stergereDupaSimbol(&lista, "turn");
//	afisareLDDeLaInceput(lista);
//
//	dezalocare(&lista);
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
////sau va creati un alt fisier cu alte date
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
////creare structura pentru un nod dintr-un arbore binar de cautare
//struct Nod
//{
//	Masina info;
//	struct Nod* st;
//	struct Nod* dr;
//	int grad;
//};
//typedef Nod Nod;
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
////int calculeazaInaltimeArbore(/*arbore de masini*/) {
////	//calculeaza inaltimea arborelui care este data de 
////	//lungimea maxima de la radacina pana la cel mai indepartat nod frunza
////	return 0;
////}
//
////ALTE FUNCTII NECESARE:
//// - aici veti adauga noile functii de care aveti nevoie.
//
//void rotireLaStanga(Nod** arbore)
//{
//	Nod* aux = (*arbore)->dr;
//	(*arbore)->dr = aux->st;
//	aux->st = (*arbore);
//	(*arbore) = aux;
//	(*arbore)->grad--;
//}
//
//void rotireLaDreapt(Nod** arbore)
//{
//	Nod* aux = (*arbore)->st;
//	(*arbore)->st = aux->dr;
//	aux->dr = (*arbore);
//	(*arbore) = aux;
//	(*arbore)->grad++;
//}
//
//void adaugaMasinaInArboreEchilibrat(Nod** radacina, Masina masinaNoua) {
//	//adauga o noua masina pe care o primim ca parametru in arbore,
//	//astfel incat sa respecte principiile de arbore binar de cautare ECHILIBRAT
//	//dupa o anumita cheie pe care o decideti - poate fi ID
//	if ((*radacina) != NULL)
//	{
//		if (masinaNoua.id < (*radacina)->info.id)
//		{
//			adaugaMasinaInArboreEchilibrat(&((*radacina)->st), masinaNoua);
//			(*radacina)->grad++;
//		}
//		else
//		{
//			adaugaMasinaInArboreEchilibrat(&((*radacina)->dr), masinaNoua);
//			(*radacina)->grad--;
//		}
//		if ((*radacina)->grad == 2)
//		{
//			//dezechilibru la stanga
//			if ((*radacina)->st->grad == 1)
//			{
//				//situatia simpla->rotire la dreapta
//				rotireLaDreapt(radacina);
//
//			}
//			else
//			{
//				rotireLaStanga(&((*radacina)->st));
//				rotireLaDreapt(radacina);
//			}
//		}
//		if ((*radacina)->grad == -2)
//		{
//			if( (*radacina)->dr->grad == 1)
//			{
//				rotireLaDreapta(&((*radacina)->dr));
//			}
//			rotireLaStanga(radacina);
//		}
//	}
//	else
//	{
//		Nod* nou = malloc(sizeof(radacina));
//		nou->info = masinaNoua;
//		nou->dr = NULL;
//		nou->st = NULL;
//		nou->grad = 0;
//		(*radacina) = nou;
//	}
//
//}
//
//
//void* citireArboreDeMasiniDinFisier(const char* numeFisier) {
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaDinFisier()
//	//ATENTIE - la final inchidem fisierul/stream-ul
//	FILE* f = fopen(numeFisier, "r");
//		Nod* arbore = NULL;
//		while (!feof(f)) {
//			Masina m = citireMasinaDinFisier(f);
//			adaugaMasinaInArboreEchilibrat(&arbore, m);
//		}
//		fclose(f);
//		return arbore;
//}
//
//void afisarePreOrdine(Nod* arbore) {
//	if (arbore) {
//		afisareMasina(arbore->info);
//		afisarePreOrdine(arbore->st);
//		afisarePreOrdine(arbore->dr);
//	}
//}
//
//
//void afisareMasiniDinArbore(/*arbore de masini*/) {
//	//afiseaza toate elemente de tip masina din arborele creat
//	//prin apelarea functiei afisareMasina()
//	//parcurgerea arborelui poate fi realizata in TREI moduri
//	//folositi toate cele TREI moduri de parcurgere
//}
//
//void dezalocareArboreDeMasini(/*arbore de masini*/) {
//	//sunt dezalocate toate masinile si arborele de elemente
//}
//
////Preluati urmatoarele functii din laboratorul precedent.
////Acestea ar trebuie sa functioneze pe noul arbore echilibrat.
//
//Masina getMasinaByID(/*arborele de masini*/int id);
//
//int determinaNumarNoduri(/*arborele de masini*/);
//
//float calculeazaPretTotal(/*arbore de masini*/);
//
//float calculeazaPretulMasinilorUnuiSofer(/*arbore de masini*/ const char* numeSofer);
//
//int main() {
//
//	Nod* arbore = citireArboreDeMasiniDinFisier("masini.txt");
//	afisarePreOrdine(arbore);
//	return 0;
//}
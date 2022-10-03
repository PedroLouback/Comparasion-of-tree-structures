#ifndef RB_HPP
#define RB_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include <fstream>
#include <random>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

typedef struct RecordRB RecordRB;
typedef struct RBTree RBTree;

struct RecordRB
{
	float key;
};

struct RBTree
{
	RecordRB reg;
	RBTree *esq, *dir;
	RBTree *pai; // específico para rubro negra
	bool cor;	 // específico para rubro negra (FALSE = VERMELHOR, TRUE = PRETO)
};

RBTree *CreateRBTree();

void rotacaoSimplesEsquerda(RBTree **raiz, RBTree *child);
void rotacaoSimplesDireita(RBTree **raiz, RBTree *child);

void insertFixUp(RBTree **raiz, RBTree *child);
void insertTreeRB(RBTree **t, RBTree **pai, RBTree **raiz, RecordRB r);
void pesquisa(RBTree **t, RBTree **aux, RecordRB r);

void preordem(RBTree *t);
void central(RBTree *t);
void posordem(RBTree *t);

RBTree *Insert500EntriesinRBTree(RBTree *t, RecordRB r_500entries);
RBTree *Insert5000EntriesinRBTree(RBTree *t, RecordRB r_5000entries);
RBTree *Insert50000EntriesinRBTree(RBTree*t, RecordRB r_50000entries);
RBTree *Insert500000EntriesinRBTree(RBTree *t, RecordRB r_500000entries);

#endif

#ifndef AVL_HPP
#define AVL_HPP

#include "../includes.hpp"

using namespace std;

typedef struct RecordAVL RecordAVL;
typedef struct AVLTree AVLTree;

struct RecordAVL
{
	float key;
	float value;
};

struct AVLTree
{
	RecordAVL reg;
	AVLTree *left, *right;
	int weight;
};

AVLTree *CreateAVLTree();
void insertTreeAVL(AVLTree **t, RecordAVL r);
void pesquisa(AVLTree **t, AVLTree **aux, RecordAVL r);
int isInTree(AVLTree *t, RecordAVL r);

// muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void removeTree(AVLTree **t, AVLTree **f, RecordAVL r);
void antecessor(AVLTree **t, AVLTree *aux);
void rebalanceTree(AVLTree **t);

void preordem(AVLTree *t);
void central(AVLTree *t);
void posordem(AVLTree *t);

int getWeight(AVLTree **t);
int getMaxWeight(int left, int right);

void rotacaoSimplesDireita(AVLTree **t);
void rotacaoSimplesEsquerda(AVLTree **t);
void rotacaoDuplaDireita(AVLTree **t);
void rotacaoDuplaEsquerda(AVLTree **t);

AVLTree *Insert500EntriesinAVLTree(AVLTree *t, RecordAVL r_500entries);
AVLTree *Insert5000EntriesinAVLTree(AVLTree *t, RecordAVL r_5000entries);
AVLTree *Insert50000EntriesinAVLTree(AVLTree *t, RecordAVL r_50000entries);
AVLTree *Insert500000EntriesinAVLTree(AVLTree *t, RecordAVL r_500000entries);


void SearchAndRemoveAVL500Entries(AVLTree *raizAVL500entries, vector<float> query_numbers);
void SearchAndRemoveAVL5000Entries(AVLTree *raizAVL5000entries, vector<float> query_numbers);
void SearchAndRemoveAVL50000Entries(AVLTree *raizAVL50000entries, vector<float> query_numbers);
void SearchAndRemoveAVL500000Entries(AVLTree *raizAVL500000entries, vector<float> query_numbers);

#endif

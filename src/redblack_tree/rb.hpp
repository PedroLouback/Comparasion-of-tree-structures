#ifndef RB_HPP
#define RB_HPP

#include "../includes.hpp"

using namespace std;

typedef struct NO *RBTree;
RBTree *cria_ArvoreRB();
void libera_RBTree(RBTree *raiz);
float insere_RBTree(RBTree *raiz, float valor);
float remove_RBTree(RBTree *raiz, float valor);
float consulta_RBTree(RBTree *raiz, float valor);
void emOrdem_RBTree(RBTree *raiz, int H);

void SearchAndRemoveRB500Entries(RBTree *RB500entries, vector<float> query_numbers);
void SearchAndRemoveRB5000Entries(RBTree *RB5000entries, vector<float> query_numbers);
void SearchAndRemoveRB50000Entries(RBTree *RB50000entries, vector<float> query_numbers);
void SearchAndRemoveRB500000Entries(RBTree *RB500000entries, vector<float> query_numbers);

#endif

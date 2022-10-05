#ifndef TREE_HPP
#define TREE_HPP

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

typedef struct Record Record;
typedef struct Tree Tree;

struct Record
{
	float key;
	float value;
};

struct Tree
{
	Record reg;
	Tree *esq, *dir;
};

Tree *CreateBinaryTree();
bool TVazia(Tree **t);
void insertTree(Tree **t, Record r);
void pesquisa(Tree **t, Tree **aux, Record r);
int isInTree(Tree *t, Record r);

void removeTree(Tree **t, Record r);
void antecessor(Tree **t, Tree *aux);

void preordem(Tree *t);
void central(Tree *t);
void posordem(Tree *t);
void widthPath(Tree *t);

Tree *Insert500EntriesinTree(Tree *t, Record r_500entries);
Tree *Insert5000EntriesinTree(Tree *t, Record r_5000entries);
Tree *Insert50000EntriesinTree(Tree *t, Record r_50000entries);
Tree *Insert500000EntriesinTree(Tree *t, Record r_500000entries);

void SearchAndRemove500Entries(Tree *raiz500entries, vector<float> query_numbers);
void SearchAndRemove5000Entries(Tree *raiz5000entries, vector<float> query_numbers);
void SearchAndRemove50000Entries(Tree *raiz50000entries, vector<float> query_numbers);
void SearchAndRemove500000Entries(Tree *raiz500000entries, vector<float> query_numbers);

#endif

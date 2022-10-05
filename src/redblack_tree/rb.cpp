#include "rb.hpp"

RBTree *CreateRBTree()
{
  return NULL;
}

void insertFixUp(RBTree **raiz, RBTree *child)
{
  RBTree *tio;

  while ((child != *raiz) && (child->pai->cor == false))
  {

    if (child->pai == child->pai->pai->esq)
    {

      tio = child->pai->pai->dir;

      // caso 1:
      if ((tio != NULL) && (tio->cor == false))
      {
        child->pai->cor = true;
        tio->cor = true;
        child->pai->pai->cor = false;
        child = child->pai->pai;
      }
      else
      {

        // caso 2
        if (child == child->pai->dir)
        {
          child = child->pai;
          rotacaoSimplesEsquerda(raiz, child);
        }

        // caso 3
        child->pai->cor = true;
        child->pai->pai->cor = false;
        rotacaoSimplesDireita(raiz, child->pai->pai);
      }
    }
    else
    {

      tio = child->pai->pai->esq;

      // caso 1
      if ((tio != NULL) && (tio->cor == false))
      {
        child->pai->cor = true;
        tio->cor = true;
        child->pai->pai->cor = false;
        child = child->pai->pai;
      }
      else
      {

        // caso 2
        if (child == child->pai->esq)
        {
          child = child->pai;
          rotacaoSimplesDireita(raiz, child);
        }

        // caso 3
        child->pai->cor = true;
        child->pai->pai->cor = false;
        rotacaoSimplesEsquerda(raiz, child->pai->pai);
      }
    }
  }

  (*raiz)->cor = true;
}

void insertTreeRB(RBTree **t, RBTree **pai, RBTree **raiz, RecordRB r)
{

  if (*t == NULL)
  {
    *t = new RBTree;
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->pai = pai != t ? *pai : NULL;
    (*t)->cor = false; // false: vermelho  true:preto
    (*t)->reg = r;
    insertFixUp(raiz, *t);
  }
  else
  {

    if (r.key < (*t)->reg.key)
    {
      insertTreeRB(&(*t)->esq, t, raiz, r);
      return;
    }

    if (r.key > (*t)->reg.key)
    {
      insertTreeRB(&(*t)->dir, t, raiz, r);
      return;
    }
  }
}

void pesquisa(RBTree **t, RBTree **aux, RecordRB r)
{

  if (*t == NULL)
  {
    return;
  }

  if ((*t)->reg.key > r.key)
  {
    pesquisa(&(*t)->esq, aux, r);
    return;
  }
  if ((*t)->reg.key < r.key)
  {
    pesquisa(&(*t)->dir, aux, r);
    return;
  }

  *aux = *t;
}

void rotacaoSimplesEsquerda(RBTree **raiz, RBTree *child)
{
  RBTree *x, *y;

  x = child;
  y = child->dir;
  x->dir = y->esq;

  if (y->esq != NULL)
    y->esq->pai = x;

  y->pai = x->pai;

  if (x->pai == NULL)
    *raiz = y;

  else
  {

    if (x == x->pai->esq)
      x->pai->esq = y;

    else
      x->pai->dir = y;
  }

  y->esq = x;
  x->pai = y;
}

void rotacaoSimplesDireita(RBTree **raiz, RBTree *child)
{
  RBTree *x, *y;

  x = child;
  y = child->esq;
  x->esq = y->dir;

  if (y->dir != NULL)
    y->dir->pai = x;

  y->pai = x->pai;

  if (x->pai == NULL)
  {
    *raiz = y;
  }

  else
  {

    if (x == x->pai->dir)
      x->pai->dir = y;

    else
      x->pai->esq = y;
  }

  y->dir = x;
  x->pai = y;
}

void preordem(RBTree *t)
{
  if (!(t == NULL))
  {
    printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
    preordem(t->esq);
    preordem(t->dir);
  }
}

void central(RBTree *t)
{
  if (!(t == NULL))
  {
    central(t->esq);
    printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
    central(t->dir);
  }
}

void posordem(RBTree *t)
{
  if (!(t == NULL))
  {
    posordem(t->esq);
    posordem(t->dir);
    printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
  }
}

RBTree *Insert500EntriesinRBTree(RBTree *t, RecordRB r_500entries)
{

  ifstream entries_file;
  string number_in_string;
  float number;

  entries_file.open("src/files/500entries.txt");
  while (!entries_file.eof())
  {
    getline(entries_file, number_in_string);
    istringstream in(number_in_string);
    in >> number;
    r_500entries.key = number;
    insertTreeRB(&t, &t, &t, r_500entries);
  }

  return t;
}

RBTree *Insert5000EntriesinRBTree(RBTree *t, RecordRB r_5000entries)
{
  ifstream entries_file;
  string number_in_string;
  float number;

  entries_file.open("src/files/5000entries.txt");
  while (!entries_file.eof())
  {
    getline(entries_file, number_in_string);
    istringstream in(number_in_string);
    in >> number;
    r_5000entries.key = number;
    insertTreeRB(&t, &t, &t, r_5000entries);
  }

  return t;
}

RBTree *Insert50000EntriesinRBTree(RBTree *t, RecordRB r_50000entries)
{

  ifstream entries_file;
  string number_in_string;
  float number;

  entries_file.open("src/files/50000entries.txt");
  while (!entries_file.eof())
  {
    getline(entries_file, number_in_string);
    istringstream in(number_in_string);
    in >> number;
    r_50000entries.key = number;
    insertTreeRB(&t, &t, &t, r_50000entries);
  }

  return t;
}

RBTree *Insert500000EntriesinRBTree(RBTree *t, RecordRB r_500000entries)
{

  ifstream entries_file;
  string number_in_string;
  float number;

  entries_file.open("src/files/500000entries.txt");
  while (!entries_file.eof())
  {
    getline(entries_file, number_in_string);
    istringstream in(number_in_string);
    in >> number;
    r_500000entries.key = number;
    insertTreeRB(&t, &t, &t, r_500000entries);
  }

  return t;
}

void SearchAndRemoveRB500Entries(RBTree *raizRB500entries, vector<float> query_numbers)
{
  RecordRB r;
  RBTree *aux = CreateRBTree();

  for (size_t i = 0; i < query_numbers.size(); i++)
  {
    r.key = query_numbers.at(i);
    pesquisa(&raizRB500entries, &aux, r);
  }
}

void SearchAndRemoveRB5000Entries(RBTree *raizRB5000entries, vector<float> query_numbers)
{
  RecordRB r;
  RBTree *aux = CreateRBTree();

  for (size_t i = 0; i < query_numbers.size(); i++)
  {
    r.key = query_numbers.at(i);
    pesquisa(&raizRB5000entries, &aux, r);
  }
}

void SearchAndRemoveRB50000Entries(RBTree *raizRB50000entries, vector<float> query_numbers)
{
  RecordRB r;
  RBTree *aux = CreateRBTree();

  for (size_t i = 0; i < query_numbers.size(); i++)
  {
    r.key = query_numbers.at(i);
    pesquisa(&raizRB50000entries, &aux, r);
  }
}

void SearchAndRemoveRB500000Entries(RBTree *raizRB500000entries, vector<float> query_numbers)
{
  RecordRB r;
  RBTree *aux = CreateRBTree();

  for (size_t i = 0; i < query_numbers.size(); i++)
  {
    r.key = query_numbers.at(i);
    pesquisa(&raizRB500000entries, &aux, r);
  }
}
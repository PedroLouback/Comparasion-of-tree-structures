#include "tree.hpp"
#include "fila.hpp"

Tree *CreateBinaryTree()
{
  return NULL;
}

bool TVazia(Tree **t)
{
  return *t == NULL;
}

void insertTree(Tree **t, Record r)
{

  if (TVazia(t))
  {
    *t = new Tree;
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->reg = r;
  }
  else
  {

    if (r.key < (*t)->reg.key)
    {
      insertTree(&(*t)->esq, r);
    }

    if (r.key > (*t)->reg.key)
    {
      insertTree(&(*t)->dir, r);
    }
  }
}

void pesquisa(Tree **t, Tree **aux, Record r)
{

  if (*t == NULL)
  {
    printf("[ERROR]: Node not found!");
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

int isInTree(Tree *t, Record r)
{

  if (t == NULL)
  {
    return 0;
  }

  return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}

void antecessor(Tree **t, Tree *aux)
{

  if ((*t)->dir != NULL)
  {
    antecessor(&(*t)->dir, aux);
    return;
  }

  aux->reg = (*t)->reg;
  aux = *t;
  *t = (*t)->esq;
  free(aux);
}

void removeTree(Tree **t, Record r)
{
  Tree *aux;

  if (*t == NULL)
  {
    printf("[ERROR]: Record not found!!!\n");
    return;
  }

  if (r.key < (*t)->reg.key)
  {
    removeTree(&(*t)->esq, r);
    return;
  }
  if (r.key > (*t)->reg.key)
  {
    removeTree(&(*t)->dir, r);
    return;
  }

  if ((*t)->dir == NULL)
  {
    aux = *t;
    *t = (*t)->esq;
    free(aux);
    return;
  }

  if ((*t)->esq != NULL)
  {
    antecessor(&(*t)->esq, *t);
    return;
  }

  aux = *t;
  *t = (*t)->dir;
  free(aux);
}

void preordem(Tree *t)
{

  if (!(t == NULL))
  {
    cout << t->reg.key << " ";
    preordem(t->esq);
    preordem(t->dir);
  }
}

void central(Tree *t)
{
  if (!(t == NULL))
  {
    central(t->esq);
    cout << t->reg.key << " ";
    central(t->dir);
  }
}

void posordem(Tree *t)
{
  if (!(t == NULL))
  {
    posordem(t->esq);
    posordem(t->dir);
    cout << t->reg.key << " ";
  }
}

void widthPath(Tree *t)
{
  Fila q;
  Item no, filho;

  FFVazia(&q);
  no.p = t;
  Enfileira(&q, no);

  while (!isVazia(&q))
  {

    Desenfileira(&q, &no);
    cout << no.p->reg.key << " ";

    if (no.p->esq != NULL)
    {
      filho.p = no.p->esq;
      Enfileira(&q, filho);
      // printf(" Entrei esquerda! ");
    }

    if (no.p->dir != NULL)
    {
      filho.p = no.p->dir;
      Enfileira(&q, filho);
      // printf(" Entrei direita! ");
    }
  }
}

Tree *Insert500EntriesinTree(Tree *t, vector<float> vector_entries, Record r_500entries)
{

  for (size_t i = 0; i < vector_entries.size(); i++)
  {
    r_500entries.key = vector_entries.at(i);
    r_500entries.value = 1;
    insertTree(&t, r_500entries);
  }
  
  return t;
}

Tree *Insert5000EntriesinTree(Tree *t, vector<float> vector_entries, Record r_5000entries)
{

  for (size_t i = 0; i < vector_entries.size(); i++)
  {
    r_5000entries.key = vector_entries.at(i);
    r_5000entries.value = 1;
    insertTree(&t, r_5000entries);
  }

  return t;
}

Tree *Insert50000EntriesinTree(Tree *t, vector<float> vector_entries, Record r_50000entries)
{

  for (size_t i = 0; i < vector_entries.size(); i++)
  {
    r_50000entries.key = vector_entries.at(i);
    r_50000entries.value = 1;
    insertTree(&t, r_50000entries);
  }

  return t;
}

Tree *Insert500000EntriesinTree(Tree *t, vector<float> vector_entries, Record r_500000entries)
{

  for (size_t i = 0; i < vector_entries.size(); i++)
  {
    r_500000entries.key = vector_entries.at(i);
    r_500000entries.value = 1;
    insertTree(&t, r_500000entries);
  }

  return t;
}


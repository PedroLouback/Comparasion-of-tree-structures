#include "avl.hpp"

AVLTree *CreateAVLTree()
{
	return NULL;
}

void insertTreeAVL(AVLTree **t, RecordAVL r)
{

	if (*t == NULL)
	{
		*t = (AVLTree *)malloc(sizeof(AVLTree));
		(*t)->left = NULL;
		(*t)->right = NULL;
		(*t)->weight = 0;
		(*t)->reg = r;
	}
	else
	{

		if (r.key < (*t)->reg.key)
		{
			insertTreeAVL(&(*t)->left, r);
			if ((getWeight(&(*t)->left) - getWeight(&(*t)->right)) == 2)
			{
				if (r.key < (*t)->left->reg.key)
					rotacaoSimplesDireita(t);
				else
					rotacaoDuplaDireita(t);
			}
		}

		if (r.key > (*t)->reg.key)
		{
			insertTreeAVL(&(*t)->right, r);
			if ((getWeight(&(*t)->right) - getWeight(&(*t)->left)) == 2)
			{
				if (r.key > (*t)->right->reg.key)
					rotacaoSimplesEsquerda(t);
				else
					rotacaoDuplaEsquerda(t);
			}
		}
	}

	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
}

void pesquisa(AVLTree **t, AVLTree **aux, RecordAVL r)
{

	if (*t == NULL)
	{
		return;
	}

	if ((*t)->reg.key > r.key)
	{
		pesquisa(&(*t)->left, aux, r);
		return;
	}
	if ((*t)->reg.key < r.key)
	{
		pesquisa(&(*t)->right, aux, r);
		return;
	}

	*aux = *t;
}

int isInTree(AVLTree *t, RecordAVL r)
{

	if (t == NULL)
	{
		return 0;
	}

	return t->reg.key == r.key || isInTree(t->left, r) || isInTree(t->right, r);
}

void antecessor(AVLTree **t, AVLTree *aux)
{

	if ((*t)->right != NULL)
	{
		antecessor(&(*t)->right, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->left;
	free(aux);
}

void rebalanceTree(AVLTree **t)
{
	int balance;
	int left = 0;
	int right = 0;

	balance = getWeight(&(*t)->left) - getWeight(&(*t)->right);
	if ((*t)->left)
		left = getWeight(&(*t)->left->left) - getWeight(&(*t)->left->right);
	if ((*t)->right)
		right = getWeight(&(*t)->right->left) - getWeight(&(*t)->right->right);

	if (balance == 2 && left >= 0)
		rotacaoSimplesDireita(t);
	if (balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if (balance == -2 && right <= 0)
		rotacaoSimplesEsquerda(t);
	if (balance == -2 && right > 0)
		rotacaoDuplaEsquerda(t);
}

void removeTree(AVLTree **t, AVLTree **f, RecordAVL r)
{
	AVLTree *aux;

	if (*t == NULL)
	{
		return;
	}

	if (r.key < (*t)->reg.key)
	{
		removeTree(&(*t)->left, t, r);
		return;
	}
	if (r.key > (*t)->reg.key)
	{
		removeTree(&(*t)->right, t, r);
		return;
	}

	if ((*t)->right == NULL)
	{
		aux = *t;
		*t = (*t)->left;
		free(aux);
		rebalanceTree(f);
		return;
	}

	if ((*t)->left != NULL)
	{
		antecessor(&(*t)->left, *t);
		rebalanceTree(t);
		rebalanceTree(f);
		return;
	}

	aux = *t;
	*t = (*t)->right;
	free(aux);
	rebalanceTree(t);
	rebalanceTree(f);
}

void preordem(AVLTree *t)
{
	if (!(t == NULL))
	{
		cout << t->reg.key << ":" << t->weight << "\t";
		preordem(t->left);
		preordem(t->right);
	}
}

void central(AVLTree *t)
{
	if (!(t == NULL))
	{
		central(t->left);
		cout << t->reg.key << "\t";
		central(t->right);
	}
}

void posordem(AVLTree *t)
{
	if (!(t == NULL))
	{
		posordem(t->left);
		posordem(t->right);
		cout << t->reg.key << "\t";
	}
}

int getWeight(AVLTree **t)
{
	if (*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeight(int left, int right)
{
	if (left > right)
		return left;
	return right;
}

void rotacaoSimplesDireita(AVLTree **t)
{
	AVLTree *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda(AVLTree **t)
{
	AVLTree *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita(AVLTree **t)
{
	rotacaoSimplesEsquerda(&(*t)->left);
	rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(AVLTree **t)
{
	rotacaoSimplesDireita(&(*t)->right);
	rotacaoSimplesEsquerda(t);
}

AVLTree *Insert500EntriesinAVLTree(AVLTree *t, RecordAVL r_500entries)
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
		r_500entries.value = 1;
		insertTreeAVL(&t, r_500entries);
	}

	return t;
}

AVLTree *Insert5000EntriesinAVLTree(AVLTree *t, RecordAVL r_5000entries)
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
		r_5000entries.value = 1;
		insertTreeAVL(&t, r_5000entries);
	}

	return t;
}

AVLTree *Insert50000EntriesinAVLTree(AVLTree *t, RecordAVL r_50000entries)
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
		r_50000entries.value = 1;
		insertTreeAVL(&t, r_50000entries);
	}

	return t;
}

AVLTree *Insert500000EntriesinAVLTree(AVLTree *t, RecordAVL r_500000entries)
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
		r_500000entries.value = 1;
		insertTreeAVL(&t, r_500000entries);
	}

	return t;
}

void SearchAndRemoveAVL500Entries(AVLTree *raizAVL500entries, vector<float> query_numbers)
{
	RecordAVL r;
	AVLTree *aux = CreateAVLTree();
	size_t time;

	time = clock();
	for (size_t i = 0; i < query_numbers.size(); i++)
	{
		r.key = query_numbers.at(i);
		pesquisa(&raizAVL500entries, &aux, r);
	}
	time = clock() - time;
	cout << "\nPesquisa: " << float(time) / CLOCKS_PER_SEC << " segundos";

	time = clock();
	for (size_t i = 0; i < query_numbers.size(); i++)
	{
		r.key = query_numbers.at(i);
		removeTree(&raizAVL500entries, &raizAVL500entries, r);
	}
	time = clock() - time;

	cout << "\nRemoção: " << float(time) / CLOCKS_PER_SEC << " segundos\n";
}

void SearchAndRemoveAVL5000Entries(AVLTree *raizAVL5000entries, vector<float> query_numbers)
{
	RecordAVL r;
	AVLTree *aux = CreateAVLTree();
	size_t time;

	time = clock();
	for (size_t i = 0; i < query_numbers.size(); i++)
	{
		r.key = query_numbers.at(i);
		pesquisa(&raizAVL5000entries, &aux, r);
	}
	time = clock() - time;
	cout << "\nPesquisa: " << float(time) / CLOCKS_PER_SEC << " segundos";

	time = clock();
	for (size_t i = 0; i < query_numbers.size(); i++)
	{
		r.key = query_numbers.at(i);
		removeTree(&raizAVL5000entries, &raizAVL5000entries, r);
	}
	time = clock() - time;
	cout << "\nRemoção: " << float(time) / CLOCKS_PER_SEC << " segundos\n";
}

void SearchAndRemoveAVL50000Entries(AVLTree *raizAVL50000entries, vector<float> query_numbers)
{
	RecordAVL r;
	AVLTree *aux = CreateAVLTree();

	size_t time;

	time = clock();
	for (size_t i = 0; i < query_numbers.size(); i++)
	{
		r.key = query_numbers.at(i);
		pesquisa(&raizAVL50000entries, &aux, r);
	}
	time = clock() - time;
	cout << "\nPesquisa: " << float(time) / CLOCKS_PER_SEC << " segundos";

	time = clock();
	for (size_t i = 0; i < query_numbers.size(); i++)
	{
		r.key = query_numbers.at(i);
		removeTree(&raizAVL50000entries, &raizAVL50000entries, r);
	}
	time = clock() - time;
	cout << "\nRemoção: " << float(time) / CLOCKS_PER_SEC << " segundos\n";
}

void SearchAndRemoveAVL500000Entries(AVLTree *raizAVL500000entries, vector<float> query_numbers)
{
	RecordAVL r;
	AVLTree *aux = CreateAVLTree();

	size_t time;

	time = clock();
	for (size_t i = 0; i < query_numbers.size(); i++)
	{
		r.key = query_numbers.at(i);
		pesquisa(&raizAVL500000entries, &aux, r);
	}
	time = clock() - time;
	cout << "\nPesquisa: " << float(time) / CLOCKS_PER_SEC << " segundos";

	time = clock();
	for (size_t i = 0; i < query_numbers.size(); i++)
	{
		r.key = query_numbers.at(i);
		removeTree(&raizAVL500000entries, &raizAVL500000entries, r);
	}
	time = clock() - time;
	cout << "\nRemoção: " << float(time) / CLOCKS_PER_SEC << " segundos\n";
}
#include "tests.hpp"

void TestsBinaryTree(vector<float> query_numbers)
{

    // Inserção na árvore binária
    Tree *raiz500entries = CreateBinaryTree();
    Record r_500entries;
    raiz500entries = Insert500EntriesinTree(raiz500entries, r_500entries);

    Tree *raiz5000entries = CreateBinaryTree();
    Record r_5000entries;
    raiz5000entries = Insert5000EntriesinTree(raiz5000entries, r_5000entries);

    Tree *raiz50000entries = CreateBinaryTree();
    Record r_50000entries;
    raiz50000entries = Insert50000EntriesinTree(raiz50000entries, r_50000entries);

    Tree *raiz500000entries = CreateBinaryTree();
    Record r_500000entries;
    raiz500000entries = Insert500000EntriesinTree(raiz500000entries, r_500000entries);

    printf("METODO CENTRAL: { ");
    central(raiz500entries);
    printf("}\n\n");

    //Pesquisa com um arquivo de entrada com 10.000 consultas
    SearchAndRemove500Entries(raiz500entries, query_numbers);

}

void TestsAVLTree(vector<float> query_numbers)
{
    // Inserção na árvore AVL
    AVLTree *raizAVL500entries = CreateAVLTree();
    RecordAVL r_500entries;
    raizAVL500entries = Insert500EntriesinAVLTree(raizAVL500entries, r_500entries);

    AVLTree *raizAVL5000entries = CreateAVLTree();
    RecordAVL r_5000entries;
    raizAVL5000entries = Insert5000EntriesinAVLTree(raizAVL5000entries, r_5000entries);

    AVLTree *raizAVL50000entries = CreateAVLTree();
    RecordAVL r_50000entries;
    raizAVL50000entries = Insert50000EntriesinAVLTree(raizAVL50000entries, r_50000entries);

    AVLTree *raizAVL500000entries = CreateAVLTree();
    RecordAVL r_500000entries;
    raizAVL500000entries = Insert500000EntriesinAVLTree(raizAVL500000entries, r_500000entries);

    cout << query_numbers.at(1);
}

void TestsRBTree(vector<float> query_numbers)
{
    // Inserção na árvore RedBlack
    RBTree *raizRB500entries = CreateRBTree();
    RecordRB r_500entries;
    raizRB500entries = Insert500EntriesinRBTree(raizRB500entries, r_500entries);

    RBTree *raizRB5000entries = CreateRBTree();
    RecordRB r_5000entries;
    raizRB5000entries = Insert5000EntriesinRBTree(raizRB5000entries, r_5000entries);

    RBTree *raizRB50000entries = CreateRBTree();
    RecordRB r_50000entries;
    raizRB50000entries = Insert50000EntriesinRBTree(raizRB50000entries, r_50000entries);

    RBTree *raizRB500000entries = CreateRBTree();
    RecordRB r_500000entries;
    raizRB500000entries = Insert500000EntriesinRBTree(raizRB500000entries, r_500000entries);

    cout << query_numbers.at(1);
}

void SearchAndRemove500Entries(Tree *raiz500entries, vector<float> query_numbers)
{
    Record r;
    Tree *aux = CreateBinaryTree();

    for(size_t i = 0; i < query_numbers.size(); i++){
        r.key = query_numbers.at(i);
        pesquisa(&raiz500entries, &aux, r);
    }

}
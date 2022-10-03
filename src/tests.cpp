#include "tests.hpp"

void TestsBinaryTree(vector<float> entries500, vector<float> entries5000, vector<float> entries50000, vector<float> entries500000, vector<float> query_numbers)
{
    Tree *aux = CreateBinaryTree();

    // Inserção na árvore binária
    Tree *raiz500entries = CreateBinaryTree();
    Record r_500entries;
    raiz500entries = Insert500EntriesinTree(raiz500entries, entries500, r_500entries);

    Tree *raiz5000entries = CreateBinaryTree();
    Record r_5000entries;
    raiz5000entries = Insert5000EntriesinTree(raiz5000entries, entries5000, r_5000entries);

    Tree *raiz50000entries = CreateBinaryTree();
    Record r_50000entries;
    raiz50000entries = Insert50000EntriesinTree(raiz50000entries, entries50000, r_50000entries);

    Tree *raiz500000entries = CreateBinaryTree();
    Record r_500000entries;
    raiz500000entries = Insert500000EntriesinTree(raiz500000entries, entries500000, r_500000entries);

    central(raiz500entries);
    printf("}\n\n");

    //Pesquisa com um arquivo de entrada com 10.000 consultas

    

}

void TestsAVLTree(vector<float> entries500, vector<float> entries5000, vector<float> entries50000, vector<float> entries500000, vector<float> query_numbers)
{
    // Inserção na árvore AVL
    AVLTree *raizAVL500entries = CreateAVLTree();
    raizAVL500entries = Insert500EntriesinTree(raizAVL500entries, entries500);

    AVLTree *raizAVL5000entries = CreateAVLTree();
    raizAVL5000entries = Insert5000EntriesinTree(raizAVL5000entries, entries5000);

    AVLTree *raizAVL50000entries = CreateAVLTree();
    raizAVL50000entries = Insert50000EntriesinTree(raizAVL50000entries, entries50000);

    AVLTree *raizAVL500000entries = CreateAVLTree();
    raizAVL500000entries = Insert500000EntriesinTree(raizAVL500000entries, entries500000);

    cout << query_numbers.at(1);
}

void TestsRBTree(vector<float> entries500, vector<float> entries5000, vector<float> entries50000, vector<float> entries500000, vector<float> query_numbers)
{
    // Inserção na árvore RedBlack
    RBTree *raizRB500entries = CreateRBTree();
    RecordRB r_500entries;
    raizRB500entries = Insert500EntriesinRBTree(raizRB500entries, entries500, r_500entries);

    RBTree *raizRB5000entries = CreateRBTree();
    RecordRB r_5000entries;
    raizRB5000entries = Insert5000EntriesinRBTree(raizRB5000entries, entries5000, r_5000entries);

    RBTree *raizRB50000entries = CreateRBTree();
    RecordRB r_50000entries;
    raizRB50000entries = Insert50000EntriesinRBTree(raizRB50000entries, entries50000, r_50000entries);

    RBTree *raizRB500000entries = CreateRBTree();
    RecordRB r_500000entries;
    raizRB500000entries = Insert500000EntriesinRBTree(raizRB500000entries, entries500000, r_500000entries);


    cout << query_numbers.at(1);
}
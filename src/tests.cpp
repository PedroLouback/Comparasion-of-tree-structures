#include "tests.hpp"

void TestsBinaryTree(vector<float> query_numbers)
{

    // Inserção, remoção e pesquisa na árvore binária
    Tree *raiz500entries = CreateBinaryTree();
    Record r_500entries;
    raiz500entries = Insert500EntriesinTree(raiz500entries, r_500entries);
    SearchAndRemove500Entries(raiz500entries, query_numbers);
    free(raiz500entries);

    Tree *raiz5000entries = CreateBinaryTree();
    Record r_5000entries;
    raiz5000entries = Insert5000EntriesinTree(raiz5000entries, r_5000entries);
    SearchAndRemove5000Entries(raiz5000entries, query_numbers);
    free(raiz5000entries);

    Tree *raiz50000entries = CreateBinaryTree();
    Record r_50000entries;
    raiz50000entries = Insert50000EntriesinTree(raiz50000entries, r_50000entries);
    SearchAndRemove50000Entries(raiz50000entries, query_numbers);
    free(raiz50000entries);

    Tree *raiz500000entries = CreateBinaryTree();
    Record r_500000entries;
    raiz500000entries = Insert500000EntriesinTree(raiz500000entries, r_500000entries);
    SearchAndRemove500000Entries(raiz500000entries, query_numbers);
    free(raiz500000entries);
}

void TestsAVLTree(vector<float> query_numbers)
{
    // Inserção na árvore AVL
    AVLTree *raizAVL500entries = CreateAVLTree();
    RecordAVL r_500entries;
    raizAVL500entries = Insert500EntriesinAVLTree(raizAVL500entries, r_500entries);
    SearchAndRemoveAVL500Entries(raizAVL500entries, query_numbers);
    free(raizAVL500entries);

    AVLTree *raizAVL5000entries = CreateAVLTree();
    RecordAVL r_5000entries;
    raizAVL5000entries = Insert5000EntriesinAVLTree(raizAVL5000entries, r_5000entries);
    SearchAndRemoveAVL5000Entries(raizAVL5000entries, query_numbers);
    free(raizAVL5000entries);

    AVLTree *raizAVL50000entries = CreateAVLTree();
    RecordAVL r_50000entries;
    raizAVL50000entries = Insert50000EntriesinAVLTree(raizAVL50000entries, r_50000entries);
    SearchAndRemoveAVL50000Entries(raizAVL50000entries, query_numbers);
    free(raizAVL50000entries);

    AVLTree *raizAVL500000entries = CreateAVLTree();
    RecordAVL r_500000entries;
    raizAVL500000entries = Insert500000EntriesinAVLTree(raizAVL500000entries, r_500000entries);
    SearchAndRemoveAVL500000Entries(raizAVL500000entries, query_numbers);
    free(raizAVL500000entries);
}

void TestsRBTree(vector<float> query_numbers)
{
    // Inserção na árvore RedBlack
    RBTree *raizRB500entries = CreateRBTree();
    RecordRB r_500entries;
    raizRB500entries = Insert500EntriesinRBTree(raizRB500entries, r_500entries);
    SearchAndRemoveRB500Entries(raizRB500entries, query_numbers);
    free(raizRB500entries);

    RBTree *raizRB5000entries = CreateRBTree();
    RecordRB r_5000entries;
    raizRB5000entries = Insert5000EntriesinRBTree(raizRB5000entries, r_5000entries);
    SearchAndRemoveRB5000Entries(raizRB5000entries, query_numbers);
    free(raizRB5000entries);

    RBTree *raizRB50000entries = CreateRBTree();
    RecordRB r_50000entries;
    raizRB50000entries = Insert50000EntriesinRBTree(raizRB50000entries, r_50000entries);
    SearchAndRemoveRB50000Entries(raizRB50000entries, query_numbers);
    free(raizRB50000entries);

    RBTree *raizRB500000entries = CreateRBTree();
    RecordRB r_500000entries;
    raizRB500000entries = Insert500000EntriesinRBTree(raizRB500000entries, r_500000entries);
    SearchAndRemoveRB500000Entries(raizRB500000entries, query_numbers);
    free(raizRB500000entries);

    cout << query_numbers.at(1);
}
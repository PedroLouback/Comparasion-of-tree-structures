#include "includes.hpp"

int main()
{
    //Feito a criação dos arquivos de entrada e do arquivo de consulta 
    size_t t;    
    t = clock();
    CreateEntriesFile();
    CreateQueryFile();
    t = clock() - t;

    cout << "\nTempo para criação de arquivos de entradas: " << float(t)/CLOCKS_PER_SEC << " segundos\n" << endl;

    //Realização da leitura dos arquivos de entradas e enviadas para os vector
    vector<float> entries500 = Read500EntriesFile();
    vector<float> entries5000 = Read5000EntriesFile();
    vector<float> entries50000 = Read50000EntriesFile();
    vector<float> entries500000 = Read500000EntriesFile();

    //Inserção na árvore binária
    Tree *raiz = CreateBinaryTree();
    Record r;
    for (size_t i = 0; i < entries500.size(); i++){
        r.key = entries500.at(i);
        r.value = 1;
        insertTree(&raiz, r);
    }

    //Inserção na árvore AVL
    AVLTree *raizAVL = CreateAVLTree();
    RecordAVL r_avl;
    for (size_t i = 0; i < entries500.size(); i++)
    {
        r_avl.key = entries500.at(i);
        r_avl.value = 1;
        insertTreeAVL(&raizAVL, r_avl);
    }

    //Inserção na árvore RedBlack
    RBTree *raizRB = CreateRBTree();
    RecordRB r_rb;
    for (size_t i = 0; i < entries500.size(); i++)
    {
        r_rb.key = entries500.at(i);
        insertTreeRB(&raizRB, &raizRB, &raizRB, r_rb);
    }

    return 0;
}
#include "tests.hpp"

void TestsBinaryTree(vector<float> query_numbers)
{

    size_t time;
    cout << "\n||TEMPOS PARA ESTRUTURA ÁRVORE BINÁRIA||";
    // Inserção, remoção e pesquisa na árvore binária
    cout << "\n500 Entradas:";
    time = clock();
    Tree *raiz500entries = CreateBinaryTree();
    Record r_500entries;
    raiz500entries = Insert500EntriesinTree(raiz500entries, r_500entries);
    time = clock() - time;
    cout << "\nMontagem de estrutura: " << float(time) / CLOCKS_PER_SEC << " segundos";
    SearchAndRemove500Entries(raiz500entries, query_numbers);
    free(raiz500entries);

    cout << "\n5000 Entradas:";
    time = clock();
    Tree *raiz5000entries = CreateBinaryTree();
    Record r_5000entries;
    raiz5000entries = Insert5000EntriesinTree(raiz5000entries, r_5000entries);
    time = clock() - time;
    cout << "\nMontagem de estrutura: " << float(time) / CLOCKS_PER_SEC << " segundos";
    SearchAndRemove5000Entries(raiz5000entries, query_numbers);
    free(raiz5000entries);

    cout << "\n50000 Entradas:";
    time = clock();
    Tree *raiz50000entries = CreateBinaryTree();
    Record r_50000entries;
    raiz50000entries = Insert50000EntriesinTree(raiz50000entries, r_50000entries);
    time = clock() - time;
    cout << "\nMontagem de estrutura: " << float(time) / CLOCKS_PER_SEC << " segundos";
    SearchAndRemove50000Entries(raiz50000entries, query_numbers);
    free(raiz50000entries);

    cout << "\n500000 Entradas:";
    time = clock();
    Tree *raiz500000entries = CreateBinaryTree();
    Record r_500000entries;
    raiz500000entries = Insert500000EntriesinTree(raiz500000entries, r_500000entries);
    time = clock() - time;
    cout << "\nMontagem de estrutura: " << float(time) / CLOCKS_PER_SEC << " segundos";
    SearchAndRemove500000Entries(raiz500000entries, query_numbers);
    free(raiz500000entries);
}

void TestsAVLTree(vector<float> query_numbers)
{
    size_t time;
    cout << "\n||TEMPOS PARA ESTRUTURA ÁRVORE AVL||";
    // Inserção, remoção e pesquisa na árvore AVL
    cout << "\n500 Entradas:";
    time = clock();
    AVLTree *raizAVL500entries = CreateAVLTree();
    RecordAVL r_500entries;
    raizAVL500entries = Insert500EntriesinAVLTree(raizAVL500entries, r_500entries);
    time = clock() - time;
    cout << "\nMontagem de estrutura: " << float(time) / CLOCKS_PER_SEC << " segundos";
    SearchAndRemoveAVL500Entries(raizAVL500entries, query_numbers);
    free(raizAVL500entries);

    cout << "\n5000 Entradas:";
    time = clock();
    AVLTree *raizAVL5000entries = CreateAVLTree();
    RecordAVL r_5000entries;
    raizAVL5000entries = Insert5000EntriesinAVLTree(raizAVL5000entries, r_5000entries);
    time = clock() - time;
    cout << "\nMontagem de estrutura: " << float(time) / CLOCKS_PER_SEC << " segundos";
    SearchAndRemoveAVL5000Entries(raizAVL5000entries, query_numbers);
    free(raizAVL5000entries);

    cout << "\n50000 Entradas:";
    time = clock();
    AVLTree *raizAVL50000entries = CreateAVLTree();
    RecordAVL r_50000entries;
    raizAVL50000entries = Insert50000EntriesinAVLTree(raizAVL50000entries, r_50000entries);
    time = clock() - time;
    cout << "\nMontagem de estrutura: " << float(time) / CLOCKS_PER_SEC << " segundos";
    SearchAndRemoveAVL50000Entries(raizAVL50000entries, query_numbers);
    free(raizAVL50000entries);

    cout << "\n500000 Entradas:";
    time = clock();
    AVLTree *raizAVL500000entries = CreateAVLTree();
    RecordAVL r_500000entries;
    raizAVL500000entries = Insert500000EntriesinAVLTree(raizAVL500000entries, r_500000entries);
    time = clock() - time;
    cout << "\nMontagem de estrutura: " << float(time) / CLOCKS_PER_SEC << " segundos";
    SearchAndRemoveAVL500000Entries(raizAVL500000entries, query_numbers);
    free(raizAVL500000entries);
}

void TestsRBTree(vector<float> query_numbers)
{
    ifstream entries_file;
    string number_in_string;
    float number;
    size_t time;

    cout << "\n||TEMPOS PARA ESTRUTURA ÁRVORE REDBLACK||";
    // Insere, pesquisa e remove na árvore RedBlack de 500 entradas
    cout << "\n500 Entradas:";
    time = clock();
    RBTree *RB500entries = cria_ArvoreRB();
    entries_file.open("src/files/500entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        insere_RBTree(RB500entries, number);
    }
    time = clock() - time;
    cout << "\nMontagem de estrutura: " << float(time) / CLOCKS_PER_SEC << " segundos";
    entries_file.close();
    SearchAndRemoveRB500Entries(RB500entries, query_numbers);

    // Insere, pesquisa e remove na árvore RedBlack de 5000 entradas
    cout << "\n5000 Entradas:";
    time = clock();
    RBTree *RB5000entries = cria_ArvoreRB();
    entries_file.open("src/files/5000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        insere_RBTree(RB5000entries, number);
    }
    time = clock() - time;
    cout << "\nMontagem de estrutura: " << float(time) / CLOCKS_PER_SEC << " segundos";
    entries_file.close();
    SearchAndRemoveRB5000Entries(RB5000entries, query_numbers);

    // Insere, pesquisa e remove na árvore RedBlack de 50000 entradas
    cout << "\n50000 Entradas:";
    time = clock();
    RBTree *RB50000entries = cria_ArvoreRB();
    entries_file.open("src/files/50000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        insere_RBTree(RB50000entries, number);
    }
    time = clock() - time;
    cout << "\nMontagem de estrutura: " << float(time) / CLOCKS_PER_SEC << " segundos";
    entries_file.close();
    SearchAndRemoveRB50000Entries(RB50000entries, query_numbers);

    // Insere, pesquisa e remove na árvore RedBlack de 500000 entradas
    cout << "\n500000 Entradas:";
    time = clock();
    RBTree *RB500000entries = cria_ArvoreRB();
    entries_file.open("src/files/500000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        insere_RBTree(RB500000entries, number);
    }
    time = clock() - time;
    cout << "\nMontagem de estrutura: " << float(time) / CLOCKS_PER_SEC << " segundos";
    entries_file.close();
    SearchAndRemoveRB500Entries(RB500000entries, query_numbers);
}

void TestsVectors(vector<float> query_numbers)
{
    ifstream entries_file;
    string number_in_string;
    float number;
    size_t time;

    cout << "\n||TEMPOS PARA VETORES||";
    cout << "\n500 Entradas: ";
    // Criação e ordenação do vetor de 500 entradas
    vector<float> vector_500entries;
    entries_file.open("src/files/500entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        vector_500entries.push_back(number);
    }
    time = clock();
    sort(vector_500entries.begin(), vector_500entries.end());
    time = clock() - time;
    cout << "\nOrdenação: " << float(time) / CLOCKS_PER_SEC << " segundos";
    entries_file.close();
    time = clock();
    for (size_t i = 0; i < query_numbers.size(); i++)
    {
        binary_search(vector_500entries.begin(), vector_500entries.end(), query_numbers.at(i));
    }
    time = clock() - time;
    cout << "\nPesquisa Binária: " << float(time) / CLOCKS_PER_SEC << " segundos\n";

    // Criação e ordenação do vetor de 5000 entradas
    cout << "\n5000 Entradas: ";
    vector<float> vector_5000entries;
    entries_file.open("src/files/5000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        vector_5000entries.push_back(number);
    }
    time = clock();
    sort(vector_5000entries.begin(), vector_5000entries.end());
    time = clock() - time;
    cout << "\nOrdenação: " << float(time) / CLOCKS_PER_SEC << " segundos";
    entries_file.close();
    time = clock();
    for (size_t i = 0; i < query_numbers.size(); i++)
    {
        binary_search(vector_5000entries.begin(), vector_5000entries.end(), query_numbers.at(i));
    }
    time = clock() - time;
    cout << "\nPesquisa Binária: " << float(time) / CLOCKS_PER_SEC << " segundos\n";

    // Criação e ordenação do vetor de 50000 entradas
    cout << "\n50000 Entradas: ";
    vector<float> vector_50000entries;
    entries_file.open("src/files/50000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        vector_50000entries.push_back(number);
    }
    time = clock();
    sort(vector_50000entries.begin(), vector_50000entries.end());
    time = clock() - time;
    cout << "\nOrdenação: " << float(time) / CLOCKS_PER_SEC << " segundos";
    entries_file.close();
    time = clock();
    for (size_t i = 0; i < query_numbers.size(); i++)
    {
        binary_search(vector_50000entries.begin(), vector_50000entries.end(), query_numbers.at(i));
    }
    time = clock() - time;
    cout << "\nPesquisa Binária: " << float(time) / CLOCKS_PER_SEC << " segundos\n";

    // Criação, ordenação e pesquisa do vetor de 500000 entradas
    cout << "\n500000 Entradas: ";
    vector<float> vector_500000entries;
    entries_file.open("src/files/500000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        vector_500000entries.push_back(number);
    }
    time = clock();
    sort(vector_500000entries.begin(), vector_500000entries.end());
    time = clock() - time;
    cout << "\nOrdenação: " << float(time) / CLOCKS_PER_SEC << " segundos";
    entries_file.close();
    time = clock();
    for (size_t i = 0; i < query_numbers.size(); i++)
    {
        binary_search(vector_500000entries.begin(), vector_500000entries.end(), query_numbers.at(i));
    }
    time = clock() - time;
    cout << "\nPesquisa Binária: " << float(time) / CLOCKS_PER_SEC << " segundos\n";
}

void TestsMaps(vector<float> query_numbers)
{

    cout << "\n||TEMPOS PARA PESQUISAS UTILIZANDO ESTRUTURAS MAPs||";

    InsertAndSearch500EntriesinMap(query_numbers);

    InsertAndSearch5000EntriesinMap(query_numbers);

    InsertAndSearch50000EntriesinMap(query_numbers);

    InsertAndSearch500000EntriesinMap(query_numbers);

    InsertAndSearch500EntriesinUnorderedMap(query_numbers);

    InsertAndSearch5000EntriesinUnorderedMap(query_numbers);

    InsertAndSearch50000EntriesinUnorderedMap(query_numbers);

    InsertAndSearch500000EntriesinUnorderedMap(query_numbers);
}
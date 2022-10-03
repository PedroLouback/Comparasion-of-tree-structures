#include "includes.hpp"

int main()
{
    // Feito a criação dos arquivos de entrada e do arquivo de consulta
    size_t t;
    t = clock();
    CreateEntriesFile();
    CreateQueryFile();
    t = clock() - t;

    cout << "\nTempo para criação de arquivos de entradas: " << float(t) / CLOCKS_PER_SEC << " segundos\n"
         << endl;

    // Realização da leitura dos arquivos de entradas e enviadas para os vector
    vector<float> entries500 = Read500EntriesFile();
    vector<float> entries5000 = Read5000EntriesFile();
    vector<float> entries50000 = Read50000EntriesFile();
    vector<float> entries500000 = Read500000EntriesFile();
    vector<float> query_numbers = ReadQueryNumbers();

    // Realização dos testes de inserção e remoção em cada tipo de árvore
    TestsBinaryTree(entries500, entries5000, entries50000, entries500000, query_numbers);
    TestsAVLTree(entries500, entries5000, entries50000, entries500000, query_numbers);
    TestsRBTree(entries500, entries5000, entries50000, entries500000, query_numbers);

    return 0;
}
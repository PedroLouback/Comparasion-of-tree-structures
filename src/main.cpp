#include "includes.hpp"

int main()
{
    // // Feito a criação dos arquivos de entrada e do arquivo de consulta
    // size_t t;
    // t = clock();
    // CreateEntriesFile();
    // CreateQueryFile();
    // t = clock() - t;

    // cout << "\nTempo para criação de arquivos de entradas: " << float(t) / CLOCKS_PER_SEC << " segundos\n"
    //      << endl;

    // Realização da leitura do arquivo de consultas
    vector<float> query_numbers = ReadQueryNumbers();

    // Realização dos testes de inserção e remoção em cada tipo de árvore
    TestsBinaryTree(query_numbers);
    TestsAVLTree(query_numbers);
    TestsRBTree(query_numbers);

    return 0;
}

#include "includes.hpp"

int main()
{
    // Realização da leitura do arquivo de consultas
    vector<float> query_numbers = ReadQueryNumbers();

    // Realização dos testes de inserção e remoção em cada tipo de árvore
    TestsBinaryTree(query_numbers);
    TestsAVLTree(query_numbers);
    TestsRBTree(query_numbers);
    TestsVectors(query_numbers);
    TestsMaps(query_numbers);

    return 0;
}

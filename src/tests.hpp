#ifndef TESTS_HPP
#define TESTS_HPP

#include "includes.hpp"

using namespace std;

void TestsBinaryTree(vector<float> query_numbers);
void TestsAVLTree(vector<float> query_numbers);
void TestsRBTree(vector<float> query_numbers);
void SearchAndRemove500Entries(Tree *raiz500entries, vector<float> query_numbers);

#endif
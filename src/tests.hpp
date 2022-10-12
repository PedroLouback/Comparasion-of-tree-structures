#ifndef TESTS_HPP
#define TESTS_HPP

#include "includes.hpp"

using namespace std;

void TestsBinaryTree(vector<float> query_numbers);
void TestsAVLTree(vector<float> query_numbers);
void TestsRBTree(vector<float> query_numbers);
void TestsVectors(vector<float> query_numbers);
void TestsMaps(vector<float> query_numbers);
vector<float> heapify(vector<float> vector_entries, int n, int i);
vector<float> heapSort(vector<float> vector_entries, int n);
int binarySearch(vector<float> vector_entries, int l, int r, float number);

#endif
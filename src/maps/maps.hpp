#ifndef MAPS_HPP
#define MAPS_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <map>
#include <sstream>

using namespace std;

void InsertAndSearch500EntriesinMap(vector<float> query_numbers);
void InsertAndSearch5000EntriesinMap(vector<float> query_numbers);
void InsertAndSearch50000EntriesinMap(vector<float> query_numbers);
void InsertAndSearch500000EntriesinMap(vector<float> query_numbers);

void InsertAndSearch500EntriesinUnorderedMap(vector<float> query_numbers);
void InsertAndSearch5000EntriesinUnorderedMap(vector<float> query_numbers);
void InsertAndSearch50000EntriesinUnorderedMap(vector<float> query_numbers);
void InsertAndSearch500000EntriesinUnorderedMap(vector<float> query_numbers);

#endif

#ifndef FILES_HPP
#define FILES_HPP

#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

void CreateEntriesFile();
void CreateQueryFile();
vector<float> Read500EntriesFile();
vector<float> Read5000EntriesFile();
vector<float> Read50000EntriesFile();
vector<float> Read500000EntriesFile();

#endif
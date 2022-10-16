#include "maps.hpp"

void InsertAndSearch500EntriesinMap(vector<float> query_numbers)
{

    ifstream entries_file;
    string number_in_string;
    float number;
    map<int, float> map500entries;
    size_t time;

    entries_file.open("src/files/500entries.txt");
    for (int i = 0; i < 500; i++)
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        map500entries.emplace(i, number);
    }
    entries_file.close();
    cout << "\n500 Entradas - map:";
    time = clock();
    for (size_t i = 0; i < query_numbers.size(); i++)
    {
        map500entries.find(query_numbers.at(i));
    }
    time = clock() - time;
    cout << "\nPesquisa: " << float(time) / CLOCKS_PER_SEC << " segundos" << endl;
}

void InsertAndSearch5000EntriesinMap(vector<float> query_numbers)
{

    ifstream entries_file;
    string number_in_string;
    float number;
    map<int, float> map5000entries;
    size_t time;

    entries_file.open("src/files/5000entries.txt");
    for (int i = 0; i < 5000; i++)
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        map5000entries.emplace(i, number);
    }
    entries_file.close();
    cout << "\n5000 Entradas - map:";
    time = clock();
    for (size_t i = 0; i < query_numbers.size(); i++)
    {
        map5000entries.find(query_numbers.at(i));
    }
    time = clock() - time;
    cout << "\nPesquisa: " << float(time) / CLOCKS_PER_SEC << " segundos" << endl;
}

void InsertAndSearch50000EntriesinMap(vector<float> query_numbers)
{

    ifstream entries_file;
    string number_in_string;
    float number;
    map<int, float> map50000entries;
    size_t time;

    entries_file.open("src/files/50000entries.txt");
    for (int i = 0; i < 50000; i++)
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        map50000entries.emplace(i, number);
    }
    entries_file.close();
    cout << "\n50000 Entradas - map:";
    time = clock();
    for (size_t i = 0; i < query_numbers.size(); i++)
    {
        map50000entries.find(query_numbers.at(i));
    }
    time = clock() - time;
    cout << "\nPesquisa: " << float(time) / CLOCKS_PER_SEC << " segundos" << endl;
}

void InsertAndSearch500000EntriesinMap(vector<float> query_numbers)
{

    ifstream entries_file;
    string number_in_string;
    float number;
    map<int, float> map500000entries;
    size_t time;

    entries_file.open("src/files/500000entries.txt");
    for (int i = 0; i < 500000; i++)
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        map500000entries.emplace(i, number);
    }

    entries_file.close();
    cout << "\n500000 Entradas - map:";
    time = clock();
    for (size_t i = 0; i < query_numbers.size(); i++)
    {
        map500000entries.find(query_numbers.at(i));
    }
    time = clock() - time;
    cout << "\nPesquisa: " << float(time) / CLOCKS_PER_SEC << " segundos" << endl;
}

void InsertAndSearch500EntriesinUnorderedMap(vector<float> query_numbers)
{

    ifstream entries_file;
    string number_in_string;
    float number;
    unordered_map<int, float> unordered_map500entries;
    size_t time;
    
    entries_file.open("src/files/500entries.txt");
    for (int i = 0; i < 500; i++)
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        unordered_map500entries.emplace(i, number);
    }
    entries_file.close();
    cout << "\n500 Entradas - unordered map:";
    time = clock();
    for (size_t i = 0; i < query_numbers.size(); i++)
    {
        unordered_map500entries.find(query_numbers.at(i));
    }
    time = clock() - time;
    cout << "\nPesquisa: " << float(time) / CLOCKS_PER_SEC << " segundos" << endl;
}

void InsertAndSearch5000EntriesinUnorderedMap(vector<float> query_numbers)
{

    ifstream entries_file;
    string number_in_string;
    float number;
    unordered_map<int, float> unordered_map5000entries;
    size_t time;

    entries_file.open("src/files/5000entries.txt");
    for (int i = 0; i < 5000; i++)
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        unordered_map5000entries.emplace(i, number);
    }
    entries_file.close();
    cout << "\n5000 Entradas - unordered map:";
    time = clock();
    for (size_t i = 0; i < query_numbers.size(); i++)
    {
        unordered_map5000entries.find(query_numbers.at(i));
    }
    time = clock() - time;
    cout << "\nPesquisa: " << float(time) / CLOCKS_PER_SEC << " segundos" << endl;
}

void InsertAndSearch50000EntriesinUnorderedMap(vector<float> query_numbers)
{

    ifstream entries_file;
    string number_in_string;
    float number;
    unordered_map<int, float> unordered_map50000entries;
    size_t time;

    entries_file.open("src/files/50000entries.txt");
    for (int i = 0; i < 50000; i++)
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        unordered_map50000entries.emplace(i, number);
    }
    entries_file.close();
    cout << "\n50000 Entradas - unordered map:";
    time = clock();
    for (size_t i = 0; i < query_numbers.size(); i++)
    {
        unordered_map50000entries.find(query_numbers.at(i));
    }
    time = clock() - time;
    cout << "\nPesquisa: " << float(time) / CLOCKS_PER_SEC << " segundos" << endl;
}

void InsertAndSearch500000EntriesinUnorderedMap(vector<float> query_numbers)
{

    ifstream entries_file;
    string number_in_string;
    float number;
    unordered_map<int, float> unordered_map500000entries;
    size_t time = 0;

    entries_file.open("src/files/500000entries.txt");
    for (int i = 0; i < 500000; i++){
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        unordered_map500000entries.emplace(i, number);
    }
    entries_file.close();

    cout << "\n500000 Entradas - unordered map:";
    time = clock();
    for (size_t i = 0; i < query_numbers.size(); i++)
    {
        unordered_map500000entries.find(query_numbers.at(i));
    }
    time = clock() - time;
    cout << "\nPesquisa: " << float(time) / CLOCKS_PER_SEC << " segundos" << endl;
}

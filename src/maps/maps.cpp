#include "maps.hpp"

void InsertAndSearch500EntriesinMap(vector<float> query_numbers)
{

    ifstream entries_file;
    string number_in_string;
    float number;
    int i = 0;
    map<int, float> map500entries;
    size_t time;

    entries_file.open("src/files/500entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        map500entries.insert(make_pair(i, number));
        i++;
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
    int i = 0;
    map<int, float> map5000entries;
    size_t time;

    entries_file.open("src/files/5000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        map5000entries.insert(make_pair(i, number));
        i++;
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
    int i = 0;
    map<int, float> map50000entries;
    size_t time;

    entries_file.open("src/files/50000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        map50000entries.insert(make_pair(i, number));
        i++;
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
    int i = 0;
    map<int, float> map500000entries;
    size_t time;

    entries_file.open("src/files/500000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        map500000entries.insert(make_pair(i, number));
        i++;
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
    int i = 0;
    unordered_map<int, float> unordered_map500entries;
    size_t time;

    entries_file.open("src/files/500entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        unordered_map500entries.insert(make_pair(i, number));
        i++;
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
    int i = 0;
    unordered_map<int, float> unordered_map5000entries;
    size_t time;

    entries_file.open("src/files/5000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        unordered_map5000entries.insert(make_pair(i, number));
        i++;
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
    int i = 0;
    unordered_map<int, float> unordered_map50000entries;
    size_t time;

    entries_file.open("src/files/50000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        unordered_map50000entries.insert(make_pair(i, number));
        i++;
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
    int i = 0;
    unordered_map<int, float> unordered_map500000entries;
    size_t time;

    entries_file.open("src/files/500000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        unordered_map500000entries.insert(make_pair(i, number));
        i++;
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

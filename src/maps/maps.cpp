#include "maps.hpp"

void Insert500EntriesinMap()
{

    ifstream entries_file;
    string number_in_string;
    float number;
    int i = 0;
    map<int, float> map500entries;

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
}

void Insert5000EntriesinMap()
{

    ifstream entries_file;
    string number_in_string;
    float number;
    int i = 0;
    map<int, float> map5000entries;

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
}

void Insert50000EntriesinMap()
{

    ifstream entries_file;
    string number_in_string;
    float number;
    int i = 0;
    map<int, float> map50000entries;

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
}

void Insert500000EntriesinMap()
{

    ifstream entries_file;
    string number_in_string;
    float number;
    int i = 0;
    map<int, float> map500000entries;

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
}

void Insert500EntriesinUnorderedMap()
{

    ifstream entries_file;
    string number_in_string;
    float number;
    int i = 0;
    unordered_map<int, float> unordered_map500entries;

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
}

void Insert5000EntriesinUnorderedMap()
{

    ifstream entries_file;
    string number_in_string;
    float number;
    int i = 0;
    unordered_map<int, float> unordered_map5000entries;

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
}

void Insert50000EntriesinUnorderedMap()
{

    ifstream entries_file;
    string number_in_string;
    float number;
    int i = 0;
    unordered_map<int, float> unordered_map50000entries;

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
}

void Insert500000EntriesinUnorderedMap()
{

    ifstream entries_file;
    string number_in_string;
    float number;
    int i = 0;
    unordered_map<int, float> unordered_map500000entries;

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
}

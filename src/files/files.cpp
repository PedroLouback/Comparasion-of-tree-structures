#include "files.hpp"

void CreateEntriesFile()
{

    ofstream entries_file;
    string past;

    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<> distr(1, 100);

    // Create a file with 500 entries
    entries_file.open("src/files/500entries.txt");
    if (!entries_file)
    {
        cout << "\nArquivo não pode ser aberto!" << endl;
        abort();
    }

    srand(time(NULL));
    for (int i = 0; i < 500; i++)
    {
        entries_file << setprecision(10) << distr(eng) << endl;
    }
    entries_file.close();

    // Create a file with 5000 entries
    entries_file.open("src/files/5000entries.txt");
    if (!entries_file)
    {
        cout << "\nArquivo não pode ser aberto!" << endl;
        abort();
    }

    srand(time(NULL));
    for (int i = 0; i < 5000; i++)
    {
        entries_file << setprecision(10) << distr(eng) << endl;
    }
    entries_file.close();

    // Create a file with 50000 entries
    entries_file.open("src/files/50000entries.txt");
    if (!entries_file)
    {
        cout << "\nArquivo não pode ser aberto!" << endl;
        abort();
    }

    srand(time(NULL));
    for (int i = 0; i < 50000; i++)
    {
        entries_file << setprecision(10) << distr(eng) << endl;
    }
    entries_file.close();

    // Create a file with 500000 entries
    entries_file.open("src/files/500000entries.txt");
    if (!entries_file)
    {
        cout << "\nArquivo não pode ser aberto!" << endl;
        abort();
    }

    srand(time(NULL));
    for (int i = 0; i < 500000; i++)
    {
        entries_file << setprecision(10) << distr(eng) << endl;
    }
    entries_file.close();
}

void CreateQueryFile()
{

    ofstream query_file;

    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<> distr(1, 100);

    query_file.open("src/files/querynumbers.txt");
    if (!query_file)
    {
        cout << "\nArquivo não pode ser aberto!" << endl;
        abort();
    }

    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        query_file << setprecision(10) << distr(eng) << endl;
    }
    query_file.close();
}

vector<float> Read500EntriesFile()
{
    ifstream entries_file;
    string number_in_string;
    float number;
    vector<float> vector_entries;

    entries_file.open("src/files/500entries.txt");
    while(!entries_file.eof()){
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        vector_entries.push_back(number);
    }

    return vector_entries;
}

vector<float> Read5000EntriesFile()
{
    ifstream entries_file;
    string number_in_string;
    float number;
    vector<float> vector_entries;

    entries_file.open("src/files/5000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        vector_entries.push_back(number);
    }

    return vector_entries;
}

vector<float> Read50000EntriesFile()
{
    ifstream entries_file;
    string number_in_string;
    float number;
    vector<float> vector_entries;

    entries_file.open("src/files/50000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        vector_entries.push_back(number);
    }

    return vector_entries;
}

vector<float> Read500000EntriesFile()
{
    ifstream entries_file;
    string number_in_string;
    float number;
    vector<float> vector_entries;

    entries_file.open("src/files/500000entries.txt");
    while (!entries_file.eof())
    {
        getline(entries_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        vector_entries.push_back(number);
    }

    return vector_entries;
}
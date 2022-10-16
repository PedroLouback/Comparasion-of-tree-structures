#include "files.hpp"

vector<float> ReadQueryNumbers()
{

    ifstream query_file;
    string number_in_string;
    float number;
    vector<float> vector_query;

    query_file.open("src/files/querynumbers.txt");
    while (!query_file.eof())
    {
        getline(query_file, number_in_string);
        istringstream in(number_in_string);
        in >> number;
        vector_query.push_back(number);
    }

    return vector_query;
}
#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &str, string delim = "	")
{
    vector<string> cont;
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos)
    {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
    return cont;
}

int main()
{
    string subjectAndPrerequisite, delim = "	";
    vector<string> response;
    unordered_map<string, list<string>> adjacencyList(40);
    while (getline(cin, subjectAndPrerequisite))
    {
        response = split(subjectAndPrerequisite, delim);
        string subject = response[0];
        string prerequisite = response[1];
        adjacencyList[prerequisite].push_back(subject);
    }

    for (auto &value : adjacencyList)
    {
        string prerequisite = value.first;
        list<string> adjacentVertices = value.second;
        list<string>::iterator iteratorInListOfSubjects = adjacentVertices.begin();

        cout << prerequisite;
        while (iteratorInListOfSubjects != adjacentVertices.end())
        {
            cout << " -> " << (*iteratorInListOfSubjects);
            ++iteratorInListOfSubjects;
        }
        cout << endl;
    }
}

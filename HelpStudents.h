#ifndef CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#define CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


class HelpStudents{
private:
    int N;
    int M;
    int K;
    vector <pair<pair<int,int>,int>> ways;
    vector<bool> visited;
    long long int INF;
    vector<long long int> dist;

public:
    HelpStudents(int  N, int  M, int K, vector < pair< pair <int,int> , int > > ways);
    long long int firstStudent();
    long long int secondStudent();
    long long int thirdStudent();
    void dfs(int u);
    long long int fourthStudent();
    long long int fifthStudent();

    // YOU CAN ADD YOUR HELPER FUNCTIONS AND MEMBER FIELDS

};

#endif //CMPE250_ASSIGNMENT3_HELPSTUDENTS_H

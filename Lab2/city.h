#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <string>

using std::cout;
using std::string;

struct city {
    string name;
    int x;
    int y;
};

struct node {
    node *leftChild = NULL;
    node *rightChild = NULL;
    node *parent = NULL;
    
    city data;
};

class cityList{
public:
    cityList();
    void insert(int, int, string);
    void deleteByName(string);
    void deleteByCoordinate(int, int);
    node *searchByName(string);
    node *searchByCoordinate(int, int, node*);
    void printAll(node *);
    void print(int, int, int, node *);

    node *getRoot();
private:
    node *root;
    int nodenum;

    void deleteCity(node *);
};

#endif

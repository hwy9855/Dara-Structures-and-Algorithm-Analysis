#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <string.h>
using std::string;
using std::cout;

struct city {
    int x;
    int y;
    string name;
    city *next = NULL;
};

class cityList {
public:
    cityList();
    void insert(int,int,string);
    void deleteByName(string);
    void deleteByCoordiante(int,int);
    void searchByName(string);
    void searchByCoordinate(int,int);
    void print(int,int,int);
private:
    city *head;

};

#endif

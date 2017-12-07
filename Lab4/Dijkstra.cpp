#include <iostream>

using namespace std;

#define INF 10000007
#define MaxNum 6

struct path {
    path *nextPath;
    double time;
    double length;
    int idOfNextCity;

    path() {
        nextPath = NULL;
    }

    path(double t, double l, int i) {
        time = t;
        length = l;
        idOfNextCity = i;
        nextPath = NULL;
    }
};

struct city {
    string name;
    int id;

    city(string n, int i) {
        name = n;
        id = i;
    }
};

city *cities[MaxNum];
path *paths[MaxNum];
bool isval[MaxNum];
double val[MaxNum];
int bef[MaxNum];

void Dijkstra_length(int from, int to) {
    for (int i = 0; i < MaxNum; i++) {
        val[i] = INF;
        isval[i] = true;
    } //initialise
    
    val[from] = 0;
    isval[from] = false;
    int curr = from;

    while (curr != to) {
        path *tmp = paths[curr];
        for (; tmp->nextPath != NULL; ) {
            tmp = tmp->nextPath;
            if (val[tmp->idOfNextCity] > val[curr] + tmp->length) {
                val[tmp->idOfNextCity] = val[curr] + tmp->length;
                bef[tmp->idOfNextCity] = curr;
            }
        }

        int ttmp = INF;
        for (int i = 0; i < MaxNum; i++) {
            if(val[i] < ttmp && isval[i]) {
                curr = i;
                ttmp = val[i];
            }
        }
        isval[curr] = false;
    }
    while (from != to) {
        cout<<cities[to]->name<<" <- ";
        to = bef[to];
    }
    cout<<cities[from]->name;
    cout<<"\n";
}

void Dijkstra_time(int from, int to) {
    for (int i = 0; i < MaxNum; i++) {
        val[i] = INF;
        isval[i] = true;
    } //initialise
    
    val[from] = 0;
    isval[from] = false;
    int curr = from;

    while (curr != to) {
        path *tmp = paths[curr];
        for (; tmp->nextPath != NULL; ) {
            tmp = tmp->nextPath;
            if (val[tmp->idOfNextCity] > val[curr] + tmp->time) {
                val[tmp->idOfNextCity] = val[curr] + tmp->time;
                bef[tmp->idOfNextCity] = curr;
            }
        }

        int ttmp = INF;
        for (int i = 0; i < MaxNum; i++) {
            if(val[i] < ttmp && isval[i]) {
                curr = i;
                ttmp = val[i];
            }
        }
        isval[curr] = false;
    }
    while (from != to) {
        cout<<cities[to]->name<<" <- ";
        to = bef[to];
    }
    cout<<cities[from]->name;
    cout<<"\n";
}


int main() {
    cities[0] = new city("New York", 0);
    cities[1] = new city("Dayton", 1);
    cities[2] = new city("Los Angeles", 2);
    cities[3] = new city("Atlanta", 3);
    cities[4] = new city("Philadelphia", 4);
    cities[5] = new city("Chicaco", 5);


    paths[0] = new path();
    paths[1] = new path();
    paths[2] = new path();
    paths[3] = new path();
    paths[4] = new path();
    paths[5] = new path();

    paths[0]->nextPath = new path(10, 30, 2);
    paths[0]->nextPath->nextPath = new path(30, 10, 4);
    paths[0]->nextPath->nextPath->nextPath = new path(100, 5, 5);

    paths[1]->nextPath = new path(5, 100, 2);

    paths[2]->nextPath = new path(50, 10, 3);

    paths[3]->nextPath = new path(10, 50, 5);

    paths[4]->nextPath = new path(20, 60, 3);
    paths[4]->nextPath->nextPath = new path(60, 20, 5);

    Dijkstra_length(0, 5);
    Dijkstra_time(0, 5);
    return 0;
}

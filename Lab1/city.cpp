#include "city.h"

cityList::cityList() {
    head = new city;
}

void cityList::insert(int x, int y, string n) {
    city *tmp = head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    city *newCity = new city;
    newCity->x = x;
    newCity->y = y;
    newCity->name = n;
    tmp->next = newCity;
    return;
}

void cityList::deleteByName(string n) {
    city *tmp = head;
    city *tmpForDelete;
    while (tmp->next !=NULL) {
        tmpForDelete = tmp;
        tmp = tmp->next;
        if(tmp->name == n) {
            tmpForDelete->next = tmp->next;
            delete tmp;
            cout<<"Delete successfully!\n";
            return;
        }
    }
    cout<<"Error, data not found!\n";
    return;
}

void cityList::deleteByCoordiante(int x, int y) {
    city *tmp = head;
    city *tmpForDelete;
    while (tmp->next !=NULL) {
        tmpForDelete = tmp;
        tmp = tmp->next;
        if(tmp->x == x && tmp->y == y) {
            tmpForDelete->next = tmp->next;
            delete tmp;
            cout<<"Delete successfully!\n";
            return;
        }
    }
    cout<<"Error, data not found!\n";
    return;
}

void cityList::searchByName(string n) {
    city *tmp = head;
    while (tmp->next !=NULL) {
        tmp = tmp->next;
        if(tmp->name == n) {
            cout<<"City found :\n";
            cout<<"City : "<<tmp->name<<"\n";
            cout<<"Coordinate : "<<tmp->x<<" "<<tmp->y<<"\n";
            return;
        }
    }
    cout<<"City not found!\n";
    return;
}

void cityList::searchByCoordinate(int x, int y) {
    city *tmp = head;
    while (tmp->next !=NULL) {
        tmp = tmp->next;
        if(tmp->x == x && tmp->y == y) {
            cout<<"City found :\n";
            cout<<"City : "<<tmp->name<<"\n";
            cout<<"Coordinate : "<<tmp->x<<" "<<tmp->y<<"\n";
            return;
        }
    }
    cout<<"City not found!\n";
    return;
}

void cityList::print(int x, int y, int distance) {
    double citydis = 0;
    int count = 0;
    city *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        citydis = (tmp->x - x)*(tmp->x - x) + (tmp->y - y)*(tmp->y - y);
        if(citydis <= distance*distance) {
            ++count;
            cout<<"#"<<count<<"\n";
            cout<<"City : "<<tmp->name<<"\n";
            cout<<"Coordinate : "<<tmp->x<<" "<<tmp->y<<"\n";
        }
    }
    cout<<count<<" avalable!\n";
}

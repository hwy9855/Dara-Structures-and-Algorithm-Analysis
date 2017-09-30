#include "city.h"

cityList::cityList() {
    root = new node;
    nodenum = 0;
}

node *cityList::getRoot() {
    return root;
}

void cityList::insert(int x, int y, string n) {
    city newCity;
    newCity.x = x;
    newCity.y = y;
    newCity.name = n;
    nodenum++;

    if (nodenum == 1) {
        root->data = newCity;
        cout<<"Insert successfully!\n";
        return;
    }

    node *tmp = root;
    while (true) {
        if(tmp->data.name == n) {
            cout<<"The city is already here!\n";
            return;
        }
        else if(tmp->data.name > n) {
            if(tmp->leftChild == NULL) {
                tmp->leftChild = new node;
                tmp->leftChild->data = newCity;
                tmp->leftChild->parent = tmp;
                cout<<"Insert successfully!\n";
                return;
            }
            else {
                tmp = tmp->leftChild;
                continue;
            }
        }
        else if(tmp->data.name < n) {
            if(tmp->rightChild == NULL) {
                tmp->rightChild = new node;
                tmp->rightChild->data = newCity;
                tmp->rightChild->parent = tmp;
                cout<<"Insert successfully!\n";
                return;
            }
            else {
                tmp = tmp->rightChild;
                continue;
            }
        }
    }
}

void cityList::deleteByName(string n) {
    node *tmp = searchByName(n);
    if (tmp == NULL) {
        return;
    }
    deleteCity(tmp);
    return;
}

void cityList::deleteByCoordinate(int x, int y) {
    node *tmp = searchByCoordinate(x,y,root);
    if(tmp == NULL) {
        return;
    }
    deleteCity(tmp);
    return;
}

node *cityList::searchByName(string n) {
    node *tmp = root;
    while (tmp != NULL) {
        if(tmp->data.name == n) {
            cout<<"City: "<<tmp->data.name;
            cout<<"\nCoordinate: "<<tmp->data.x<<" "<<tmp->data.y<<"\n";
            return tmp;
        }
        else if(tmp->data.name > n) {
            tmp = tmp->leftChild;
        }
        else if(tmp->data.name < n) {
            tmp = tmp->rightChild;
        }
    }
    cout<<"City not found!\n";
    return NULL;
}

node *cityList::searchByCoordinate(int x, int y, node *tmp) {
    node *ttmp;
    if(tmp == NULL) {
        return NULL;
    }
    else if(tmp->data.x == x && tmp->data.y == y) {
        cout<<"City: "<<tmp->data.name;
        cout<<"\nCoordinate: "<<tmp->data.x<<" "<<tmp->data.y<<"\n";
        return tmp;
    }
    else {
        ttmp = searchByCoordinate(x, y, tmp->leftChild);
        if(ttmp != NULL) {
            return ttmp;
        }
        ttmp = searchByCoordinate(x, y, tmp->rightChild);
        if(ttmp != NULL) {
            return ttmp;
        }
    }
    return NULL;
}

void cityList::printAll(node *tmp) {
    if(tmp == NULL) {
        return;
    }

    cout<<"City: "<<tmp->data.name;
    cout<<"\nCoordinate: "<<tmp->data.x<<" "<<tmp->data.y<<"\n";
    printAll(tmp->leftChild);
    printAll(tmp->rightChild);
    return;
}

void cityList::print(int x, int y, int dis, node *tmp) {
    if(tmp == NULL) {
        return;
    }
    
    if((tmp->data.x - x) * (tmp->data.x - x) + (tmp->data.y - y) * (tmp->data.y - y) <= dis *dis) {
        cout<<"City: "<<tmp->data.name;
        cout<<"\nCoordinate: "<<tmp->data.x<<" "<<tmp->data.y<<"\n";
    }
    print(x, y, dis, tmp->leftChild);
    print(x, y, dis, tmp->rightChild);
    return;
}

void cityList::deleteCity(node *tmp) {
    
    nodenum--;
    if(tmp == root) {
        if(tmp->leftChild == NULL && tmp->rightChild != NULL) {
            root = tmp->leftChild;
            delete tmp;
            return;
        }
    
        if(tmp->leftChild != NULL && tmp->rightChild == NULL) {
            root = tmp->rightChild;
            delete tmp;
            return;
        }
    
        if(tmp->leftChild == NULL && tmp->rightChild == NULL) {
            root = new node;
            delete tmp;
            return;
        }
    
        //have 2 children
        node *ttmp = tmp->leftChild;
        while(ttmp->rightChild != NULL) {
            ttmp = ttmp->rightChild;
        }
        tmp->data = ttmp->data;
        if(ttmp == ttmp->parent->leftChild) {
            ttmp->parent->leftChild = NULL;
        }
        else {
            ttmp->parent->rightChild = NULL;
        }
        delete ttmp;
        return;
    }
    bool isLeft;
    if(tmp->parent->data.name > tmp->data.name) {
        isLeft = true;
    }
    else {
        isLeft = false;
    }


    //one or Child
    if(tmp->leftChild == NULL && tmp->rightChild != NULL) {
        if(isLeft) {
            tmp->rightChild->parent = tmp->parent;
            tmp->parent->leftChild = tmp->rightChild; 
        }
        else {
            tmp->rightChild->parent = tmp->parent;
            tmp->parent->rightChild = tmp->rightChild;
        }
        delete tmp;
        return;
    }

    if(tmp->leftChild != NULL && tmp->rightChild == NULL) {
        if(isLeft) {
            tmp->leftChild->parent = tmp->parent;
            tmp->parent->leftChild = tmp->leftChild; 
        }
        else {
            tmp->leftChild->parent = tmp->parent;
            tmp->parent->rightChild = tmp->leftChild;
        }
        delete tmp;
        return;
    }

    if(tmp->leftChild == NULL && tmp->rightChild == NULL) {
        if(isLeft) {
            tmp->parent->leftChild = NULL;
        }
        else {
            tmp->parent->rightChild = NULL;
        }
        delete tmp;
        return;
    }

    //have 2 children
    node *ttmp = tmp->leftChild;
    while(ttmp->rightChild != NULL) {
        ttmp = ttmp->rightChild;
    }
    tmp->data = ttmp->data;
    if(ttmp == ttmp->parent->leftChild) {
        ttmp->parent->leftChild = NULL;
    }
    else {
        ttmp->parent->rightChild = NULL;
    }
    delete ttmp;
    return;
}

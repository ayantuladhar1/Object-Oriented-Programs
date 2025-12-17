#include<iostream>
#include<vector>
#include "Header.h"
using namespace std;


int main() {

    

    int x, y;
    cout << "Enter the row (X) : ";
    cin >> x;
    cout << "Enter the column (Y) : ";
    cin >> y;
   
        Grid a1(x, y);
        Grid a2(x, y);
        Grid a3(x, y);
        a1.a1random();
        a2.a2random();
        a3.a3random();

    a3.fill(a1, a2, a3);

    cout << "Grid 1:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << a1.getGrid()[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Grid 2:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << a2.getGrid()[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Grid 3 (Result):" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << a3.getGrid()[i][j] << " ";
        }
        cout << endl;
    }

}
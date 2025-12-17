#include <iostream>
#include <vector>
using namespace std;


class Grid
{
public:
    vector<vector<int> > getGrid() const { return grid; }
    void setGrid(vector<vector<int> > a) { grid = a; }
    Grid() : X(0), Y(0) {}
    Grid(int _x, int _y);
    void a1random();
    void a2random();
    void a3random();
    void fill(const Grid& a1, const Grid& a2, Grid& a3);


private:
    int X, Y;
    vector<vector<int> >  grid;

};

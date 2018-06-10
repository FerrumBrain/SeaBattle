#include <bits/stdc++.h>

using namespace std;

#ifndef SEABATTLE_INTELLECT_H
#define SEABATTLE_INTELLECT_H


class Intellect {
public:
    virtual void initialize(vector< vector<int> > &map) = 0;
    //virtual void make_move() = 0;
protected:
    void clearing(vector< vector<int> > &map, int x, int y){
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if(map[x + i][y + j] == 4) continue;
                map[x + i][y + j] = 5;
            }
        }
    };
};


#endif //SEABATTLE_INTELLECT_H
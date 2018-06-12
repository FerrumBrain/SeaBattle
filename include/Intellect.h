#include <bits/stdc++.h>

using namespace std;

#ifndef SEABATTLE_INTELLECT_H
#define SEABATTLE_INTELLECT_H


class Intellect {
public:
    virtual void initialize(vector< vector<int> > &map) = 0;
    virtual void make_turn(vector<vector<int>> &map1, vector<vector<int>> &map) = 0;
protected:
    void clearing(vector< vector<int> > &map, int x, int y){
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if(map[x + i][y + j] == 4) continue;
                map[x + i][y + j] = 5;
            }
        }
    };
    void clearing2(vector< vector<int> > &map, int x, int y){
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if(map[x + i][y + j] == 2 || map[x + i][y + j] == 3) continue;
                map[x + i][y + j] = 1;
            }
        }
    };
    void kill_ship(pair<int, int> coords, vector< vector<int> > &map){
        map[coords.second][coords.first] = 3;
        clearing2(map, coords.second, coords.first);
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if(map[coords.second + i][coords.first + j] == 2){
                    kill_ship(make_pair(coords.first + j, coords.second + i), map);
                }
            }
        }
    }
};


#endif //SEABATTLE_INTELLECT_H
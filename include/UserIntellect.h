#include <bits/stdc++.h>
#include "Intellect.h"

using namespace std;


#ifndef SEABATTLE_USERINTELLECT_H
#define SEABATTLE_USERINTELLECT_H


class UserIntellect : public Intellect {
public:
    vector< vector<int> > user_map_for_user, computer_map_for_user;
    void initialize(vector< vector<int> > &map);
    int make_turn(vector<vector<int>> &map1, vector<vector<int>> &map, int size);
    int answer(pair<int, int> coords, vector<vector<int>> &map);
    UserIntellect();
};


#endif //SEABATTLE_USERINTELLECT_H

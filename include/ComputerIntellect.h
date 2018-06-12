#include "Intellect.h"
#ifndef SEABATTLE_COMPUTERINTELLECT_H
#define SEABATTLE_COMPUTERINTELLECT_H


class ComputerIntellect: Intellect {
public:
    vector< vector<int> > user_map_for_comp, computer_map_for_comp;
    void initialize(vector< vector<int> > &map);
    int make_turn(vector<vector<int>> &map1, vector<vector<int>> &map, int size);
    pair<int, int> generate_shoot_coordinates(vector<vector<int>> &map, int _size);
    ComputerIntellect();
    int answer(pair<int, int> coords, vector<vector<int>> &map);

protected:
    void generate_coordinates(pair<int, int> &cur_coordinate, pair<int, int> &last_coordinate, pair<int, int> &dir, int size, vector< vector<int> > &map);
};


#endif //SEABATTLE_COMPUTERINTELLECT_H

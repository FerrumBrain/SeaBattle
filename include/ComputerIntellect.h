#include "Intellect.h"
#ifndef SEABATTLE_COMPUTERINTELLECT_H
#define SEABATTLE_COMPUTERINTELLECT_H


class ComputerIntellect: Intellect {
public:
    vector< vector<int> > user_map_for_comp, computer_map_for_comp;
    void initialize(vector< vector<int> > &map);
    ComputerIntellect();

protected:
    void generate_coordinates(pair<int, int> &cur_coordinate, pair<int, int> &last_coordinate, pair<int, int> &dir, int size, vector< vector<int> > &map);
};


#endif //SEABATTLE_COMPUTERINTELLECT_H

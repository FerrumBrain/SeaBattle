#include <bits/stdc++.h>

using namespace std;

#ifndef SEABATTLE_INPUTCONTROLLER_H
#define SEABATTLE_INPUTCONTROLLER_H


class InputController {
public:
    void start(pair<int, int> &cur_coordinate, pair<int, int> &last_coordinate, const vector< vector<int> > &map, int size, int num, pair <int, pair <int, int> > &value_from_dist);
    pair<bool, pair <int, pair <int, int> >> is_valid(const vector< vector<int> > &map, pair<int, int> cur_coordinate, pair<int, int> last_coordinate, int size);

protected:
    pair <int, pair <int, int> > dist(const pair<int, int> &a, const pair<int, int> &b);
    bool is_coordinates_ok(char letter, int digit);
};


#endif //SEABATTLE_INPUTCONTROLLER_H

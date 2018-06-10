#include "../include/UserIntellect.h"
#include "../include/InputController.h"
#include "../include/PresentationController.h"

UserIntellect::UserIntellect() {
    user_map_for_user.resize(12, vector<int>(12, 0));
    computer_map_for_user.resize(12, vector<int>(12, 0));
}

void UserIntellect::initialize(vector< vector<int> > &map){
    vector< vector<int> > empty(12, vector<int>(12, 0));
    pair <int, int> cur_coordinate, last_coordinate;
    pair <int, pair <int, int> > value_from_dist;
    InputController inputController;
    PresentationController presentationController(0, 10);
    presentationController.print(map, empty);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            inputController.start(cur_coordinate, last_coordinate, map, i, j, value_from_dist);

            if(value_from_dist.second.first == 0){
                if(value_from_dist.second.second > 0){
                    for (int k = cur_coordinate.first; k <= last_coordinate.first; ++k) {
                        map[cur_coordinate.second][k] = 4;
                        clearing(map, cur_coordinate.second, k);
                    }
                } else {
                    for (int k = cur_coordinate.first; k >= last_coordinate.first; --k) {
                        map[cur_coordinate.second][k] = 4;
                        clearing(map, cur_coordinate.second, k);
                    }
                }
            } else {
                if(value_from_dist.second.second > 0){
                    for (int k = cur_coordinate.second; k <= last_coordinate.second; ++k) {
                        map[k][cur_coordinate.first] = 4;
                        clearing(map, k, cur_coordinate.first);
                    }
                } else {
                    for (int k = cur_coordinate.second; k >= last_coordinate.second; --k) {
                        map[k][cur_coordinate.first] = 4;
                        clearing(map, k, cur_coordinate.first);
                    }
                }
            }
            presentationController.print(map, empty);
        }
    }
}
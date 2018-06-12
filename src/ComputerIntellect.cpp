#include "../include/ComputerIntellect.h"
#include "../include/PresentationController.h"
#include "../include/InputController.h"

using namespace std;

ComputerIntellect::ComputerIntellect() {
    user_map_for_comp.resize(12, vector<int>(12, 0));
    computer_map_for_comp.resize(12, vector<int>(12, 0));
}

int ComputerIntellect::answer(pair<int, int> coords, vector<vector<int>> &map){
    PresentationController presentationController(0, 0);
    if(map[coords.second][coords.first] != 4){
        presentationController.shoot(0);
        map[coords.second][coords.first] = 1;
        return 0;
    }
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if(i == 0 && j == 0) continue;
            if(map[coords.second + i][coords.first + j] == 4){
                presentationController.shoot(1);
                map[coords.second][coords.first] = 2;
                return 1;
            }
        }
    }
    presentationController.shoot(2);
    kill_ship(coords, map);
    return 2;
}

void ComputerIntellect::generate_coordinates(pair<int, int> &cur_coordinate, pair<int, int> &last_coordinate,
                                             pair<int, int> &dir, int size, vector< vector<int> > &map) {

    InputController inputController;
    do {
        cur_coordinate.first = random() % 10 + 1;
        cur_coordinate.second = random() % 10 + 1;
        dir.first = random() % 2;
        dir.second = random() % 2;

        if(dir.first == 0){
            if(dir.second > 0){
                last_coordinate.first = cur_coordinate.first + 3 - size;
                last_coordinate.second = cur_coordinate.second;
            } else {
                last_coordinate.first = cur_coordinate.first - 3 + size;
                last_coordinate.second = cur_coordinate.second;
            }
        } else {
            if(dir.second > 0){
                last_coordinate.first = cur_coordinate.first;
                last_coordinate.second = cur_coordinate.second + 3 - size;
            } else {
                last_coordinate.first = cur_coordinate.first;
                last_coordinate.second = cur_coordinate.second - 3 + size;
            }
        }
    }while(!inputController.is_valid(map, cur_coordinate, last_coordinate, size).first);
}

void ComputerIntellect::initialize(vector< vector<int> > &map) {
        vector< vector<int> > empty(12, vector<int>(12, 0));
        pair <int, int> cur_coordinate, last_coordinate, dir;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                generate_coordinates(cur_coordinate, last_coordinate, dir, i, map);
                if(dir.first == 0){
                    if(dir.second > 0){
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
                    if (dir.second > 0) {
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
            }
        }
    }


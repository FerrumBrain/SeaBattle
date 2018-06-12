#include "../include/PresentationController.h"
#include "../include/InputController.h"

pair <int, pair <int, int> > InputController::dist(const pair<int, int> &a, const pair<int, int> &b){
    pair <int, pair <int, int> > ans;
    if(a.first == b.first){
        ans.first = abs(a.second - b.second) + 1;
        ans.second.first = 1;
        ans.second.second = a.second > b.second ? -1 : 1;
    } else if(a.second == b.second) {
        ans.first = abs(a.first - b.first) + 1;
        ans.second.first = 0;
        ans.second.second = a.first > b.first ? -1 : 1;
    } else {
        ans.first = ans.second.second = ans.second.first = -1;
    }
    return ans;
}

pair<bool, pair <int, pair <int, int> >> InputController::is_valid(const vector<vector<int> > &map, pair<int, int> cur_coordinate, pair<int, int> last_coordinate, int size) {
    bool is_right_coords;
    is_right_coords = !((cur_coordinate.first > 10 || cur_coordinate.first < 1 ||
                         cur_coordinate.second > 10 || cur_coordinate.second < 1) ||
                        (last_coordinate.first > 10 || last_coordinate.first < 1 ||
                         last_coordinate.second > 10 || last_coordinate.second < 1));
    pair <int, pair <int, int> > value_from_dist = dist(cur_coordinate, last_coordinate);
    is_right_coords = is_right_coords && (value_from_dist.first == 4 - size);

    if(is_right_coords && value_from_dist.second.first == 0){
        if(value_from_dist.second.second > 0){
            for (int k = cur_coordinate.first; k <= last_coordinate.first; ++k) {
                if(map[cur_coordinate.second][k] != 0) is_right_coords = false;
            }
        } else {
            for (int k = cur_coordinate.first; k >= last_coordinate.first; --k) {
                if(map[cur_coordinate.second][k] != 0) is_right_coords = false;
            }
        }
    } else if(is_right_coords && value_from_dist.second.first == 1){
        if(value_from_dist.second.second > 0){
            for (int k = cur_coordinate.second; k <= last_coordinate.second; ++k) {
                if(map[k][cur_coordinate.first] != 0) is_right_coords = false;
            }
        } else {
            for (int k = cur_coordinate.second; k >= last_coordinate.second; --k) {
                if(map[k][cur_coordinate.first] != 0) is_right_coords = false;
            }
        }
    } else {
        is_right_coords = false;
    }
    return make_pair(is_right_coords, value_from_dist);
}

bool InputController::is_coordinates_ok(char letter, int digit) {
    return letter >= 'A' && letter <= 'J' && digit > 0 && digit <= 10;
}

pair<int, int> InputController::get_coordinates(){
    int counter = 0, digit;
    char letter;
    do {
        if (counter >= 1) cout << "It is wrong coordinates. Try again." << endl;
        cin >> letter >> digit;
        counter++;
    } while(!is_coordinates_ok(letter, digit));
    return make_pair(letter - 'A' + 1, digit);
}

void InputController::start(pair<int, int> &cur_coordinate, pair<int, int> &last_coordinate, const vector<vector<int> > &map, int size, int num, pair <int, pair <int, int> > &value_from_dist) {
    PresentationController presentationController(0, 10);
    bool flag;
    int counter = 0, digit;
    char letter;
    do {
        if(counter >= 1) cout << "It is wrong coordinates. Try again." << endl;
        presentationController.ship_declaration_for_user(size, num, true);
        cin >> letter >> digit;
        if(!is_coordinates_ok(letter, digit)){
            flag = false;
            counter++;
            continue;
        }
        cur_coordinate.first = letter - 'A' + 1;
        cur_coordinate.second = digit;
        last_coordinate = cur_coordinate;
        if(size != 3){
            presentationController.ship_declaration_for_user(size, num, false);
            cin >> letter >> digit;
            if(!is_coordinates_ok(letter, digit)){
                flag = false;
                counter++;
                continue;
            }
            last_coordinate.first = letter - 'A' + 1;
            last_coordinate.second = digit;
        }
        counter++;
        flag = is_valid(map, cur_coordinate, last_coordinate, size).first;
        value_from_dist = is_valid(map, cur_coordinate, last_coordinate, size).second;
    } while(!flag);
}
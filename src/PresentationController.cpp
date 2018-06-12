#include "../include/PresentationController.h"

PresentationController::PresentationController(int ent, int spac) {
    enters = ent;
    spaces = spac;
}

void PresentationController::clear() {
    for (int i = 0; i < enters; ++i) {
        cout << endl;
    }
}

char PresentationController::symbol(int n) {
    if(n == 0 || n == 5)
        return '~';   //Empty and I can shoot there.
    if(n == 1)
        return '.';   //Empty and I can't shoot there.
    if(n == 2)
        return '*';   //Injured.
    if(n == 3)
        return 'X';   //Killed.
    if(n == 4)
        return '@';   //Your ship.
}

void PresentationController::ship_declaration_for_user(int size, int num, bool start_or_end) {
    string numbers[4] = {"one", "two", "three", "four"};
    string ordinal_numbers[4] = {"first", "second", "third", "fourth"};
    cout << "Enter ";
    if (size != 3) {
        if(start_or_end)
            cout << "start ";
        else
            cout << "end ";
    }
    cout << "coordinate of ";
    if (size != 0) {
        cout << ordinal_numbers[num] << " ";
    }
    cout << numbers[3 - size] << "-deck ship." << endl;
}

void PresentationController::shoot(int n){
   if(n == 0) cout << "Pass" << endl;
   if(n == 1) cout << "Injured";
   if(n == 2) cout << "Killed";
}

bool PresentationController::start_of_the_game(string str) {
    string ans, ans_copy;
    cout << str << endl;
    cin >> ans;
    for(char cur: ans){
       ans_copy += to_lower(cur);
    }
    if(ans_copy == "yes") return true;
    else return false;
}

void PresentationController::print(const vector< vector<int> > &map, const vector< vector<int> > &map1){
    clear();
    char cur;
    cout << "    " << "ABCDEFGHIJ" << "    ";
    for(int k = 0; k < spaces; k++){
        cout << " ";
    }
    cout << "ABCDEFGHIJ" << endl;

    for (int i = 1; i < map.size() - 1; ++i) {
        if(i < 10){
            cout << i << "   ";
        } else {
            cout << i << "  ";
        }
        for (int j = 1; j < map[i].size() - 1; ++j) {
            cur = symbol(map[i][j]);
            cout << cur;
        }

        for(int k = 0; k < spaces; k++){
            cout << " ";
        }

        if(i < 10){
            cout << i << "   ";
        } else {
            cout << i << "  ";
        }
        for (int j = 1; j < map1[i].size() - 1; ++j) {
            cur = symbol(map1[i][j]);
            cout << cur;
        }

        cout << endl;
    }
}

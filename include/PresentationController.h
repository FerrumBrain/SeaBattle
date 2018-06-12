#include <bits/stdc++.h>

using namespace std;

#ifndef SEABATTLE_PRESENTATIONCONTROLLER_H
#define SEABATTLE_PRESENTATIONCONTROLLER_H


class PresentationController {
public:
    int enters, spaces;
    void print(const vector< vector<int> > &map, const vector< vector<int> > &map1);
    void shoot(int n);
    void ship_declaration_for_user(int size, int num, bool start_or_end);
    bool start_of_the_game(string str);
    PresentationController(int ent, int spac);

protected:
    char symbol(int n);
    char to_lower(char in) {
        if(in <= 'Z' && in >= 'A')
            return in - ('Z' - 'z');
        return in;
    };
    void clear();
};


#endif //SEABATTLE_PRESENTATIONCONTROLLER_H

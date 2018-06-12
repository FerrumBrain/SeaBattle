#include <bits/stdc++.h>
#include "../include/UserIntellect.h"
#include "../include/ComputerIntellect.h"
#include "../include/PresentationController.h"

using namespace std;

int main() {
    srandom(time(NULL));

    vector< vector<int> > empty(12, vector<int>(12, 0));
    UserIntellect userIntellect;
    ComputerIntellect computerIntellect;
    PresentationController presentationController(30, 10);
    computerIntellect.initialize(computerIntellect.computer_map_for_comp);
    if(!presentationController.start_of_the_game("Do you want to get a random map?")){
        userIntellect.initialize(userIntellect.user_map_for_user);
        computerIntellect.initialize(computerIntellect.computer_map_for_comp);
        presentationController.print(userIntellect.user_map_for_user, computerIntellect.computer_map_for_comp);
    } else {
        int counter = 0;
        do {
            userIntellect.user_map_for_user = empty;
            computerIntellect.computer_map_for_comp = empty;
            computerIntellect.initialize(userIntellect.user_map_for_user);
            computerIntellect.initialize(computerIntellect.computer_map_for_comp);
            presentationController.print(userIntellect.user_map_for_user, computerIntellect.computer_map_for_comp);
            counter++;
        } while(!presentationController.start_of_the_game("This one?"));
    }

    //userIntellect.make_turn(userIntellect.computer_map_for_user, computerIntellect.computer_map_for_comp);
    //presentationController.print(userIntellect.computer_map_for_user, computerIntellect.computer_map_for_comp);

    return 0;
}
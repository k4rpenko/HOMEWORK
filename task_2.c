#include <superkarel.h>

void move_forward_path();
void move_backward_path();
void collect_beeper_if_present();
void move_straight();
void go_to_next_cell();
void return_to_previous_cell();

int main() {
    turn_on("task_2.kw");
    set_step_delay(10);

    while (1) {
        if (beepers_in_bag()) {
            move_backward_path();
            
            if (right_is_blocked() && left_is_blocked() && front_is_blocked()) {
                while (!facing_north()) {
                    turn_left();
                }
                break;
            }
        } 
        else {
            move_forward_path();
            if (right_is_blocked() && left_is_blocked() && front_is_blocked()) {
                turn_left();
                turn_left();
                step();
            }
        }
    }

    turn_off();
    return 0;
}

void collect_beeper_if_present() {
    if (beepers_present()) {
        pick_beeper();
    }
}


void move_straight() {
    while (right_is_blocked() && left_is_blocked() && front_is_clear()) {
        step();
    }
}


void move_forward_path() {
    move_straight();


    if (right_is_blocked() && left_is_clear() && front_is_blocked()) {
        turn_left();
        step();
        move_straight();
    }

    else if (right_is_clear() && left_is_blocked() && front_is_blocked()) {
        turn_left();
        turn_left();
        turn_left();
        step();
        move_straight();
    }

    collect_beeper_if_present();
}

void move_backward_path() {
    move_straight();


    if (right_is_blocked() && left_is_clear() && front_is_blocked()) {

        turn_left();
        turn_left();
        turn_left();
        step();
        move_straight();
    }

    else if (right_is_clear() && left_is_blocked() && front_is_blocked()) {
        turn_left();
        step();
        move_straight();
    }

    collect_beeper_if_present();
}

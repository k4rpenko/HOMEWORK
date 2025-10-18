#include <superkarel.h>

void fill_line();
bool check_doors();
void clear_line();

void move_forward();
void turn_north();
void turn_east();
void turn_south();
void turn_west();
void turnNinety();
void turnOneHundredEighty();
void turnTwoHundredAndEighty();

int main() {
    turn_on("task_7.kw");
    set_step_delay(100);

    fill_line();
    check_doors();
    clear_line();
    turn_east();

    turn_off();
    return 0;
}


void fill_line() {
    turn_east();
    put_beeper();
    while (front_is_clear()) {
        step();
        put_beeper();
    }
    turn_west();
    move_forward();
    turn_east();
}

bool check_doors() {
    while (true) {
        if (facing_west() && front_is_clear() && beepers_present()) {
            turnOneHundredEighty();
            step();
            pick_beeper();
            turnOneHundredEighty();
            break;
        }
        if (left_is_clear() && beepers_present()) {
            turn_left();
            step();
            if (!beepers_present()) {
                put_beeper();
            } else {
                continue;
            }
            while (left_is_blocked() && front_is_clear()) {
                step();
            }
        }
        if (left_is_clear()) {
            turn_left();
            step();
        }
        if (beepers_present() && front_is_clear() && not_facing_east()) {
            pick_beeper();
            step();
        }
        if (left_is_blocked() && front_is_clear()) {
            step();
            if (beepers_present() && facing_south() && front_is_blocked()) {
                turnOneHundredEighty();
                step();
                put_beeper();
                turnOneHundredEighty();
                step();
            }
        }
        if (front_is_blocked() && left_is_blocked() && right_is_blocked()) {
            turnOneHundredEighty();
            step();
        }
        if (left_is_blocked() && front_is_blocked()) {
            turnTwoHundredAndEighty();
            step();
        }
    }
    return true;
}

void clear_line() {
    turn_west();
    move_forward();
    turn_east();
    pick_beeper();
    while (front_is_clear()) {
        step();
        if (beepers_present()) {
            pick_beeper();
        }
    }
}

void move_forward() {
    while (front_is_clear()) {
        step();
    }
}

void turnNinety() { turn_left(); }
void turnOneHundredEighty() { turn_left(); turn_left(); }
void turnTwoHundredAndEighty() { turn_left(); turn_left(); turn_left(); }

void turn_north() {
    while (not_facing_north()) {
        turn_left();
    }
}

void turn_east() {
    while (not_facing_east()) {
        turn_left();
    }
}

void turn_south() {
    while (not_facing_south()) {
        turn_left();
    }
}

void turn_west() {
    while (not_facing_west()) {
        turn_left();
    }
}

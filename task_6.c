#include <superkarel.h>


void run_mile();
void turn_north();
void turn_east();
void turn_south();
void turn_west();
void turnNinety();
void turnOneHundredEighty();
void turnTwoHundredAndEighty();

int main() {
    turn_on("task_6.kw");

    set_step_delay(130);

    run_mile();

    turn_off();

    return 0;
}


void run_mile(){
    while(1){ 
        step(); 
		if (beepers_present()) {
			if (beepers_present()) {pick_beeper(); turn_north();}
			if (beepers_present()) {pick_beeper(); turn_west();}
			if (beepers_present()) {pick_beeper(); turn_south();}
			if (beepers_present()) {pick_beeper(); turn_east();}
			if (beepers_present()) {pick_beeper(); break;}
		}
    }
}



void turnNinety(){ turn_left(); }
void turnOneHundredEighty(){ turn_left(); turn_left(); }
void turnTwoHundredAndEighty(){ turn_left(); turn_left(); turn_left(); }

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
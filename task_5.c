#include <superkarel.h>


void run_mile();
void center();
void turnNinety();
void turnOneHundredEighty();
void turnTwoHundredAndEighty();

int main() {
    turn_on("task_5.kw");

    set_step_delay(130);
    while(not_facing_south()){turnNinety();}
    while(front_is_clear()){step();}
    turnTwoHundredAndEighty();
    while(front_is_clear()){step();}
    turnTwoHundredAndEighty();
    run_mile();

    turn_off();

    return 0;
}


void run_mile(){
    while(!beepers_present()){
        while(front_is_clear()){ if(!beepers_present()){put_beeper();}step();}
        turnTwoHundredAndEighty();
    }
    center();
    turnNinety();
    center();
    turnOneHundredEighty();
}

void center() {
	step();
	step();
	if (front_is_clear()) {
		center();
		step();
	} else {
		turn_left();
		turn_left();
		step();
	}
}

void turnNinety(){ turn_left(); }
void turnOneHundredEighty(){ turn_left(); turn_left(); }
void turnTwoHundredAndEighty(){ turn_left(); turn_left(); turn_left(); }
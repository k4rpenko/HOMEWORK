#include <superkarel.h>


void run_mile();
void run_bottom();
void finish();
void turnNinety();
void turnOneHundredEighty();
void turnTwoHundredAndEighty();

int main() {
    turn_on("task_1.kw");

    set_step_delay(50);

    
    if(left_is_clear() && front_is_blocked()){
        turnTwoHundredAndEighty();
        while(front_is_clear()){ step(); } 
        put_beeper();
        turnOneHundredEighty();
        while (right_is_blocked())
        {
            step();
        }
        turnTwoHundredAndEighty();
        step();
    }
    run_mile();

    turn_off();

    return 0;
}


void run_mile(){
    while (!beepers_in_bag())
    {
        if(right_is_clear()){
            run_bottom();
        }
        else if(left_is_clear() && front_is_blocked() && right_is_blocked()){
            turnNinety();
            while(front_is_clear()){ step(); 
                if (beepers_present()) {
                    pick_beeper(); 
                    finish(); 
                    pick_beeper(); 
                    turnTwoHundredAndEighty();
                    break;
                } 
            } 
            turnNinety();
            while (right_is_blocked() && front_is_clear())
            {
                step();
            }
            turnTwoHundredAndEighty();
            step();
        }
        else {step();}
    }
}

void run_bottom(){
    turnTwoHundredAndEighty();
    while(front_is_clear()){
        step();
        if (beepers_present()) {
            pick_beeper(); 
            turnOneHundredEighty();
            step();
            finish(); 
            pick_beeper(); 
            turnTwoHundredAndEighty();
            break;
        }
    }
    if(beepers_in_bag()){return;}
    turnOneHundredEighty();
    while (right_is_blocked())
    {
        step();
    }
    turnTwoHundredAndEighty();
    step();
}

void finish(){
    while (1)
    {
        if(not_facing_north()){
            turnOneHundredEighty();
        }
        while(left_is_blocked()){step();}
        turnNinety();
        step();
        while(left_is_blocked()){step();}
        turnNinety();
        while (front_is_clear())
        {
            step(); 
            if (beepers_present()) { break; }
        }
        if (beepers_present()) { break; }
    }  
}


void turnNinety(){ turn_left(); }
void turnOneHundredEighty(){ turn_left(); turn_left(); }
void turnTwoHundredAndEighty(){ turn_left(); turn_left(); turn_left(); }
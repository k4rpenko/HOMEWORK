#include <superkarel.h>


void run_mile();
void finish();
void GoDown();
void Repair();
void turnNinety();
void turnOneHundredEighty();
void turnTwoHundredAndEighty();

int main() {
    turn_on("task_4.kw");

    set_step_delay(130);

    Repair();
    turnTwoHundredAndEighty();
    step();
    run_mile();

    turn_off();

    return 0;
}


void run_mile(){
    while (1)
    {   
        if(front_is_blocked() && left_is_blocked())
        {   
            Repair(); 
            turnOneHundredEighty(); 
            while(front_is_clear()) { step(); } 
            turnNinety(); 
            break;
        }
        else if(left_is_clear()){
            turnOneHundredEighty();
            step();
            Repair();
            turnTwoHundredAndEighty();
            if(front_is_clear()){ step(); }
            else{turnTwoHundredAndEighty(); while(front_is_clear()){step();} turnNinety(); break;}
        }
        while (left_is_clear())
        {
            GoDown();
        }
        while (left_is_blocked())
        {
            //GoUp();
            turnTwoHundredAndEighty();
            if(front_is_clear()){
                while(left_is_blocked()){ if(front_is_blocked()){turnOneHundredEighty(); while(front_is_clear()) {step();} turnTwoHundredAndEighty(); break;}else{step();} }
                if(front_is_blocked() && left_is_blocked()){break;}
                turnNinety();
                while (front_is_clear() && left_is_clear())
                {
                    step();
                }
                while(front_is_clear() && left_is_blocked()){step();}
            }
        }
    }
}

void GoDown(){
    if(front_is_clear()){
        turnNinety();
        while(front_is_clear() ){step();}
        turnTwoHundredAndEighty();
        while(left_is_blocked() && front_is_clear()){step();}
    }
}


void Repair(){
    while(not_facing_south()) {turnNinety();}
    while(front_is_clear()){step();}
    turnOneHundredEighty();
    while(front_is_clear()){ if(!beepers_present()){put_beeper();}step();}
    if(!beepers_present()){put_beeper();}
}

void turnNinety(){ turn_left(); }
void turnOneHundredEighty(){ turn_left(); turn_left(); }
void turnTwoHundredAndEighty(){ turn_left(); turn_left(); turn_left(); }
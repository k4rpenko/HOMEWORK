#include <superkarel.h>


void run_mile();
void GetCoin();
void PutCoin();
void turnNinety();
void turnOneHundredEighty();
void turnTwoHundredAndEighty();

int main() {
    turn_on("task_3.kw");

    set_step_delay(50);

    run_mile();

    turn_off();

    return 0;
}


void run_mile(){
    while (1)
    {     
        GetCoin();
        PutCoin();
        turnNinety();
        if(front_is_blocked()){
            turnNinety();
            while(front_is_clear()){step();}
            turnNinety();
            while(front_is_clear()) {step();}
            turnNinety();
            while(front_is_clear()){step();}
            turnOneHundredEighty();
            break;
        }
        step();
        turnNinety();
    }
}

void GetCoin(){
    while(front_is_clear()){
        step();
        if(beepers_present()){pick_beeper();}
    }
    turnOneHundredEighty();
}

void PutCoin(){
    while(front_is_clear()){
        if(beepers_in_bag()){
            turnTwoHundredAndEighty();
            if(front_is_blocked()) {put_beeper(); turnNinety();}
            else {
                step();
                if(beepers_present()){turnOneHundredEighty(); step(); put_beeper(); turnTwoHundredAndEighty();}
                else {turnOneHundredEighty(); step(); turnTwoHundredAndEighty();}
            }
            step();
        }
        else { while(front_is_clear()) { step(); } }
    }
}


void turnNinety(){ turn_left(); }
void turnOneHundredEighty(){ turn_left(); turn_left(); }
void turnTwoHundredAndEighty(){ turn_left(); turn_left(); turn_left(); }
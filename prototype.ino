#include <Mouse.h>


screenRes[2] = {2240, 1400};



enum blink_t {
    BLINK = 0,
    BLINKBLINK,
    LONGBLINK
}


void setup() {

    Serial.begin(9600);
    Mouse.begin();

    // run calibration

    


    calibration();



    
}


void loop() {

    // Read from sensor
    V_horizontal = analogRead(A0);
    V_vertical = analogRead(A1);

    // Find current mouse position
        

    // Move mouse
    Mouse.move();


}



void calibration() {
    

    /* 
     *  Running cal.....START
     *  Look at the red dot, then blink twice.
     */

    Serial.print("Running calibration");

    int i;
    for (i = 0; i < 5; i++) {
        Serial.print('.');
        delay(200);
    }

    Serial.println("START");
    Serial.println("Look at the red dot, then blink twice.");


    // Calibrate using EOG data

    int cal[3][2] = {{0,0},{0,0},{0,0}};

    bool blinkblink = false;
    blinkblink = (checkblink() == BLINKBLINK) ? true : false;

    while (!blinkblink) {
        blinkblink = (checkblink() == BLINKBLINK) ? true : false;
    }

    readSignal();

}

int checkblink() {

}

int *readSignal() {
    vals[2] = {0,0};

    vals[0] = analogRead(A0);
    vals[1] = analogRead(A1);
    
    return vals;
}
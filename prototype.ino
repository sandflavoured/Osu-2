#include <Mouse.h>


//! set screen resolution here
int screenRes[2] = {2240, 1400};


// Global definitions

typedef enum {
    BLINK = 0,
    BLINKBLINK,
    LONGBLINK
} blink_t;

// ================== Setup ==================

void setup() {

    Serial.begin(9600);
    Mouse.begin();

    // run calibration
    //calibration();

    Mouse.move(90,90,0);

    
}

// ================== Loop ==================

void loop() {

    // // Read from sensor
    // V_horizontal = analogRead(A0);
    // V_vertical = analogRead(A1);

    // // Center mouse (every so often)
    // //centerMouse();

    // // Move mouse
    // xMove = 0;
    // yMove = 0;
    // Mouse.move(xMove, yMove);

    // if (clicked()) {
    //     Mouse.click();
    // }


}



// ================== Functions ==================

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
    delay(1000);
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


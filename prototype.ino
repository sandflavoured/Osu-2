
// Global definitions
int *sig_vol;

// ================== Setup ==================

void setup() {

    Serial.begin(9600);


    // run calibration
    //calibration();



    
}

// ================== Loop ==================

void loop() {

    sig_vol = readSignal();

    Serial.println();


}



// ================== Functions ==================

int map_a(float x, float in_min, float in_max, float out_min, float out_max) {

    return (int)((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);

}


int *readSignal() {
    int *vals;

    vals[0] = analogRead(A0);
    vals[1] = analogRead(A1);
    
    return vals;
}

void offset() {
    int *vals = readSignal();     // 0 to 1024

    float voltage[2] = {
        (float)vals[0] / 1024.0 * 5.0, 
        (float)vals[1] / 1024.0 * 5.0
    };       // 0 to 5


    // initialise offsets
    float offSetX_volt = 0;
    float offSetY_volt = 0;


    // Set X offset
    if (voltage[0] >= 5) {
        offSetX_volt = -4.0;
    }
    else if (voltage[0] <= 0) {
        offSetX_volt = 4.0;
    }
    else {
        offSetX_volt = 2.5 - voltage[0];
    }


    // Set Y offset
    if (voltage[1] >= 5) {
        offSetY_volt = -4.0;
    }
    else if (voltage[1] <= 0) {
        offSetY_volt = 4.0;
    }
    else {
        offSetY_volt = 2.5 - voltage[1];
    }


    int offSetX = map(offSetX_volt, 0, 5, 0, 255);

    analogWrite(10, offSetX_volt);
    analogWrite(10, offSetY_volt);



}
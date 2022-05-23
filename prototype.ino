
// Global definitions
int *sig_vol;

// ================== Setup ==================

void setup() {
    Serial.begin(115200);    
}

// ================== Loop ==================

void loop() {
    sig_vol = readSignal();

    Serial.println(sig_vol[0]);
    Serial.println(sig_vol[1]);
    
    if (digitalRead(2)) {
        offset();
    }
}



// ================== Functions ==================

float mapf(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


int *readSignal() {                                                 //? DONE
    int *vals;

    vals[0] = analogRead(A0);
    vals[1] = analogRead(A1);
    
    return vals;
}

void offset() {                                                     // TODO: Need to finish
    int *vals = readSignal();     // 0 to 1024

    float voltage[2] = {
        mapf((float)vals[0], 0, 1023, 0, 5), 
        mapf((float)vals[1], 0, 1023, 0, 5) 
    };       // 0 to 5


    // initialise offsets
    float offSetX_volt = 0; 
    float offSetY_volt = 0;


    // Set X offset
    if (voltage[0] >= 5) {
        offSetX_volt += 4.0;
    }
    else if (voltage[0] <= 0) {
        offSetX_volt -= 4.0;
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
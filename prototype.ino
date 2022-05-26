
// Global definitions
int *sig_vol = NULL;

// ================== Setup ==================

void setup() {
    Serial.begin(115200);    
    
    Serial.print("Offsetting..........");
    offset();
    Serial.println("Done")
}

// ================== Loop ==================

void loop() {
    sig_vol = readSignal();

    Serial.print(sig_vol[0]);
    Serial.print(',');
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

void offset() {                                                     // ! Need to check
    int *vals = readSignal();     // 0 to 1024

    float voltage[2] = {
        mapf((float)vals[0], 0.0, 1023.0, 0.0, 5.0), 
        mapf((float)vals[1], 0.0, 1023.0, 0.0, 5.0) 
    };       // 0 to 5


    // initialise offsets
    float offSetX_volt = 0; 
    float offSetY_volt = 0;

    while (voltage[0] > 2.51 || voltage[0] < 2.49 || voltage[1] > 2.51 || voltage[1] < 2.49) {
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
            offSetY_volt -= 2.5 - voltage[1];
        }


        int offSetX = mapf(offSetX_volt, 0.0, 5.0, 0.0, 255.0);
        int offSetY = mapf(offSetY_volt, 0.0, 5.0, 0.0, 255.0);

        analogWrite(10, offSetX);
        analogWrite(11, offSetY);

        // Serial.print("X Offset: ");
        // Serial.println(offSetX_volt);
        // Serial.print("Y Offset: ");
        // Serial.println(offSetY_volt);
        


        vals = readSignal();     // 0 to 1024

        voltage[0] = mapf((float)vals[0], 0.0, 1023.0, 0.0, 5.0);       
        voltage[1] = mapf((float)vals[1], 0.0, 1023.0, 0.0, 5.0);
    }
}
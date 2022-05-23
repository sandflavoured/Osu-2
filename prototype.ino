
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




int *readSignal() {
    vals[2] = {0,0};

    vals[0] = analogRead(A0);
    vals[1] = analogRead(A1);
    
    return vals;
}

void offset() {
    int vals[2] = readSignal();

    int offSetX = map();
    int offSetY = map();

    analogWrite(10, offSetX);
    analogWrite(10, offSetY);

}
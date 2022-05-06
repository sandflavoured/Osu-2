#include <Mouse.h>


int V_horizontal = 0;
int V_vertical = 0;


void setup() {

    Serial.begin(9600);
    Mouse.begin();


    
}


void loop() {

    // Read from sensor
    V_horizontal = analogRead(A0);
    V_vertical = analogRead(A1);

    // Find current mouse position
    

    // Move mouse
    Mouse.move();


}
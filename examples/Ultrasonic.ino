#include <Ultrasonic.h>

const unsigned int TRIG_PIN = 7;
const unsigned int ECHO_PIN = 6;
const unsigned int BAUD_RATE = 9600;

Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

void setup()
{
    Serial.begin(BAUD_RATE);
}

void loop()
{
    const unsigned long duration = ultrasonic.measure_duration();
    if (duration == 0) {
        Serial.println("Warning: We did not get a pulse from sensor."); 
    } else {
        Serial.print("Distance to nearest object: ");
        Serial.print(ultrasonic.microseconds_to_cm());
        Serial.println(" cm");
    }
    delay(1000);
}

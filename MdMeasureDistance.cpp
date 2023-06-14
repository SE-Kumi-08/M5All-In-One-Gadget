#include "MdMeasureDistance.h"
#include "DrUltraSonic.h"
#include "M5All-In-One-Gadget.h"
#include "AppControl.h"

DrUltraSonic drul = DrUltraSonic(ECHO_PIN, TRIG_PIN);


double MdMeasureDistance::getDistance(){
    double t;
    double distance;

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    t = drul.measureReturnTime();
    if(t > 0){
        distance = (340.0 / 1000000) * t * 0.5 * 100;
    }else{
        distance = 0;
    }
    return distance;
}

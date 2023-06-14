#include "DrUltraSonic.h"
#include "M5All-In-One-Gadget.h"
#include "AppControl.h"

DrUltraSonic::DrUltraSonic(int m_echo_pin, int m_trig_pin){
    pinMode(m_echo_pin, INPUT);
    pinMode(m_trig_pin, OUTPUT);
}

double DrUltraSonic::measureReturnTime(){
    double t;

    digitalWrite(m_trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_trig_pin, LOW);

    t = pulseIn(m_echo_pin, HIGH, 2000000);
   
    return t;
}
#include <Arduino.h>
#include <Moteur.h>

const int inApin_MOTD = 26, // INA2 
    inBpin_MOTD = 25,       // INB2 
    PWM_MOTD = 17,

    inApin_MOTG = 16,       // INA1 
    inBpin_MOTG = 15,       // INB1
    PWM_MOTG = 18,

    PWMD_Channel = 3,
    PWMG_Channel = 2;

Moteur moteur_droit(inApin_MOTD, inBpin_MOTD, PWM_MOTD, PWMD_Channel);
Moteur moteur_gauche(inApin_MOTG, inBpin_MOTG, PWM_MOTG, PWMG_Channel);

void setup() {
  Serial.begin(115200);

  moteur_droit.setVitesseMax(900);
  moteur_gauche.setVitesseMax(-900);
}

void loop() {
  
}

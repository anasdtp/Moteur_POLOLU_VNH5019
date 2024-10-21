#include "Moteur.h"

Moteur::Moteur(int inA_pin, int inB_pin, int pwm_pin, int pwm_channel){
    _inA_pin = inA_pin;
    _inB_pin = inB_pin;
    _pwm_pin = pwm_pin;
    _pwm_channel = pwm_channel;
    pinMode(_inA_pin, OUTPUT);
    pinMode(_inB_pin, OUTPUT);
    pinMode(_pwm_pin, OUTPUT);
    digitalWrite(_inA_pin, LOW);
    digitalWrite(_inB_pin, LOW);

    VITESSE_MAX = 1 << _resolution;

    ledcSetup(_pwm_channel, _freq_mot, _resolution);
    ledcAttachPin(_pwm_pin, _pwm_channel);
}

void Moteur::cmdMoteur(int vitesse){
    if(vitesse > VITESSE_MAX){
        vitesse = VITESSE_MAX;
    }else if(vitesse < -VITESSE_MAX){
        vitesse = -VITESSE_MAX;
    }
    
    setRotation(vitesse >= 0);

    setPwm(abs(vitesse));
}

void Moteur::setRotation(bool rotation){
    if(rotation){//Avancer
        digitalWrite(_inA_pin, HIGH);
        digitalWrite(_inB_pin, LOW);
    }else{//Reculer
        digitalWrite(_inA_pin, LOW);
        digitalWrite(_inB_pin, HIGH);
    }
}

void Moteur::setPwm(int pwm){
    ledcWrite(_pwm_channel, (pwm));
}

void Moteur::arretBrutal()
{
    digitalWrite(_inA_pin, HIGH);
    digitalWrite(_inB_pin, HIGH);
    setPwm(0);
}
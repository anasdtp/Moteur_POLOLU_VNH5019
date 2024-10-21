#include <Arduino.h>

class Moteur
{
private:
    // Les pins pour le sens de rotation du moteur :
    int _inA_pin, _inB_pin;
    // Le pin pour le signal PWM :
    int _pwm_pin;
    //Le canal PWM pour le signal PWM, doit etre différent pour chaque moteur :
    int _pwm_channel;
    //Vitesse max du moteur
    int VITESSE_MAX;
    // La fréquence du signal PWM et la résolution du signal PWM. 
    //La resolution veut dire que la vitesse max est 2^11 = 2048 :
    const int _freq_mot = 20000, _resolution = 11;

    //Si la rotation est vraie, le moteur tourne dans un sens, sinon il tourne dans l'autre sens :
    void setRotation(bool rotation);
    //Cette fonction permet de créer le signal PWM pour commander le moteur :
    void setPwm(int pwm);
public:
    //Initialiser les pins pour le moteur :
    Moteur(int inA_pin, int inB_pin, int pwm_pin, int pwm_channel);

    //Commander le moteur avec une vitesse entre -2048 et 2048
    void cmdMoteur(int vitesse);

    //Arreter le moteur brutalement
    void arretBrutal();
    void setVitesseMax(int vitesseMax){
        VITESSE_MAX = abs(vitesseMax);
    }
};



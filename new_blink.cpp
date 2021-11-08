/**
 * @file blink.cpp
 * @author João Marcos Airton
 * @brief Desenvolvimento das class new_blink.h em cpp
 * @version 0.1
 * @date 2021-11-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "new_blink.h"
#include "Arduino.h"

blink_h * blink_h::_led = 0; // definindo nossa instância = 0

blink_h::blink_h() // chamando a função para criação da instãncia;
{
    
}

void blink_h::begin(int pin) // Definindo o pino como saída
{
    _pin = pin;
    pinMode(_pin, OUTPUT);
}


void blink_h::start() // função que inicia o blink
{   
    if((millis() - intervalo) >= 500)  // utilizamos essa forma para comparar o tempo, pois dessa forma o codigo continuará rolando
                                        // e poderá mudar seu estado, não travando o codigo como um delay
    {
      digitalWrite(_pin,  HIGH); 
    }
    if ((millis() - intervalo) <3000) // mesma situação para desligar
    {
      digitalWrite(_pin, LOW);
    }
    if ((millis() - intervalo) >=3500) // após passar esse tempo ele irá marcar novamente o tempo de inicio.
    {
      intervalo = millis();
    }
     
}

void blink_h::stop() // função para desligar o blink;

{
    digitalWrite(_pin, LOW);
}



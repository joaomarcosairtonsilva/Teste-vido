/**
 * @file blink.h
 * @author  João Marcos Airton
 * @brief   

    Desenvolvimento de uma class para c++, onde esa class  terá 3 funções,
    onde a função blink define os pino de saída para nossso led. A função
    start inicia o pisca do nosso led, respeitando um tempo de 500 ms do 
    led ligado e  3000 do led desligado. E por ultimo a função stop ela
    interrompe o pisca do led.
 
 
 
 
 * @version 0.1
 * @date 2021-11-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __BLINK__H__
#define __BLINK__H__

class blink_h // criando a classe
{
private:

        blink_h(); // construtor
        static blink_h * _led; // criando a instância
    
        unsigned long intervalo; // varial para usar para controle de tempo
        int _pin; // varial para definir a porta de saída
        
public:
    static blink_h * instance(void) // criando a forma estatica usando o padrão singleton
    {
        if (!_led)
        {
            _led = new blink_h();
        }
    }
    
    void begin(int pin); // função define o pino de saída 
    void start(); // função que inicia o blink
    void stop(); // função que desliga o blink
    
};


#endif  //!__BLINK__H__
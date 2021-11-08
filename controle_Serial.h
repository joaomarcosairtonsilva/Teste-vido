/**
 * @file controle_Serial.h
 * @author your name (you@domain.com)
 * @brief 
 
    Desenvolvimento de uma class para c++, onde esa class  terá 3 funções,
    onde a ctrl_serial, inicia a serial, a função recebe pacote irá armazenar 
    a mensgem recebida e tratar esses dados, a função le pacote irá verificar 
    se essa ativadade já está sendo realizada, e por ultmimo a função envia 
    pacote irános enviar uma resposta pela serial sobre o que irá acontecer,
    se irá realizar ou não a funçao.
 
 
 * @version 0.1
 * @date 2021-11-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Arduino.h"
#ifndef __CONTROLE_SERIAL__H__
#define __CONTROLE_SERIAL__H__

class ctrl_Serial // criando a classe
{
private:
        String pacote; // criando a string que recebe a mensagem
        ctrl_Serial(); // construtor
        static ctrl_Serial* _serial; // criando a instância

public:
        static ctrl_Serial* instance(void) // criando a forma estatica usando o padrão singleton
        {
            if(!_serial)        
            {
            _serial = new ctrl_Serial();
            }
        }
    
        int recebe_pacote(); // função que recebe mensagem via seril
        int le_pacote(int sinal, int Antsinal); // função que compara se a funcão está sendo realizada
        void envia_men(int ind, int sinal); // função que envia a resposta para o usario
    
    
};


#endif  //!__CONTROLE_SERIAL__H__
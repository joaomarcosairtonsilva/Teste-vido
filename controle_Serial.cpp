/**
 * @file controle_Serial.cpp
 * @author João Marcos Airton
 * @brief Desenvolvimento das class controle_Serial em cpp
 * @version 0.1
 * @date 2021-11-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include"controle_Serial.h"
#include"Arduino.h"

ctrl_Serial* ctrl_Serial::_serial = 0; // definindo nossa instância = 0

ctrl_Serial::ctrl_Serial() // chamando a função para criação da instãncia;
{
        Serial.begin(9600); // Inciando a serial
        Serial.println("iniciando os trabalhos \n"); // Informando ao usuário que iniciou o programa 
}

int ctrl_Serial::recebe_pacote() // função que recebe a mensagem via serial
{
        if (Serial.available() > 0 ) // se recebeu alguma mensagem irá guardar a mensagem
        {
            pacote = Serial.readStringUntil('\n'); // guardando a mensagem
            pacote.replace(",", ""); // aqui retiramos os pontos, virgulas e espaço da mensagem
            pacote.replace(" ", "");
            pacote.replace(".", "");

        if(pacote.equals("0x800x010xFF")) // confirimos se a mensagem foi o codigo para ligar o blink
        {
            Serial.println("\n pacote recebido");
            return(0); // retorna um valor para a comparação
            
        }
        if(pacote.equals("0x800x020xFF")) // confirimos se a mensagem foi o codigo para desligar o blink
        {
            Serial.println("\n pacote recebido");
            return(1); // retorna um valor para a comparação
        }
        else
        {
            Serial.println("\n Comando invalido"); // Caso o usuário envie uma mensagem errada ele avisa que o comando é invalido
        }
        }
        return(2); // caso o usario não envie mensagem ele retorna 2 para fazer a comparaçãp
}


int ctrl_Serial::le_pacote(int sinal, int Antsinal) // Verificação se está ocorrendo a atividade solicitada 
{
    
        if(sinal != Antsinal) // Se o sinal enviado e o sinal antigo são diferentes é que aconteceu uma mudança da atividade solicitada.
        {
            return 0; // valor para comparação
        }
    
        else if (sinal == Antsinal) // as atividades são iguais 
        {
            return 1; // valor para comparação
        }
} 

void ctrl_Serial::envia_men(int ind, int sinal) // envia mensagem na serial
{
        if(ind == 0 && sinal == 0)
        {
            Serial.println("\n Iniciando o blink ");
            Serial.println("\n 0x81, 0x01, 0x01, 0xFF \n ");
        }
        else if(ind == 0 && sinal == 1)
        {
            Serial.println("\n Essa função já está sendo realizada");
            Serial.println("\n 0x81, 0x01, 0x02, 0xFF \n ");
        }
        else if(ind == 1 && sinal == 0)
        {
            Serial.println("\n Desligando o blink");
            Serial.println("\n 0x81, 0x02, 0x01, 0xFF \n ");
        }
        else if(ind == 1 && sinal == 1)
        {
            Serial.println("\n Essa função já está sendo realizada");
            Serial.println("\n 0x81, 0x02, 0x02, 0xFF \n ");
        }
}

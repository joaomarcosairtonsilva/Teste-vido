/**
 *
 * @author João Marcos Airton
 ** @brief   

    Aqui está o escopo principal da função, onde iniciamos o programa
    e esperamos um sinal do usario para realizar a atividade, utilizando
    conceitos de classes e o metodo padrão singleton para as bibliotecas
    criadas. 

 * @version 0.1
 * @date 2021-11-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <Arduino.h>
#include <new_blink.h>
#include <controle_Serial.h>

int sinal, antsinal =1, ind; /* Aqui estamos definindo nossas variaveis para as compações e tomadas de decisões.
                                Definimos o antsinal = 1 pois o sinal está desligado, caso solicite para desligar
                                ele informará o erro */
void setup() 
{
  
      blink_h::instance(); // Criando as instancias para a class blink
      ctrl_Serial::instance(); // Criando as instancias para a class ctrl_Serial
      blink_h::instance()->begin(13); // Chamando a função para definir o pino 13 como saída.
   
}

void loop() 
{     
      sinal    = ctrl_Serial::instance()->recebe_pacote(); // Recebendo o sinal que indica a mensagem na serial
      ind = ctrl_Serial::instance()->le_pacote(sinal,antsinal); // Comparando o sinal recebido com o sinal antigo
  
      if(ind == 0 && sinal != 2) /* se ind = 0 sinal que aconteceu mudança do estado serial
                                    primeira tomada de decisão para envio de mensagem e salvar o sinal antigo*/
      {
         ctrl_Serial::instance()->envia_men(sinal,ind); // chama a funçao para enviar mensagem na serial
         antsinal = sinal; // guarda o sinal atual no antigo para uma futura compação
      }
      
      else if(sinal == 2) // se sinal = 2 o usario não enviou nada e então devemos preservar o sinal antigo
      {
        sinal = antsinal;
      }
      
      if (ind == 0 && sinal == 0  && antsinal == 0 ) /* Aqui ind indica que aconteceu mudança, o sinal envia qual foi a mensagem e o a
                                                      e o antigo sinal está de acordo com o comando */
      {
          blink_h::instance()->start(); // chama a função para ligar o sistema
      }
      
      if(ind == 0 && sinal ==1 && antsinal == 1) //Aqui esse if tem a mesma função de cima, porém agora vamos desligar o sistema
      {
         blink_h::instance()->stop();  // chama a função para desligar o sistema
      }

      if(ind == 1) // Aqui indica que indicamos um comando porém esse comando já está acionado
      {
        ctrl_Serial::instance()->envia_men(sinal,ind); // indica que a função não será realizada
      }
   
 }
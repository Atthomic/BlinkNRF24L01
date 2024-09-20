
/*******************************************************************************************
Este é um projeto de "Hello World!" para testar os módulos de radiofrequencia NRF24L01
Baseado no próprios exemplos da biblioteca RF24 e o vídeo 
https://youtu.be/X7qWHlHh7DY?si=YLyKlsaAy6NsI5Ig do 
Prof. Cleber Borges do canal FunBots: https://www.youtube.com/@FunBots
******************************************************************************************

/******************************************************************************************
// Aqui começa o código para o Emissor que deve ser carregado apenas no Arduino Emissor
// ******************************************************************************************/

#include <RF24.h>

RF24 radio(7,8); // CE e CSN no arduino UNO - Arduino UNO atua como Emissor da mensagem apenas
const byte address[6] ="00001"; // ambos devem ter configurado o mesmo enderço para estabelecerem a comunicação


void setup() {
  radio.begin(); //Iniciamos comunicação via Radio
  radio.openWritingPipe(address); //Abrimos o Pipe de comunicação para escrita
  radio.setPALevel(RF24_PA_MIN); 
	/*Definimos o PA Level low para prevenir possíveis problmas de corrente
  dado que estes testes sáo realizados geralmente numa bancada com os rádios bem próximos.*/
  radio.stopListening(); // Este módulo apenas realizará o envio do Hello World, por tanto não precisa "escutar"
}
  

void loop() {
  const char text[] = "Hello World!"; // Criamos uma constante tipo texto para armazenar a mensagem que ser� enviada
  radio.write(&text, sizeof(text)); // Envia a mensagem de 
  delay(2000); // é um simples teste, então sim. Delay mesmo para simplificar.
}
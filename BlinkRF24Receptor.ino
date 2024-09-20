/*******************************************************************************************
Este é um projeto de "Hello World!" para testar os módulos de radiofrequencia NRF24L01
Baseado no próprios exemplos da biblioteca RF24 e o vídeo 
https://youtu.be/X7qWHlHh7DY?si=YLyKlsaAy6NsI5Ig do 
Prof. Cleber Borges do canal FunBots: https://www.youtube.com/@FunBots
******************************************************************************************

/******************************************************************************************
// Aqui começa o código para o Receptor que deve ser carregado apenas no Arduino receptor
// ******************************************************************************************/

#include <RF24.h>

RF24 radio(46,45); // CE e CSN no arduno MEGA - Aduino Mega atua como receptor

const byte address[6] ="00001"; // ambos devem ter configurado o mesmo endere�o para estabelecerem a comunica��o

void setup() {
  Serial.begin(9600); // Iniciamos o Serial para podermos visualizar a mensagem
  Serial.println("Iniciando..."); 


  radio.begin(); //Iniciamos comunica��o via Radio
  radio.openReadingPipe(0, address); //Abrimos o Pipe de comunica��o para leitura
  radio.setPALevel(RF24_PA_MIN);
	/*Definimos o PA Level low para prevenir poss�veis problmas de corrente
  dado que estes testes s�o realizados geralmente numa bancada com os r�dios bem pr�ximos.*/
  radio.startListening(); // Este m�dulo apenas realizar� o recebimento da mensagem, por tanto n�o precisa "escutar"
}


void loop() {
  if(radio.available()){ //Verificamos que quando a mensagem tenha sido recebida, ele da True e executa o c�digo a seguir
    char text[32] = ""; // instancia uma vari�vel em branco
    radio.read(&text, sizeof(text)); //recebe a mensagem via radio e armazena na vari�vel text
    Serial.println(text);// imprime a vari�vel no terminal para podermos visualizar e validar que a comunica��o est� funcionando.
  }
}



# Projeto de Blink para os módulos de radio frequencia NRF24L01. 
---
## O Objetivo era criar um blink bem simples para testar o lote de transmistores recebidos 

**Melhorias:** 
- [ ] Na sequencia do projeto, para melhoria seria possível acrescentar um verificador de status de resposta do transmissor (disponível via biblioteca RF24) pois o Blink funciona muito bem para validar que o módulo funciona, mas se ele não funcionar, não traz muita informação.

**Próximos passos no projeto:**
- [ ] Acrescentar tambem o mesmo procedimento para utilizando um **Attiny85** como emissor e o Arduino UNO ainda como receptor. Este é um passo na frente com o objetivo de fazer uma rede de sensores com attiny85 que enviam seus dados para um modulo central (Arduino ou ESP) que coleta os dados e os armazena. Realizar esta conexão com Attiny85 apresenta desafios por ter 5 a 6 portas disponíveis (6 se não utilizarmos o reset) e 5 seriam utilizadas na comunicação com o **módulo NRF24l01**.


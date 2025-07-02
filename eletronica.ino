#include<Servo.h>
Servo cancela;
int dist = 100;
int tempo = 0;
const int trig = 4;
const int echo = 3;

void setup()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(6, OUTPUT);
  cancela.attach(7);
}  

void loop()
{
  //manda um pulso que gera uma onda sonora
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  //armazena o tempo que a onda demorou para ir e voltar
  tempo = pulseIn(echo,HIGH);
  //converte o tempo de retorno da onda para distância em centímetros
  //com base na velocidade do som 
  dist = 0.01723 * tempo;
  
  //enquanto a distancia for menor que 5cm (adaptado pro tamanho do projeto)
  if(dist < 5){
    //a cancela abre em 90 graus
    cancela.write(90);
    //o led verde liga, indicando que a cancela irá abrir
    digitalWrite(13, HIGH);
    
    //o buzzer emite um som de alerta para a passagem
    tone(6, 200);
    //espera dois segundos para a passagem
    delay(2000);
    //desliga o led verde, indicando que a passagem foi feita
    digitalWrite(13, LOW);
  }
  
  //caso contrário
  else{
    //a cancela se fecha/permanece fechada
    cancela.write(0);
    //o led vermelho continua ligado
    digitalWrite(12, HIGH);
    //não há emissão de barulho
    noTone(6);
    delay(5);
    digitalWrite(12, LOW);
  }
  
}  
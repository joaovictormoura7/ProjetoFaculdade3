﻿//importação de tempo
unsigned long time;
int analogico = A0;
//Entradas da placa
int entrada_Luz = A0;


//variaveis do cronometro
int i = 0;
int f = 0;
int tempo = 0;
int tempoLuz = 0;


//Variaveis de iluminação
int luz = 0;
int luzI = 1; //750
int luzF = 300; //920


int topo = 0;
int num1 = -1;
int num2 = -1;
int soma = -1;


int final[4] = { -1, -1, -1, -1};
int zero[4] = {0, 0, 0, 0};
int um[4] = {0, 0, 0, 1};
int dois[4] = {0, 0, 1, 0};
int tres[4] = {0, 0, 1, 1};
int quatro[4] = {0, 1, 0, 0};
int cinco[4] = {0, 1, 0, 1};
int seis[4] = {0, 1, 1, 0};
int sete[4] = {0, 1, 1, 1};
int oito[4] = {1, 0, 0, 0};
int nove[4] = {1, 0, 0, 1};




int comparacao(int v1[], int v2[]) {
  int aux = 0;
  for (int i = 0; i < 4; i++) {
    if (v1[i] == v2[i]) {
      aux++;
    }
  }
  if (aux == 4) {
    return 0;
  } else {
    return -1;
  }
}




int separacao() {
  if (comparacao(final, zero) == 0) {
    return 0;
  }
  else if (comparacao(final, um) == 0) {
    return 1;
  }
  else if (comparacao(final, dois) == 0) {
    return 2;
  }
  else if (comparacao(final, tres) == 0) {
    return 3;
  }
  else if (comparacao(final, quatro) == 0) {
    return 4;
  }
  else if (comparacao(final, cinco) == 0) {
    return 5;
  }
  else if (comparacao(final, seis) == 0) {
    return 6;
  }
  else if (comparacao(final, sete) == 0) {
    return 7;
  }
  else if (comparacao(final, oito) == 0) {
    return 8;
  }
  else if (comparacao(final, nove) == 0) {
    return 9;
  }
  else {
    return -1;
  }
}




void setup() {
  Serial.begin(9600);
  pinMode(entrada_Luz, INPUT);
  pinMode(12, OUTPUT);
}




void loop() {
  int time = millis();


  luz = analogRead(analogico);
  if (luz <= luzF) { //Luz apagada
    i = time;
    tempoLuz = f - tempo;




    if (tempoLuz > 10 && tempoLuz <= 2500) {
      Serial.println("Recebido: 0");
      final[topo] = 0;
      topo++;


    } else if (tempoLuz > 2500 && tempoLuz <= 5000) {
      Serial.println("Recebido: 1");
      final[topo] = 1;
      topo++;
    }




    f = 0;
    tempo = 0;
  } else { //Luz acessa
    f = time;
    tempo = i;




  }
  //Serial.println(topo);
  if (topo > 3) {




    if (num1 != -1 && num2 == -1) {
      num2 = separacao();
      Serial.print("numero detectado: ");


      Serial.println(num2);
      Serial.println("-----------------------");
    }
    else if (num1 == -1 &&  num2 == -1) {
      num1 = separacao();
      Serial.print("numero detectado: ");


      Serial.println(num1);
      Serial.println("-----------------------");
    }




    if (num1 != -1 && num2 != -1) {
      Serial.print("Soma: ");
      soma = num1 + num2;
      Serial.println(soma);
      Serial.println("-----------------------");
      num1 = -1;
      num2 = -1;
      soma = -1;
    }
    topo = 0;


  }








}

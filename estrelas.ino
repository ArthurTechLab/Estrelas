int leds[] = {3, 5, 6, 9, 10, 11};
int quantidade = 6;

int ledsAM[] = {3, 9};
int ledsAZ[] = {5, 10};
int ledsVA[] = {6};
int ledsVD[] = {11};

int botao = 2;

int modo = 0;

bool transicao = false;
int quantidadeVA = 1; 
int quantidadeAM = 2;
int quantidadeAZ = 2;
int quantidadeVD = 1;
float tempo = 0;

bool pwm = true;



void setup() {
  
  for (int i = 0; i < quantidade; i++) {
    pinMode(leds[i], OUTPUT);
  }

  for (int i = 0; i < quantidadeAM; i++) {
    pinMode(ledsAM[i], OUTPUT);
  }

  for (int i = 0; i < quantidadeAZ; i++) {
    pinMode(ledsAZ[i], OUTPUT);
  }

  for (int i = 0; i < quantidadeVA; i++) {
    pinMode(ledsVA[i], OUTPUT);
  }

  for (int i = 0; i < quantidadeVD; i++) {
    pinMode(ledsVD[i], OUTPUT);
  }
  pinMode(ledsVD, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  int botaos = digitalRead(botao);
  tempo += 0.05;
if(modo == 0){
     for (int i = 0; i < quantidade; i++) {
      float fase = tempo + i;
      float brilho = (sin(fase) + 1.0) * 127.5;
      analogWrite(leds[i], brilho);
    }
}
 

    if (botaos == LOW && transicao == false) {
      modo++;
      transicao = true;
        }

  if (modo == 1) {
        for (int i = 0; i < quantidadeAM; i++) {
      float fase = tempo + i;
      float brilho = (sin(fase) + 1.0) * 127.5;
      analogWrite(ledsAM[i], brilho);
    }

  for (int i = 0; i < quantidadeAZ; i++) {
    analogWrite(ledsAZ[i], 0);
  }

  for (int i = 0; i < quantidadeVA; i++) {
    analogWrite(ledsVA[i], 0);
  }

  for (int i = 0; i < quantidadeVD; i++) {
    analogWrite(ledsVD[i], 0);
  }

  }


if(botaos == HIGH && modo == 1){
  transicao = false; 
}

    if(modo == 2){
      for (int i = 0; i < quantidadeAZ; i++) {
      float fase = tempo + i;
      float brilho = (sin(fase) + 1.0) * 127.5;
      analogWrite(ledsAZ[i], brilho);
    }
      
      for(int i = 0; i < quantidadeAM; i++){
        analogWrite(ledsAM[i], 0);

      }


    }
    
    if(botaos == HIGH){
      transicao = false;
    }



  
    if(modo == 3){

      for (int i = 0; i < quantidadeVA; i++) {
      float fase = tempo + i;
      float brilho = (sin(fase) + 1.0) * 127.5;
      analogWrite(ledsVA[i], brilho);
    }

      for(int i = 0; i < quantidadeAZ; i++){
        analogWrite(ledsAZ[i], 0);
      }
      
      for(int i = 0; i < quantidadeAM; i++){
        analogWrite(ledsAM[i], 0);

      }
    }

    if(modo == 4){
      for (int i = 0; i < quantidadeVD; i++) {
      float fase = tempo + i;
      float brilho = (sin(fase) + 1.0) * 127.5;
      analogWrite(ledsVD[i], brilho);
    }

            for(int i = 0; i < quantidadeVA; i++){
        analogWrite(ledsVA[i], 0);

      }


      for(int i = 0; i < quantidadeAZ; i++){
        analogWrite(ledsAZ[i], 0);
      }
      
      for(int i = 0; i < quantidadeAM; i++){
        analogWrite(ledsAM[i], 0);

      }
    }

  if(modo > 4){
    modo = 0;
  }

  delay(20);
}
 
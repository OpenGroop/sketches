/*
  ctrl4 v1.0
  MCU: Arduino Micro 5V

  READS A 5 BYTE SERIAL INPUT VALUE. BYTE VALUES ARE 0 AND 1.
  
  10101
  ||__|- OUTPUTS AFFECTED (1's DENOTE OUTPUT TO PROGRAM, BY INDEX)
  +----- STATE OF OUTPUT  (0=LOW, 1=HIGH)

  THE ABOVE EXAMPLE OUTPUTS HIGH ON OUTPUT 2 AND 4.
*/

  int c1_pin = 2;
  int c2_pin = 12;
  int c3_pin;
  int c4_pin;

  
  int c_states[4] = {0,0,0,0};

  int counter = 0;
  char buf[6];
  
  
void setup() {
  Serial.begin(9600); 
  
  pinMode(c1_pin, OUTPUT);
  pinMode(c2_pin, OUTPUT);

}

void loop() {
  
  if (Serial.available() > 0) {
    buf[counter] = Serial.read();
    Serial.print(buf[counter]);
    counter++;
  }

  if (counter == 5) {
    buf[counter] = NULL;
    Serial.println(buf[counter]);
    Serial.println("buffer:" + String(sizeof(buf)));
    counter = 0;
    int state;
    for (int i = 1; i < sizeof(buf); i++) {
      

      if(buf[0] == 48) {state = LOW;}
      if(buf[0] == 49) {state = HIGH;}
      
      if (buf[i] == 49) {
        Serial.println("output:" + String(i) + " state:" + String(state));
        c_states[i-1] = state;
      }
    }

    for (int i = 0; i < 4; i++) {
      Serial.print(c_states[i]);
    }
    Serial.println();
    Serial.println("c_states:" + String(sizeof(c_states)) );
    
    digitalWrite(c1_pin, c_states[0]);
    digitalWrite(c2_pin, c_states[1]);
  }
  
}

#define CLOCK 9
#define CLOCK_RATE 100
#define RTS 7
#define CTS 8
#define DADOS 13
#define BUFFER_SIZE 64

char buffer[BUFFER_SIZE];
int buffer_begin = 0;
int buffer_end = 0;

void reset() {
  digitalWrite(DADOS, LOW);
  digitalWrite(RTS, LOW);
  digitalWrite(CLOCK, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(CLOCK, OUTPUT);
  pinMode(RTS, OUTPUT);
  pinMode(CTS, INPUT);
  pinMode(DADOS, OUTPUT);
  reset();
}

void loop() {
  if (Serial.available() > 0) {
    buffer[buffer_begin] = Serial.read();
    buffer_begin++;
    //Serial.print(buffer[buffer_begin - 1]);
    if (buffer[buffer_begin - 1] != '\n') {
      //Serial.println("");
    }
  }
  
  digitalWrite(RTS, HIGH);

  delay(500);

  if (digitalRead(CTS) == HIGH) {
    while (buffer_end < buffer_begin) {
      char dado = buffer[buffer_end];

      send_char(dado);
      Serial.write('|');

      buffer_end++;
    }
  }
}

void send_char(char dado) {
  for (int i = 7; i >= 0; i--) {
    int signal = bitRead(dado, i);

    if (signal == 1) {
      digitalWrite(DADOS, HIGH);
      Serial.write('1');
    } else {
      digitalWrite(DADOS, LOW);
      Serial.write('0');
    }
  }
}
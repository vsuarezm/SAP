//out

int num;
void setup() {
  DDRA = B11111111;
}

void loop() {
  num = PINK; //20

  byte dNum = (num / 10) << 4;
  byte uNum = num % 10;
  PORTA = dNum | uNum;
}

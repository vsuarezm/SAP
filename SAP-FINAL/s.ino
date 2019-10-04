/*
  LDA -> 0000 ADD -> 1010 SUB -> 1100 OUT -> 0010 HALT -> 1000 RAIZ3 -> 0101 GOTO -> 0001 RETURN -> 1011 MUL -> 0111 DIV -> 0110 MOVE -> 0100 MOD -> 1001
*/

#define add 52
#define sub 51
#define mul 11
#define dib 12
#define inv 13 //// invvvvvvvv
#define out 50
#define halt 10
#define lda 53
#define got 37
#define ret 36

//acumc
#define ec 0
#define lc 38


#define cp 49
#define ep 44
#define lm 49
#define er 15
#define li 48
#define ei 14
#define la 47
#define ea 43
#define suma 21
#define resta 20
#define multi 19
#define divid 18
#define eu 42
#define lb 46
#define lo 45

int pc, possition, divisor, valor, value, cont;

void setup() {
  pinMode(add, INPUT);
  pinMode(sub, INPUT);
  pinMode(mul, INPUT);
  pinMode(dib, INPUT);
  pinMode(inv, INPUT);
  pinMode(out, INPUT);
  pinMode(halt, INPUT);
  pinMode(lda, INPUT);
  pinMode(got, INPUT);
  pinMode(ret, INPUT);

  pinMode(lc, OUTPUT);
  pinMode(ec, OUTPUT);
  pinMode(cp, OUTPUT);
  pinMode(ep, OUTPUT);
  pinMode(lm, OUTPUT);
  pinMode(er, OUTPUT);
  pinMode(li, OUTPUT);
  pinMode(ei, OUTPUT);
  pinMode(la, OUTPUT);
  pinMode(ea, OUTPUT);
  pinMode(suma, OUTPUT);
  pinMode(resta, OUTPUT);
  pinMode(multi, OUTPUT);
  pinMode(divid, OUTPUT);
  pinMode(eu, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(lo, OUTPUT);
  pc = 0;
  cont = 0;
  DDRA = 255;
}

void leer() {
  PORTA = pc;
  digitalWrite(ep, 1);
  digitalWrite(lm, 1);
  delay(1);
  digitalWrite(lm, 0);
  digitalWrite(ep, 0);
  digitalWrite(er, 1);
  digitalWrite(li, 1);
  delay(1);
  digitalWrite(li, 0);
  digitalWrite(er, 0);
}

void cargar() {
  digitalWrite(ei, 1);
  digitalWrite(lm, 1);
  delay(1);
  digitalWrite(lm, 0);
  digitalWrite(ei, 0);
  digitalWrite(er, 1);
  digitalWrite(la, 1);
  delay(1);
  digitalWrite(la, 0);
  digitalWrite(er, 0);
  pc++;
}

void sumar() {
  digitalWrite(ei, 1);
  digitalWrite(lm, 1);
  delay(1);
  digitalWrite(lm, 0);
  digitalWrite(ei, 0);
  digitalWrite(er, 1);
  digitalWrite(lb, 1);
  delay(1);
  digitalWrite(lb, 0);
  digitalWrite(er, 0);
  digitalWrite(suma, 1);
  digitalWrite(suma, 0);
  digitalWrite(eu, 1);
  digitalWrite(la, 1);
  delay(1);
  digitalWrite(la, 0);
  digitalWrite(eu, 0);
  pc++;
}

void restar() {
  digitalWrite(ei, 1);
  digitalWrite(lm, 1);
  delay(1);
  digitalWrite(lm, 0);
  digitalWrite(ei, 0);
  digitalWrite(er, 1);
  digitalWrite(lb, 1);
  delay(1);
  digitalWrite(lb, 0);
  digitalWrite(er, 0);
  digitalWrite(resta, 1);
  digitalWrite(resta, 0);
  digitalWrite(eu, 1);
  digitalWrite(la, 1);
  delay(1);
  digitalWrite(la, 0);
  digitalWrite(eu, 0);
  pc++;
}

void multiplicar() {
  digitalWrite(ei, 1);
  digitalWrite(lm, 1);
  delay(1);
  digitalWrite(lm, 0);
  digitalWrite(ei, 0);
  digitalWrite(er, 1);
  digitalWrite(lb, 1);
  delay(1);
  digitalWrite(lb, 0);
  digitalWrite(er, 0);
  digitalWrite(multi, 1);
  digitalWrite(multi, 0);
  digitalWrite(eu, 1);
  digitalWrite(la, 1);
  delay(1);
  digitalWrite(la, 0);
  digitalWrite(eu, 0);
  pc++;
}

void dividir() {
  digitalWrite(ei, 1);
  digitalWrite(lm, 1);
  delay(1);
  digitalWrite(lm, 0);
  digitalWrite(ei, 0);
  digitalWrite(er, 1);
  delay(1);
  valor = PINK;
  if (valor != 0) {
    digitalWrite(lb, 1);
    delay(1);
    digitalWrite(lb, 0);
    digitalWrite(er, 0);
    digitalWrite(divid, 1);
    digitalWrite(divid, 0);
    digitalWrite(eu, 1);
    digitalWrite(la, 1);
    delay(1);
    digitalWrite(la, 0);
    digitalWrite(eu, 0);
    pc++;
  } else {
    mostrarError();
    parar();
  }
}

void retornar() {
  pc = possition;
}

//void menosUno(){
//  digitalWrite(ea, 1);
//  digitalWrite(lc, 1);
//  delay(1);
//  digitalWrite(lc,0);
//  digitalWrite(ea,0);
//
//  PORTA = 0;
//  digitalWrite(la, 1);
//  delay(1);
//  digitalWrite(la,0);
//
//  PORTA = 1;
//  digitalWrite(lb,1);
//  delay(1);
//  digitalWrite(lb,0);
//
//  digitalWrite(resta,1);
//  digitalWrite(eu,1);
//  delay(1);
//  digitalWrite(resta,0);
//  digitalWrite(la, 1);
//  delay(1);
//  digitalWrite(la,0);
//  digitalWrite(eu,0);
//
//  digitalWrite(ec,1);
//  digitalWrite(lb,1);
//  delay(1);
//  digitalWrite(lb,0);
//  digitalWrite(ec,0);
//
//  digitalWrite(multi, 1);
//  digitalWrite(eu,1);
//  delay(1);
//  digitalWrite(multi,0);
//  digitalWrite(la, 1);
//  delay(1);
//  digitalWrite(la,0);
//  digitalWrite(eu,0);
//  pc++;
//}

void menosUno() {
  digitalWrite(ea, 1);
  digitalWrite(lb, 1);
  delay(1);
  digitalWrite(lb, 0);
  digitalWrite(ea, 0);
  digitalWrite(multi, 1);
  digitalWrite(eu, 1);
  delay(1);
  digitalWrite(multi, 0);
  digitalWrite(la, 1);
  delay(1);
  digitalWrite(la, 0);
  digitalWrite(eu, 0);
  pc++;
}

void vayaA() {
  digitalWrite(ei, 1);
  delay(1);
  possition = pc + 1;
  pc = PINK;
  digitalWrite(ei, 0);
}

void parar() {
  while (1);
  pc = 0;
}

void mostrar() {
  digitalWrite(ea, 1);
  digitalWrite(lo , 1);
  delay(1);
  digitalWrite(lo , 0);
  digitalWrite(ea, 0);
  pc++;
}

void mostrarError() {
  PORTH = 238;// es en hexa 1110 1110 -> EE
  digitalWrite(er, 0);
  digitalWrite(ep, 1);
  digitalWrite(lo , 1);
  delay(1);
  digitalWrite(lo , 0);
  digitalWrite(ep, 0);
}

void loop() {
  leer();
  if (digitalRead(lda) == 1) cargar();
  if (digitalRead(add) == 1) sumar();
  if (digitalRead(sub) == 1) restar();
  if (digitalRead(mul) == 1) multiplicar();
  if (digitalRead(dib) == 1) dividir();
  if (digitalRead(got) == 1) vayaA();
  if (digitalRead(ret) == 1) retornar();
  if (digitalRead(inv) == 1) menosUno();
  if (digitalRead(out) == 1) mostrar();
  if (digitalRead(halt) == 1) parar();
  cont = 0;
}

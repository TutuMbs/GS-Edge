#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 9
#define ECHO_PIN 8
#define BUZZER_PIN 7

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int maxDistancia = 400; // sensor no Wokwi

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.begin(16, 2);
  lcd.backlight();

  Serial.begin(9600);
}

long medirDistanciaCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracao = pulseIn(ECHO_PIN, HIGH);
  long distancia = duracao * 0.034 / 2;
  return distancia;
}

void loop() {
  long distancia = medirDistanciaCM();
  long nivelRioSimulado =  distancia;
  float nivelRioReal = (nivelRioSimulado / 400.0) * 800.0; // conversão para escala de 8 metros

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nivel: ");
  lcd.print((int)nivelRioReal);
  lcd.print("cm");

  lcd.setCursor(0, 1);
  if (nivelRioReal < 200) {
    lcd.print("Nivel Baixo");
    digitalWrite(BUZZER_PIN, LOW);
  } else if (nivelRioReal <= 500) {
    lcd.print("Acima da metade");
    digitalWrite(BUZZER_PIN, LOW);
  } else if (nivelRioReal <= 700) {
    lcd.print("Rio Cheio");
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    lcd.print("!!! PERIGO !!!");
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("Enviando alerta de seguranca: rio em estado perigoso");
  }

  delay(1000);
}

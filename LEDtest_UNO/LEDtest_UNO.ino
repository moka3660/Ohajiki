const int LED_SIG = 0;
const int LED_R = 1;
const int LED_G = 2;
const int LED_B = 5;

#define colorlength 1000
unsigned long colortimes;

void setup()
{
  pinMode(LED_SIG, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  digitalWrite(LED_SIG, LOW);
  digitalWrite(LED_R,LOW);
  digitalWrite(LED_G,LOW);
  digitalWrite(LED_B,LOW);
}

void loop()
{
  colortimes = millies();
  while(millis()-colortimes < colorlength)
  {
    digitalWrite(LED_R, HIGH);
    analogWrite(LED_SIG, 126);
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    analogWrite(LED_SIG, 126);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
    analogWrite(LED_SIG, 126);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_R, HIGH);
  }

//  delay(1000);
  colortimes = millies();
  while(millis()-colortimes < colorlength)
  {
    digitalWrite(LED_R, HIGH);
    analogWrite(LED_SIG, 255);
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    analogWrite(LED_SIG, 0);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
    analogWrite(LED_SIG, 0);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_R, HIGH);
  }
}

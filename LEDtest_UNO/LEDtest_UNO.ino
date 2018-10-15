const int LED_SIG = 0;
const int LED_R = 1;
const int LED_G = 2;
const int LED_B = 5;

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
  
}

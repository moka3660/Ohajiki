const int PHOTO_SW = 4;
const int VIB_SW = 3;
const int LED_SIG = 0;
const int LED_R = 1;
const int LED_G = 2;
const int LED_B = 5;
int randRed = 0;
int randGreen = 0;
int randBlue = 0;

void setup()
{
  //入出力設定
  pinMode(PHOTO_SW,INPUT);
  pinMode(VIB_SW,INPUT);
  pinMode(LED_R,OUTPUT);
  pinMode(LED_G,OUTPUT);
  pinMode(LED_B,OUTPUT);
  digitalWrite(LED_R,LOW);
  digitalWrite(LED_G,LOW);
  digitalWrite(LED_B,LOW);
}

void loop()
{
  if(digitalRead(PHOTO_SW))
    lighting(300, 255, 255, 255);
  else
    lighting(300, 0, 0 ,0);
}

void lighting(int Length, int Red, int Green, int Blue)
{
  unsigned long colortimes;
  colortimes = millis();
  while(millis()-colortimes < Length)
    {
      digitalWrite(LED_R, HIGH);
      analogWrite(LED_SIG, Red);
      delayMicroseconds(100);
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, HIGH);
      analogWrite(LED_SIG, Green);
      delayMicroseconds(100);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, HIGH);
      analogWrite(LED_SIG, Blue);
      delayMicroseconds(100);
      digitalWrite(LED_B, LOW);
      digitalWrite(LED_R, HIGH);
  }
}

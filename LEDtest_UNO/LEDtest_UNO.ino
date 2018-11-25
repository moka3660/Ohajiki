const int LED_SIG = 0;
const int LED_R = 1;
const int LED_G = 2;
const int LED_B = 3;

#define colorlength 1000
//unsigned long colortimes;

void setup()
{
//  pinMode(LED_SIG, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
//  digitalWrite(LED_SIG, LOW);
  digitalWrite(LED_R,LOW);
  digitalWrite(LED_G,LOW);
  digitalWrite(LED_B,LOW);
}

void loop()
{
	lighting(1000, 255, 255, 255);
	lighting(1000, 0, 0, 0);
  lighting(500, 255, 0, 0);
  lighting(500, 0, 255, 0);
  lighting(500, 0, 0, 255);
  lighting(300, 0, 0, 0);
  lighting(300, 255, 255, 255);
  lighting(300, 128, 128, 0);
  lighting(300, 255, 255, 0);
  lighting(300, 255, 0, 255);
  lighting(300, 192, 192, 192);
  lighting(300, 0, 255, 255);
  lighting(300, 0, 255, 0);
  lighting(300, 255, 0, 0);
  lighting(300, 128, 128, 128);
  lighting(300, 0, 0, 255);
  lighting(300, 0, 128, 0);
  lighting(300, 128, 0, 128);
  lighting(300, 0, 0, 128);
  lighting(300, 0, 128, 128);
  lighting(300, 128, 0, 0);
  lighting(700, 0, 0, 0);
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

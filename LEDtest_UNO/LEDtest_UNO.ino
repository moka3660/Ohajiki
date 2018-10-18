const int LED_SIG = 0;
const int LED_R = 1;
const int LED_G = 2;
const int LED_B = 5;

#define colorlength 1000
//unsigned long colortimes;

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
	lighting(1000, 255, 255, 255);
	lighting(1000, 255, 126, 0);
}


void lighting(int Length, int Red, int Green, int Blue)
{
	unsigned long colortimes = millies();
 	while(millis()-colortimes < Length)
  	{
    	digitalWrite(LED_R, HIGH);
	    analogWrite(LED_SIG, Red);
	    digitalWrite(LED_R, LOW);
	    digitalWrite(LED_G, HIGH);
	    analogWrite(LED_SIG, Green);
	    digitalWrite(LED_G, LOW);
	    digitalWrite(LED_B, HIGH);
	    analogWrite(LED_SIG, Blue);
	    digitalWrite(LED_B, LOW);
	    digitalWrite(LED_R, HIGH);
	}
}
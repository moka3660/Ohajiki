const int LED_R = 2;
const int LED_G = 3;
const int LED_B = 4;

void setup()
{
}

void loop()
{
	analogWrite(LED_R, 255);
  analogWrite(LED_G, 0);
  analogWrite(LED_B, 0);
  delay(1000);
  analogWrite(LED_R, 0);
  analogWrite(LED_G, 255);
  analogWrite(LED_B, 0);
  delay(1000);
  analogWrite(LED_R, 0);
  analogWrite(LED_G, 0);
  analogWrite(LED_B, 255);
  delay(1000);
}

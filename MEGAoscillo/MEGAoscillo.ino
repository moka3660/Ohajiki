void setup()
{
  pinMode(0,INPUT);
  Serial.begin(9600);
}

void loop()
{
//  Serial.println(analogRead(0));
  Serial.println(digitalRead(0));
}

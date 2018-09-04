const int PHOTO_SW = 3;
const int VIB_SW = 4;
const int LED_SIG = 0;
const int LED = 1;//for debug

void setup()
{
  //入出力設定
  pinMode(PHOTO_SW,INPUT);
  pinMode(VIB_SW,INPUT);
  pinMode(LED_SIG,OUTPUT);
  pinMode(LED,OUTPUT);
}

void loop()
{

}

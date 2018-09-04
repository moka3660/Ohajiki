const int PHOTO_SW = 3;
const int VIB_SW = 4;
const int LED_SIG = 0;
const int LED = 1;//for debug
boolean mode = false;
#define vibLimit 15000  //衝撃検知待ち時間
#define chatterLimit 700 //衝撃検知一回の時間
#define chatterTimes 10 //チャタリング回数

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
  mode = false;
  //PHOTO_SW入力待ち
  while(1)
  {
    if(digitalRead(PHOTO_SW))
      break;
  }

  boolean vibstate = false;
  int chattercount = 0;
  unsigned long vibtime;
  unsigned long chattertime;
  vibtime = millis();
  while(millis()-vibtime<vibLimit)
  {
    if(vibstate != digitalRead(VIB_SW))
    {
      vibstate = !vibstate;
      chattercount++;
      if(chattercount==1)
        chattertime = millis();
    }
    if(chattercount >= chatterTimes)
    {
      mode = true;
      break;
    }
    if(millis()-chattertime > chatterLimit)
      chattercount = 0;
  }

}

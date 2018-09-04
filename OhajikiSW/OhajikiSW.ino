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

  //衝撃検知
  boolean vibstate = false;
  int chattercount = 0;
  unsigned long vibtime;
  unsigned long chattertime;
  vibtime = millis(); //開始時間取得
  while(millis()-vibtime<vibLimit)
  {
    //チャタリングカウンタ
    if(vibstate != digitalRead(VIB_SW))
    {
      vibstate = !vibstate;
      chattercount++;
      if(chattercount==1)
        chattertime = millis();
    }
    //チャタリング回数が一定以上になればモード変更して脱出
    if(chattercount >= chatterTimes)
    {
      mode = true;
      break;
    }
    //チャタリング回数に達しなければカウンタ初期化
    if(millis()-chattertime > chatterLimit)
      chattercount = 0;
  }

}

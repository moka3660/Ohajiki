const int PHOTO_SW = 4;
const int VIB_SW = 3;
const int LED_SIG = 0;
const int LED1 = 1;//for debug 1
const int LED2 = 2;//for debug 2
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
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  digitalWrite(LED_SIG,LOW);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2>LOW);
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

  digitalWrite(LED1,HIGH); //debug
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
      digitalWrite(LED1,LOW);
      mode = true;
      break;
    }
    //チャタリング回数に達しなければカウンタ初期化
    if(millis()-chattertime > chatterLimit)
      chattercount = 0;
  }

  //DEBUG
  if (mode == true)
  {
  	digitalWrite(LED2,HIGH);
  	delay(1000);
  	digitalWrite(LED2,LOW);
  }
  else
  {
  	digitalWrite(LED1,LOW);//衝撃検知終了
  	digitalWrite(LED2,LOW);
  	delay(1000);
  }
  //DEBUG

}

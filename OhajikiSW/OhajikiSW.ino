const int PHOTO_SW = 4;
const int VIB_SW = 4;
const int LED_SIG = 0;
const int LED_R = 1;
const int LED_G = 2;
const int LED_B = 5;
//const int LED1 = 1;//for debug 1
//const int LED2 = 2;//for debug 2
boolean mode = false;
#define vibLimit 15000  //衝撃検知待ち時間
#define chatterLimit 700 //衝撃検知一回の時間
#define chatterTimes 10 //チャタリング回数
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
  mode = false;
  //PHOTO_SW入力待ち
  while(1)
  {
    if(digitalRead(PHOTO_SW))
      break;
  }

  lighting(300, 255, 255, 255); //debug
  //衝撃検知
  boolean vibstate = false;
  int chattercount = 0;
  unsigned long vibtime;
  unsigned long chattertime;
  vibtime = millis(); //開始時間取得
  while(millis() - vibtime < vibLimit)
  {
    //チャタリングカウンタ
    if(vibstate != digitalRead(VIB_SW))
    {
      vibstate = !vibstate;
      chattercount++;
      if(chattercount == 1)
        chattertime = millis();
    }
    //チャタリング回数が一定以上になればモード変更して脱出
    if(chattercount >= chatterTimes)
    {
//      digitalWrite(LED1,LOW);
      mode = true;
      break;
    }
    //チャタリング回数に達しなければカウンタ初期化
    if(millis() - chattertime > chatterLimit)
      chattercount = 0;
  }

  //DEBUG
  if (mode == true)
  {
    //変色
    randRed = random(256);
    randGreen = random(256);
    randBlue = random(256);
    lighting(10000, randRed, randGreen, randBlue);
  }
  else
  {
    //戻る
  //	digitalWrite(LED1,LOW);//衝撃検知終了
  //	digitalWrite(LED2,LOW);
  	delay(1000);
  }
  //DEBUG

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

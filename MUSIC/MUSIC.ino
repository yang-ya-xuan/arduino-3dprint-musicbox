//定義音符的頻率
#define Do 262  
#define Re 294  
#define Mi 330  
#define Fa 349  
#define Sol 392
#define G42 415  //#5 #Sol  
#define La 440  
#define Si 494  
#define Do_h 523  
#define Re_h 587
#define D52 622  //#2 #Re_h
#define Mi_h 659  
#define Fa_h 698  
#define Sol_h 784  
#define La_h 880  
#define Si_h 988
#define O1 000  //休止符

int LIGHT_SENSOR_PIN = A5;//光敏感測器
int light2=0;//光敏感測器數值

int tonepin = 2;//蜂鳴器
//燈泡
int a = 6;//Sol、D52(車)
int b = 7;//La
int c = 8;//Do_h、Do(星)
int d = 9;//Si
int e = 10;//Re_h、Re(星)
int f = 11;//Sol_h、Mi(車)
int g = 12;//Mi_h、Mi(星)
int h = 13;//Fa_h、Fa(星)、O1(車)
int i = 5;//G42


void setup()
{
  pinMode(tonepin,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(h,OUTPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);//光敏感測器
  Serial.begin(9600); 
}

void stopMusicAndLights() 
{
  noTone(tonepin); //停止音樂
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);
  digitalWrite(i, LOW);
}

//生日快樂
void birthday()
{
  
  int birthdayscale[]=
  {
    Sol,Sol,La,Sol,Do_h,Si,
    Sol,Sol,La,Sol,Re_h,Do_h,
    Sol,Sol,Sol_h,Mi_h,Do_h,Si,La,
    Fa_h,Fa_h,Mi_h,Do_h,Re_h,Do_h

  };//音符順序
  float birthdaydurt[]=
  {
    0.5,0.5,1,1,1,1+1,
    0.5,0.5,1,1,1,1+1,
    0.5,0.5,1,1,1,1,1,
    0.5,0.5,1,1,1,1+1,
  };//音符時長
  float birthdaylight[]=
  {
    a,a,b,a,c,d,
    a,a,b,a,e,c,
    a,a,f,g,c,d,b,
    h,h,g,c,e,c

  };//燈泡亮的順序

  for(int x=0;x<25;x++)//總共有25個音符
  {
    if (analogRead(LIGHT_SENSOR_PIN) < 110) 
    {
      stopMusicAndLights();
      return;
    }
    tone(tonepin,birthdayscale[x]);//生成音樂
    digitalWrite(birthdaylight[x],HIGH);//打開燈泡
    delay(500*birthdaydurt[x]);//音符持續的時間，500毫秒*目前到的音符時長(21)

    digitalWrite(birthdaylight[x],LOW);
    delay(100*birthdaydurt[x]);//音符中間間隔的時間
    noTone(tonepin);//避免出現聲音持續播放
  }
  delay(1000);

   
}

//小星星
void star()
{
  int starscale[]=
  {
    Do,Do,Sol,Sol,La,La,Sol, 
    Fa,Fa,Mi,Mi,Re,Re,Do,
    Sol,Sol,Fa,Fa,Mi,Mi,Re,
    Sol,Sol,Fa,Fa,Mi,Mi,Re,
    Do,Do,Sol,Sol,La,La,Sol,
    Fa,Fa,Mi,Mi,Re,Re,Do
  };

  int stardurt[]=
  { 
    1,1,1,1,1,1,1.5,   
    1,1,1,1,1,1,1.5,   
    1,1,1,1,1,1,1.5,   
    1,1,1,1,1,1,1.5,   
    1,1,1,1,1,1,1.5,  
    1,1,1,1,1,1,1.5
  };

  float starlight[]=
  {
    c,c,a,a,b,b,a,
    h,h,g,g,e,e,c,
    a,a,h,h,g,g,e,
    a,a,h,h,g,g,e,
    c,c,a,a,b,b,a,
    h,h,g,g,e,e,c
  };

  for(int x=0;x<42;x++)//總共有25個音符
  {
    if (analogRead(LIGHT_SENSOR_PIN) < 110) 
    {
      stopMusicAndLights();
      return;
    }
    tone(tonepin,starscale[x]);//生成音樂
    digitalWrite(starlight[x],HIGH);//打開燈泡
    delay(400*stardurt[x]);//音符持續的時間，500毫秒*目前到的音符時長(21)

    digitalWrite(starlight[x],LOW);
    delay(80*stardurt[x]);//音符中間間隔的時間
    noTone(tonepin);//避免出現聲音持續播放
  }
  delay(1000);
}

//垃圾車
void alice()
{

  int alicescale[]=
  {
    Mi_h,D52,Mi_h,D52,Mi_h,Si,Re_h,Do_h,La,
    O1,Mi,La,
    Si,Mi,G42,Si,Do_h,Mi,
    Mi_h,D52,Mi_h,D52,Mi_h,Si,Re_h,Do_h,La,
    O1,Mi,La,
    Si,Mi,Do_h,Si,La
  };
  int alicedurt[]=
  {
    1,1,1,1,1,1,1,1,3,
    0,1,1,
    3,1,1,1,3,1,
    1,1,1,1,1,1,1,1,3,
    0,1,1,
    3,1,1,1,3
  };


int alicelight[]=
{
    g,a,g,a,g,d,e,c,b,
    h,f,b,
    d,f,i,d,c,f,
    g,a,g,a,g,d,e,c,b,
    h,f,b,
    d,f,c,d,b
};

  for(int x=0;x<35;x++)//總共有25個音符
  {
    if (analogRead(LIGHT_SENSOR_PIN) < 110) 
    {
      stopMusicAndLights();
      return;
    }
    tone(tonepin,alicescale[x]);//生成音樂
    digitalWrite(alicelight[x],HIGH);//打開燈泡
    delay(200*alicedurt[x]);//音符持續的時間，500毫秒*目前到的音符時長(21)

    digitalWrite(alicelight[x],LOW);
    delay(100*alicedurt[x]);//音符中間間隔的時間
    noTone(tonepin);//避免出現聲音持續播放
  }
  delay(1000);
}


void loop()
{
  light2 = analogRead(LIGHT_SENSOR_PIN); //將讀取到的光敏感測器數值存入light2變數
  Serial.println(light2);

    int randomSong = random(3); //隨機選取一首歌
    switch(randomSong)
    {
      case 0:
        birthday();
        break;
      case 1:
        star();
        break;
      case 2:
        alice();
        break;
    }

}


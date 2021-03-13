//27/07/2019 2:33 dit lukt en moet alleen schoon gemaakt worden !

#include "Nextion.h"
#define   botton6         6//blauw
#define   botton5         5//groen
#define   botton3         3//rood
//---------------------------------
#define   botton11        11//lamp
#define   botton10        10//lamp
#define   botton9         9//lamp
#define   botton7         7//lamp
//------------------------------
NexDSButton bt1  = NexDSButton(2, 2, "bt1");//blauw-- (5//pagina nummer, 7//id van obj, bt1//naam obj)
NexDSButton bt3  = NexDSButton(2, 4, "bt3");//groen
NexDSButton bt2  = NexDSButton(2, 3, "bt2");//rood
NexDSButton bt4  = NexDSButton(2, 7, "bt4");//relax
NexDSButton bt5  = NexDSButton(2, 6, "bt0");//disco
//---------------------------
NexDSButton bt7  = NexDSButton(7,  8, "bt0");//lamp knop
NexDSButton bt9  = NexDSButton(9,  8, "bt0");//lamp knop
NexDSButton bt10 = NexDSButton(10, 8, "bt0");//lamp knop
NexDSButton bt11 = NexDSButton(11, 8, "bt0");//lamp knop
NexSlider   h20  = NexSlider  (15, 1, "h0");//blauw slider
NexSlider   h21  = NexSlider  (15, 2, "h1");//rood slider
NexSlider   h22  = NexSlider  (15, 3, "h2");//groen slider

//----------------------------
NexTouch *nex_listen_list[] =
{
  &h20,
  &h21,
  &h22,
  &bt1,
  &bt2,
  &bt3,
  &bt4,
  &bt5,
  &bt7,
  &bt9,
  &bt10,
  &bt11,
  NULL
};
//-------------------------
 void prender_h20()
{
  uint32_t estado2 ; 
  h20.getValue(&estado2); 
    int val2= estado2;
    int val = map(val2,0,100,0,255);
    analogWrite(botton6, val);
}
 void prender_h21()
{
  uint32_t estado2 ; 
  h21.getValue(&estado2); 
    int val2= estado2;
    int val = map(val2,0,100,255,0);
    analogWrite(botton3, val);
}
 void prender_h22()
{
  uint32_t estado2 ; 
  h22.getValue(&estado2); 
    int val2= estado2;
    int val = map(val2,0,100,0,255);
    analogWrite(botton5, val);
}
//-----------------------------
void prender_bt1() // blauwe led
{ 
  uint32_t estado;
  bt1.getValue(&estado);
  if(estado == 1)
  {
    analogWrite(botton6, 255);
   }
  else
  {
    analogWrite(botton6, 0);
  }
}

void prender_bt2() //rode led
{
  uint32_t estado;
  bt2.getValue(&estado);
  if(estado == 0)
  {
    analogWrite(botton3, 255);
  }
  else
  {
    analogWrite(botton3, 0);
  }
}

void prender_bt3() // groene led
{

  uint32_t estado;
  bt3.getValue(&estado);
  if(estado == 1)
  {
    analogWrite(botton5,255);
   }
  else
  {
    analogWrite(botton5, 0);
  }
}
//-----------------------------------
void prender_bt4() //relax knop
{
  analogWrite(botton3, 255);
  analogWrite(botton5, 0);
  analogWrite(botton6, 0);  
  int i=1;
  uint32_t estado;
  uint32_t val;
  bt4.getValue(&estado);
  int totaal = 0;
  int totaalR = 255;
  bool up = false;
  bool a = false;
  int led=0;
  int count=0;
  int leds[] = {botton5,botton6};
  do{  
      bt4.getValue(&estado);
     if( estado == 0)
    {
      analogWrite(botton6,0);
      analogWrite(botton5,0);
      analogWrite(botton3,255);
      led=0;
      totaal=0;
      delay(100);
      prender_bt1();
      delay(100);
      prender_bt3();
      delay(100);
      prender_bt2();
     h20.getValue(&val);
     val = 100;
      break;
      
    }
    else if ( estado == 1)
    {
      if(!up)//up falso
      {      
        totaal++;
        if(totaal >= 255)
        {
          up = true; 
        }
      }
      if(up) //up true
      {
       totaal--;
       if(totaal <= 0)
       {
          analogWrite(leds[0],0);
          analogWrite(leds[1],0);
          led++;
          count++;
          if( led >= 3)
          {
            led = 0;
            count++;
          }
          up = false;
        }
       }
     
      if(!a)
      {
        totaalR--;
        if( totaalR <= 0)
        {
          a = true;
        }
      }
      if(a)
      {
        totaalR++;
        if(totaalR >= 255)
        {
          analogWrite(botton3,255);
          a = false;
        }
      }
      //analogWrite(leds[0],totaal);
      if(count <= 1)
      {
        analogWrite(leds[led],totaal);
      }
      else if ( count == 2)
      {
        analogWrite(botton3,totaalR);
      }
      else if( count >2 )
      {
        count = 0;
      }
      
      //Serial.println(count);
   }
  }while(i == 1); 
}

void prender_bt5() //disco knop
{
  
  uint32_t estado;
  bt5.getValue(&estado);
  if(estado == 1)
  {
    digitalWrite(botton5, HIGH);
   }
  else
  {
    digitalWrite(botton5, LOW);
  }
}

void prender_bt7()
{
  
  uint32_t estado;
  bt7.getValue(&estado);
  if(estado == 1)
  {
    digitalWrite(botton7, HIGH);
   }
  else
  {
    digitalWrite(botton7, LOW);
  }
}


void prender_bt9()
{
  
  uint32_t estado;
  bt9.getValue(&estado);
  if(estado == 1)
  {
    digitalWrite(botton9, HIGH);
   }
  else
  {
    digitalWrite(botton9, LOW);
  }
}
void prender_bt10()
{
  
  uint32_t estado;
  bt10.getValue(&estado);
  if(estado == 1)
  {
    digitalWrite(botton10, HIGH);
   }
  else
  {
    digitalWrite(botton10, LOW);
  }
}
void prender_bt11()
{
  
  uint32_t estado;
  bt11.getValue(&estado);
  if(estado == 1)
  {
    digitalWrite(botton11, HIGH);
   }
  else
  {
    digitalWrite(botton11, LOW);
  }
}

//---------------------------------




void setup() {
  
  nexInit();
  digitalWrite(botton3,HIGH );
  pinMode(botton6, OUTPUT);
  pinMode(botton5, OUTPUT);
  pinMode(botton3, OUTPUT);

  //-----------------------
  pinMode(botton7, OUTPUT);
  pinMode(botton9, OUTPUT);
  pinMode(botton10, OUTPUT);
  pinMode(botton11, OUTPUT);
  //----------------------
  bt1.attachPop(prender_bt1);
  bt2.attachPop(prender_bt2);
  bt3.attachPop(prender_bt3);
  
  //------------------------
  bt4.attachPop(prender_bt4);
  bt5.attachPop(prender_bt5);
  h22.attachPop(prender_h22);
  h21.attachPop(prender_h21);
  h20.attachPop(prender_h20);
  bt7.attachPop(prender_bt7);
  bt9.attachPop(prender_bt9);
  bt10.attachPop(prender_bt10);
  bt11.attachPop(prender_bt11);
  //---------------------------
}

void loop() {
  nexLoop(nex_listen_list);
}

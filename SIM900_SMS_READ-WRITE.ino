#include "SIM900.h"
#include <SoftwareSerial.h>
//#include "inetGSM.h"  //for better performance dont add HTTP library
//فقط اگه با نت میخوای کار کنی لایبلرری بالا رو فعال کن با اینکار رم کمتری مصرف میشه


#include "sms.h" //have to add this lib for sms //لایبرری اس ام اس
SMSGSM sms;

//To change pins for Software Serial, use the two lines in GSM.cpp //واسه شناسوندن اردوینو حتما باید شماره پین هاتونو توی فایل  GSM.cpp عوض کنی 


int numdata;
boolean started=false;
char smsbuffer[160];
char n[20];

void setup() 
{
  //Serial connection.
  Serial.begin(9600); //واسه بادریت 9600 انتخاب کن چون ماژول با این بادریت کار میکنه 
  Serial.println("GSM Shield testing.");  //Start configuration of shield with baudrate. //حواست باشه اگه میخوای با نت کار کنی بادریت بایت 4800 انتخاب کنی
  if (gsm.begin(2400)){ //شرط استارت
    Serial.println("\nstatus=READY");
    started=true;  
  }
  else Serial.println("\nstatus=IDLE");
  
  if(started){
   
    if (sms.SendSMS("+989022040132", "yasi yasi yasi")) //if (sms.SendSMS(" شماره", "پیغام"))
      Serial.println("\nSMS sent OK");
  }

};

void loop() 
{
  if(started){
    if(gsm.readSMS(smsbuffer, 160, n, 20)) //read sms buffer //اگه تو سریال پیغام اومد چاپ کنه
    {
      Serial.println(n);
      Serial.println(smsbuffer);
    }
    delay(1000);
  }
};

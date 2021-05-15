

#include <IRremote.h>
#include<SoftwareSerial.h>
SoftwareSerial mySerial(3,4);


String no="8105325556";
int RECV_PIN = 2;//tsop out gnd vcc
IRrecv irrecv(RECV_PIN);
decode_results results;
int incomingByte;
String msg="Traffic Violation" ; 
String m2=""; 
void setup()
{

  pinMode (2,INPUT);
  pinMode (3,OUTPUT);
  pinMode (4,OUTPUT);
  pinMode (5,OUTPUT); 
  pinMode (6,OUTPUT);
  pinMode (7,OUTPUT);
  pinMode (8,OUTPUT);
  pinMode (9,OUTPUT);
  pinMode (10,OUTPUT);
  pinMode (11,OUTPUT);
  pinMode (12,OUTPUT);
  pinMode (13,OUTPUT);
  pinMode (14,OUTPUT);
  pinMode (15,OUTPUT);
  Serial.begin(9600);
 mySerial.begin(9600);

  irrecv.enableIRIn(); // Start the receiver
}

void loop() {

  if (irrecv.decode(&results)) 
  {
    //Serial.println(results.value);
    irrecv.resume(); // Receive the next value

  }
  if((results.value==3778927144))//1_NORTH
  {
    res();
    digitalWrite(11,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(6,HIGH);
    msg="SIGNAL JUMP ,pay penalty of Rs.100  http://27.7.132.9/dashboard/signaljump.png";
  }
  //if((results.value==3526956266))//TV fast Divider shift 
  //{
  //  digitalWrite(,HIGH);
  //}

  if((results.value==2908251746))//2_SOUTH   
  {
    res();
    digitalWrite(5,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(6,HIGH);
    msg="SIGNAL JUMP ,pay penalty of Rs.100 http://27.7.132.9/dashboard/signaljump.png";

  }



 if((results.value==657459652))//3_WEST   
  {
    res();
    digitalWrite(13,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH); 
    msg="SIGNAL JUMP ,pay penalty of Rs.100 http://27.7.132.9/dashboard/signaljump.png"; 

  }

  if((results.value==4120482440))//4_EAST   
  {
    res();
    digitalWrite(13,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(5,HIGH);
    msg="SIGNAL JUMP ,pay penalty of Rs.100 http://27.7.132.9/dashboard/signaljump.png";

  }

  if((results.value==1931099650))//5_NORMAL LANE   
  {
    res();
    digitalWrite(7,HIGH);
    //msg="SIGNAL JUMP ,pay penalty of Rs.100"; 

  }

  if((results.value==2340753640))//9_PEDESTRIAN
  {
    res();
    digitalWrite(13,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    msg="SIGNAL JUMP ,pay penalty of Rs.100 http://27.7.132.9/dashboard/signaljump.png"; 

  }
  if((results.value==742730860))//6_FAST LANE 
  {
    res();
    digitalWrite(8,HIGH);
    //msg="SIGNAL JUMP ,pay penalty of Rs.100"; 

  }




  if(results.value==1167253836)//7_AMBULANCE

  {
    res();
    digitalWrite(9,HIGH);
    //msg="SPEEDING ,pay penalty of Rs.300"; 

  }

  if(results.value==1747313982)//8_PARKING
  {
    res();
    digitalWrite(10,HIGH);
    msg="NO PARKING ,pay penalty of Rs.100 http://27.7.132.9/dashboard/noparking.png"; 
  }

  if(results.value==3526956266)//TV_footpath
  {
    res();
    //digitalWrite(11,HIGH);
    msg="WRONG PARKING(FOOTPATH) ,pay penalty of Rs.100 http://27.7.132.9/dashboard/wrongparking.png";

  }     
  if(results.value==1723810024)//OK SMS
  {
    digitalWrite(12,HIGH);
    sms();
  }

  if(results.value==4105841032)//POWER_reset
  {

    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
  }

  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();


    if((incomingByte == 'L'))//5_normal Divider 
    {
      res();
      digitalWrite(7,HIGH);
      //sms();
    }
    if((incomingByte == 'F'))//6_fast Divider shift 
    {
      res();
      digitalWrite(8,HIGH);
      //sms();
    }

    if((incomingByte == 'N'))//1_NORTH   
    {
      res();
      
      digitalWrite(11,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(13,HIGH);
    
      msg="SIGNAL JUMP ,pay penalty of Rs.100  http://27.7.132.9/dashboard/signaljump.png"; 
    }

    if((incomingByte == 'S'))//2_SOUTH   
    {
      res();
      digitalWrite(11,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      msg="SIGNAL JUMP ,pay penalty of Rs.100  http://27.7.132.9/dashboard/signaljump.png"; 
    }

    if((incomingByte == 'E'))//4_EAST
    {
      res();
      digitalWrite(13,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(5,HIGH);
      msg="SIGNAL JUMP ,pay penalty of Rs.100  http://27.7.132.9/dashboard/signaljump.png"; 
    }

    if((incomingByte == 'W'))//3_WEST  
    {
      res();
      digitalWrite(13,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      msg="SIGNAL JUMP ,pay penalty of Rs.100  http://27.7.132.9/dashboard/signaljump.png"; 
    }

    if((incomingByte == 'P'))//9_PEDESTRIAN  
    {
      res();
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      msg="SIGNAL JUMP ,pay penalty of Rs.100  http://27.7.132.9/dashboard/signaljump.png"; 
    }

    if((incomingByte == 'M'))//7_AMBULANCE
    {
      res();
      digitalWrite(9,HIGH);
      //sms();
    } 
    if((incomingByte == 'X'))//7_RESET
    {
      res();
    }



  }
}

void sms()
{
  if(mySerial.available())
  {

    if (!(msg.equals(m2)))
  {  
      mySerial.println("AT"); 
      delay(1000);
      mySerial.println("AT+CMGF=1"); // send SMS in text mode
      delay(1000);
      mySerial.println("AT+CMGS=\"+91"+no+"\"");//CHANGE TO Number , you'd like to receive message
      delay(1000);
      mySerial.print(msg);// content of the message
      digitalWrite(13,HIGH);
      digitalWrite(13,LOW);
      mySerial.write(26); // ctrl+z ASCII code
      delay(1000); // Wait for 5 minutes before next reading
      m2=msg;
    }
  }
}
void res()
{
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW); 
}



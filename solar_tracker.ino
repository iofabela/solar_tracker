#include<Servo.h>

int ldr_sup_izq =0; //1              __________________  
int ldr_sup_der =0; //2             |1                2| 
int ldr_cen_cen =0; //3             |        3         | 
int ldr_inf_izq =0; //4             |                  |
int ldr_inf_der =0; //5             |4________________5|
                                     
Servo servo_pan;  //Servo de paneo(voltear hacia los lados)
Servo servo_tilt; //Servo de tilt (voltear hacia arriba y abajo) 

int led_sup_izq =2; //1             
int led_sup_der =3; //2             
int led_cen_cen =4; //3        
int led_inf_izq =5; //4             
int led_inf_der =6; //5

int pos_pan = 90;
int pos_tilt =90;

void setup() 
{
  Serial.begin(9600);

  servo_pan.attach(9);   //Digital #D10
  servo_tilt.attach(10); //Digial #D09

  servo_pan.write(pos_pan); // 0 (izq) a 180 (der)
  servo_tilt.write(pos_tilt);// 90(centro) a 180 (arriba)

  pinMode(led_sup_izq,OUTPUT);
  pinMode(led_sup_der,OUTPUT);
  pinMode(led_cen_cen,OUTPUT);
  pinMode(led_inf_izq,OUTPUT);
  pinMode(led_inf_der,OUTPUT);

}


void loop() 
{
  
  /*for(int i = 90 ; i>=0 ; i--)
  {
    servo_tilt.write(i);
    delay(50);
  }
  
  for(int i = 0 ; i<=90 ; i++)
  {
    servo_tilt.write(i);
    delay(50);
  }
  
  for(int i = 90 ; i<=180 ; i++)
  {
    servo_pan.write(i);
    delay(50);
  }
  
  for(int i = 180 ; i>=90 ; i--)
  {
    servo_pan.write(i);
    delay(50);
  }
  
  
  
  for(int i = 90 ; i>=0 ; i--)
  {
    servo_pan.write(i);
    delay(50);
  }
  
  for(int i = 0 ; i<=90 ; i++)
  {
    servo_pan.write(i);
    delay(50);
  }
  */
  
 ldr_sup_izq = analogRead(A0);
 ldr_sup_der = analogRead(A1);
 ldr_cen_cen = analogRead(A2);
 ldr_inf_izq = analogRead(A3);
 ldr_inf_der = analogRead(A4);
 
 //Condiciones de comparación
 
 if (ldr_sup_izq >ldr_sup_der && ldr_sup_izq >ldr_cen_cen && ldr_sup_izq >ldr_inf_izq && ldr_sup_izq >ldr_inf_der)
 {
   Serial.println("Mayor intensidad en el LDR superior izquierdo");
   
   digitalWrite(led_sup_izq , HIGH) ;
   digitalWrite(led_sup_der , LOW) ;
   digitalWrite(led_cen_cen , LOW) ;
   digitalWrite(led_inf_izq , LOW) ;
   digitalWrite(led_inf_der , LOW) ;
   
   if ( pos_tilt == 45){pos_tilt=10;servo_tilt.write(pos_tilt);}
   else{ pos_tilt=45;servo_tilt.write(pos_tilt);  }
   delay(1000);
   if ( pos_pan == 150 ){pos_pan=90;servo_pan.write(pos_pan);}
   else{ pos_pan =25 ; servo_pan.write(pos_pan);}
   delay(1000);
   
   
      
 } 
 else if (ldr_sup_der >ldr_sup_izq && ldr_sup_der >ldr_cen_cen && ldr_sup_der >ldr_inf_izq && ldr_sup_der >ldr_inf_der)
 {
   Serial.println("Mayor intensidad en el LDR superior derecho");
   digitalWrite(led_sup_izq , LOW) ;
   digitalWrite(led_sup_der , HIGH) ;
   digitalWrite(led_cen_cen , LOW) ;
   digitalWrite(led_inf_izq , LOW) ;
   digitalWrite(led_inf_der , LOW) ;
   
   if ( pos_tilt == 45){pos_tilt=10;servo_tilt.write(pos_tilt);}
   else{ pos_tilt=45;servo_tilt.write(pos_tilt);  }
   delay(1000);
   if ( pos_pan == 25 ){pos_pan=90;servo_pan.write(pos_pan);}
   else{ pos_pan =150 ; servo_pan.write(pos_pan);}
   delay(1000);
   
 }
 
 else if (ldr_cen_cen >ldr_sup_izq && ldr_cen_cen >ldr_sup_der && ldr_cen_cen >ldr_inf_izq && ldr_cen_cen >ldr_inf_der)
 {
   Serial.println("Mayor intensidad en el LDR central");
   digitalWrite(led_sup_izq , LOW) ;
   digitalWrite(led_sup_der , LOW) ;
   digitalWrite(led_cen_cen , HIGH) ;
   digitalWrite(led_inf_izq , LOW) ;
   digitalWrite(led_inf_der , LOW) ;
 }
 
 else if (ldr_inf_izq >ldr_sup_izq && ldr_inf_izq >ldr_sup_der && ldr_inf_izq >ldr_cen_cen && ldr_inf_izq >ldr_inf_der)
 {
   Serial.println("Mayor intensidad en el LDR inferior izquierdo");
   digitalWrite(led_sup_izq , LOW) ;
   digitalWrite(led_sup_der , LOW) ;
   digitalWrite(led_cen_cen , LOW) ;
   digitalWrite(led_inf_izq , HIGH) ;
   digitalWrite(led_inf_der , LOW) ;
   
   
   if ( pos_tilt == 45){pos_tilt=90;servo_tilt.write(pos_tilt);}
   else if ( pos_tilt == 10){pos_tilt=45;servo_tilt.write(pos_tilt);}
   else{ pos_tilt=90;servo_tilt.write(pos_tilt);  }
   delay(1000);
   
   if ( pos_pan == 150 ){pos_pan=90;servo_pan.write(pos_pan);}
   else{ pos_pan =25 ; servo_pan.write(pos_pan);}
   delay(1000);
   
   
 }
 else if (ldr_inf_der >ldr_sup_izq && ldr_inf_der >ldr_sup_der && ldr_inf_der >ldr_cen_cen && ldr_inf_der >ldr_inf_izq)
 {
   Serial.println("Mayor intensidad en el LDR inferior derecho");
   digitalWrite(led_sup_izq , LOW) ;
   digitalWrite(led_sup_der , LOW) ;
   digitalWrite(led_cen_cen , LOW) ;
   digitalWrite(led_inf_izq , LOW) ;
   digitalWrite(led_inf_der , HIGH) ;
   
   
   if ( pos_tilt == 45){pos_tilt=90;servo_tilt.write(pos_tilt);}
   else if ( pos_tilt == 10){pos_tilt=45;servo_tilt.write(pos_tilt);}
   else{ pos_tilt=90;servo_tilt.write(pos_tilt);  }
   delay(1000);
   if ( pos_pan == 25 ){pos_pan=90;servo_pan.write(pos_pan);}
   else{ pos_pan =150 ; servo_pan.write(pos_pan);}
   delay(1000);
   
   
 }
 
 else {Serial.println("ERROR DE LECTURA EN LDRS");}
 
 
 
}

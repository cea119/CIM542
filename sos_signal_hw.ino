void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite (13,HIGH); 
delay (500);
digitalWrite (13,LOW); 
delay (300);
digitalWrite (13,HIGH); 
delay (500);
digitalWrite (13,LOW); 
delay (300);
digitalWrite (13,HIGH); 
delay (500);
digitalWrite (13,LOW); 
delay (300);

// three long flashes 

digitalWrite (13,HIGH); 
delay (1500);
digitalWrite (13,LOW); 
delay (300);
digitalWrite (13,HIGH); 
delay (1500);
digitalWrite (13,LOW); 
delay (300);
digitalWrite (13,HIGH); 
delay (1500);
digitalWrite (13,LOW); 
delay (300);

// three short flashes again

digitalWrite (13,HIGH); 
delay (500);
digitalWrite (13,LOW); 
delay (300);
digitalWrite (13,HIGH); 
delay (500);
digitalWrite (13,LOW); 
delay (300);
digitalWrite (13,HIGH); 
delay (500);
digitalWrite (13,LOW); 
delay (3000); //final delay is 3 seconds 

}

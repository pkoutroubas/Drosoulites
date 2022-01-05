int twater=A5; // Analog input for the tank water level sensor
int twl=0;     
int tpump=5;   // output for the tank pump
int val;
int temp=A4;   // Analog input for temperature sensor
int pwater= A3; // Analog Input for pool water level sensor
int pbuttonPin = 2;  //Input for button to start the water pump.
int ppump =  3;  // Output for pool pump
int pwl=0;
int pflag=0;  // variable to trace the button
int pbuttonState = 0;   
void setup() {
Serial.begin(9600);
pinMode(tpump, OUTPUT);
pinMode(ppump, OUTPUT);
pinMode(pbuttonPin, INPUT);
}
void loop() {
// empty the pool
digitalWrite(ppump, LOW);
 digitalWrite (tpump, LOW);
 pwl=analogRead(pwater);
 Serial.println(pwl);
  pbuttonState = digitalRead(pbuttonPin);
  if (pbuttonState == HIGH) {

    // turn pool pump on:

    pflag=1;}

       while (pflag ==1 ) {
pwl=analogRead(pwater);
    digitalWrite(ppump, HIGH);
Serial.println(pwl);
Serial.println(pflag);
if (pwl<=260) {
 pflag=0;}
   
}
           

if (pflag==0) {digitalWrite(ppump, LOW);}

     
     

  //fire extinguishing
 digitalWrite (tpump, LOW);
twl=analogRead(twater);
Serial.print ("Water Level: ");
Serial.println(twl);
delay(500);
val= analogRead (temp);  
float mv= (val/1024.0)*5000;
float c=mv/10;
Serial.print("Temperature= ");
Serial.print(c);
Serial.print("oC");
Serial.println();
delay (500);

while ( twl > 200 && c > 45) {
 digitalWrite (tpump, HIGH); 
twl=analogRead(twater);
Serial.print ("tank Water Level: ");
Serial.println(twl);
Serial.println(pwl);

val= analogRead (temp);  
float mv= (val/1024.0)*5000;
float c=mv/10;
Serial.print("Temperature= ");
Serial.print(c);
Serial.print("oC");
Serial.println();

if (twl <100){
  digitalWrite (tpump, LOW);
}
}

  
}
 

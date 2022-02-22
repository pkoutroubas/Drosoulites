int pwater=A3; //Analog input to read the pool water level
int pbuttonpin=2; //input to read the button value
int ppump=3;// output to pool pump
int pwl=0; //pool water level
int pflag=0;// variable to trace and hold the button press
int pbuttonstate=0;


int water=A4;// Analog input to read the tank water level
int wl=0; //tank water level
int tpump=5;// output to tank pump
int val;
int temp=A1;// Analog input to  read the temperature
int fire=0; // variable used as a flag to trace fire
void setup() {
Serial.begin(9600);
pinMode(tpump, OUTPUT);
pinMode(ppump, OUTPUT);
pinMode(pbuttonpin, INPUT);

}
void loop() {
   digitalWrite (tpump, LOW);
   digitalWrite(ppump, LOW);
wl=analogRead(water);
//Serial.print ("Water Level: ");
//Serial.println(wl);
//delay(1000);
//val= analogRead (temp);  
//float mv= (val/1024.0)*5000;
//float c=mv/10;
//Serial.print("Temperature= ");
//Serial.print(c);
//Serial.print("oC");
//Serial.println();

//fire extinguishing
//if (c > 40) {
  
  //  delay(2000);
    //val= analogRead (temp);  
    //float mv= (val/1024.0)*5000;
//float c=mv/10;
  //  if (c > 40) {
    //  fire = 1;
    //}}
//if (c > 50) {fire=1;} // fire alarm
//while ( wl > 200 && fire ==1) {
//  digitalWrite (tpump, HIGH); 
//wl=analogRead(water);
//Serial.print ("Water Level: ");
//Serial.println(wl);
//delay(500);
//val= analogRead (temp);  
//float mv= (val/1024.0)*5000;
//float c=mv/10;
//Serial.println(c);
//Serial.println();

//if (wl <100){
 // digitalWrite (tpump, LOW);
//}
//}
//if (c < 30) {fire=0;}
  
//moving water from pool to the tank
pwl=analogRead(pwater);
 Serial.println(pwl);
  pbuttonstate = digitalRead(pbuttonpin);
  if (pbuttonstate == HIGH) {

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
}
 

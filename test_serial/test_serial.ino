
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(8, OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  char getdata='c';
  digitalWrite(8, LOW);
  digitalWrite(13, LOW);
  
  if(Serial.available()){
    getdata = Serial.read();
  }
  delay(200);  
  if(getdata == '9'){
    digitalWrite(8, HIGH); 
    digitalWrite(13, HIGH); 
    String values = readSensors();
    Serial.println(values);
  }
  delay(2000);  
}
String readSensors(){
 return "{'peso':'50'}"; 
}

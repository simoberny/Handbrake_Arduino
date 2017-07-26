int init_min = 0;
int max_read = 0;

void setup(){
  Serial.begin(115200);
  init_min = analogRead(A0);
  pinMode(A0, INPUT);
}

void loop(){
  int pot = analogRead(A0);
  
  if(pot > max_read){
    max_read = pot;
  }
  
  int mapped = map(pot,init_min,max_read,0,32727);

  if(mapped < 0){
    mapped = 0;
  }
  
  delay(25);
  Serial.println(mapped);
}

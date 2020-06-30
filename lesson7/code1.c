void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}
  byte income=0;
void loop()
{
  int i=0;
  for(i;i<11;i++){
    income=i;
    digitalWrite(5,HIGH);
    digitalWrite(1,income&0x1);
    digitalWrite(2,(income>>1)&0x1);
    digitalWrite(3,(income>>2)&0x1);
    digitalWrite(4,(income>>3)&0x1);
  	delay(10);
  if(i=10){i=0;}}
}
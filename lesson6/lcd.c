#include <LiquidCrystal.h>
void lcd_init();
void lcd_write_cmd(byte);
void lcd_write_data(byte);
void set_data(byte);
int en=11;
int rs=12;
int d0=9;
int d1=8;
int d2=7;
int d3=6;
int d4=5;
int d5=4;
int d6=3;
int d7=2;

void setup() {
  pinMode(en,OUTPUT);
  pinMode(rs,OUTPUT);
  pinMode(d0,OUTPUT);
  pinMode(d1,OUTPUT);
  pinMode(d2,OUTPUT);
  pinMode(d3,OUTPUT);
  pinMode(d4,OUTPUT);
  pinMode(d5,OUTPUT);
  pinMode(d6,OUTPUT);
  pinMode(d7,OUTPUT);
  
  
  lcd_init();
  lcd_write_cmd(0x80);
  lcd_write_data(0x61);
  lcd_write_cmd(0x81);
  lcd_write_data(0x62);
  lcd_write_cmd(0x82);
  lcd_write_data(0x63);
  lcd_write_cmd(0x83);
  lcd_write_data(0x64);
}

void loop() {
  
}

void lcd_init(){
  delay(15);
  digitalWrite(rs,LOW);
  digitalWrite(en,LOW);
  lcd_write_cmd(0x38);
  delay(5);
  lcd_write_cmd(0x38);
  lcd_write_cmd(0x08);
  lcd_write_cmd(0x01);
  lcd_write_cmd(0x06);
  lcd_write_cmd(0x0c);
}

void lcd_write_cmd(byte c){
  digitalWrite(rs,LOW);//写命令，所以RS为1
  write_data(c);
}

void lcd_write_data(byte d){
  digitalWrite(rs,HIGH);//写数据，所以RS为0
  write_data(d);
}

void write_data(byte c)
{
  //1.en为高
  digitalWrite(en,HIGH);
  delay(1);
  //2. 数据线放置数据
  
  digitalWrite(d0,c&0x1);
  digitalWrite(d1,(c>>1)&0x1);
  digitalWrite(d2,(c>>2)&0x1);
  digitalWrite(d3,(c>>3)&0x1);
  digitalWrite(d4,(c>>4)&0x1);
  digitalWrite(d5,(c>>5)&0x1);
  digitalWrite(d6,(c>>6)&0x1);
  digitalWrite(d7,(c>>7)&0x1);
  delay(1);
  
  //3. 数据放好后，en为低，将数据写指定寄存器
  digitalWrite(en,LOW);
  delay(1);
}

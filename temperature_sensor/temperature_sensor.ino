#include <LiquidCrystal.h>


int thermPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16,2);
 // DHT dht (7,DHTTYPE);
  Serial.begin(9600);
}

void loop(){
  Vo = analogRead(thermPin);
  R2 = R1*(1023.0/(float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T-273.15;
  Tf = (Tc * 9.0)/5.0 + 32.0;


/*
  T_dht = dht.readTemperature();
  H_dht = dht.readHumidity();
  H_idx = dht.computeHeatIndex(T_dht, H_dht);


  lcd.setCursor(0,0);
  lcd.print("T=");
  lcd.setCursor(2,0);
  lcd.print(T_dht);
  lcd.setCursor(4,0);
  lcd.print("*C ");
  lcd.setCursor(0,1);
  lcd.print("H=");
  lcd.setCursor(2,1);
  lcd.print(H_dht);
  lcd.setCursor(4,1);
  lcd.print("% ");
  lcd.setCursor(8,1);
  lcd.print("HI=");
  lcd.print(H_idx);
  */
  

  
  lcd.print("Temp: ");
  //lcd.print(Tf);
  //lcd.print(" F; ");
  lcd.print(Tc);
  lcd.print(" *C");
  


  delay(500);
  lcd.clear();
}

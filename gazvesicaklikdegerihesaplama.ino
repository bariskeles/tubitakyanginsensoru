int esikDegeri = 500; //Gaz eşik değerini belirliyoruz.    
int buzzerPin = 2; //Buzzerın takılacağı pin
int led=3; // ledin takılacağı pin
int gdeger; //Sensörden okunan gaz değeri
int sdeger=0; // sıcaklık sensörünün takılı olduğu pin
float sicaklik_gerilim=0;
float sicaklik=0;

void setup() {
  pinMode(buzzerPin, OUTPUT); //Buzzer pinimizi çıkış olarak ayarlıyoruz.
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  gdeger = analogRead(A2); //Sensörden gelen gaz değerini oku.
  sdeger = analogRead(A0); // sıcaklık sensörünün veri çekeeceği analog pini belirledk
  sicaklik_gerilim=(5000.0/1023.0)* sdeger;
  sicaklik= sicaklik_gerilim/100.0;

  if ((gdeger >= esikDegeri) || (sicaklik >=50) ) { //Sensörden okunan değer eşik değerinden büyükse çalışır.
    Serial.print("Gaz değeri: ");
    Serial.println(gdeger);
    Serial.print("Sıcaklık = ");
    Serial.print(sicaklik); // Seri port ekranına sıcaklığı yazdır
    Serial.println(" °C");
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(led, LOW);
    delay(1000);
  } 
   
  else
   { //Sensörden okunan değer eşik değerinin altındaysa çalışır.
    Serial.print("Gaz değeri: ");
    Serial.println(gdeger);
    Serial.print("Sıcaklık = ");
    Serial.print(sicaklik); // Seri port ekranına sıcaklığı yazdır
    Serial.println(" °C");
    Serial.println(" Problem yok.");
    delay(1000);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(led, LOW);
  }
}
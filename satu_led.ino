int pinLED1 =10;
// Mendefinisikan Pin Tirg dan Echo Pada Sensor Ultrasonik
const int trigPin = 6;
const int echoPin = 5;
// Variabel Waktu "duration" dan Jarak "distance"
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Mengatur trigPin Untuk Output
  pinMode(echoPin, INPUT); // Mengatur echoPin Untuk  Input
  pinMode(pinLED1,OUTPUT);
  Serial.begin(9600);
}
void loop() {
    distance = calculateDistance();
    // Pemanggilan Funsi Perhitungan Jarak pada Sensor Ultrasonik
    Serial.print("Distance:"); // Mengirim karakter tambahan tepat di sebelah nilai sebelumnya yang diperlukan nanti dalam Memproses IDE untuk pengindeksan
    Serial.println(distance); // Mengirim nilai jarak ke Port Serial
    Serial.print("."); // Mengirim karakter tambahan tepat di sebelah nilai sebelumnya yang diperlukan nanti dalam Memproses IDE untuk pengindeksan jika (jarak <= 2)
    delay(100);
    if (distance<10)
    {
      digitalWrite(pinLED1,HIGH);
    }
    else if (distance>=10 && distance <=30)
    {
      digitalWrite(pinLED1,LOW);
    }
  else  
     {
      digitalWrite(pinLED1,LOW);
      }
}
  int calculateDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Atur trigPin pada status TINGGI selama 10 detik mikro
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Mengatur trigPin pada status TINGGI untuk membaca echoPin, mengembalikan waktu tempuh gelombang suara dalam mikrodetik 10 mikro detik
  distance= duration*0.034/2;
  return distance;
}
delay(1000);

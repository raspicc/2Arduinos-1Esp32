#define RXp2 16
#define TXp2 17

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
}

void loop() {
  //Serial2.write("*IDN?\n");  // enviar el comando a través del puerto serial
  Serial2.write("Esclavo1\n");
  // esperar hasta que se reciba una respuesta
  while (!Serial2.available()) {
    delay(1000);
  }

  String response = Serial2.readString();  // leer la respuesta del puerto serial
  Serial.println(response);  // imprimir la respuesta en el monitor serie del ESP32
}

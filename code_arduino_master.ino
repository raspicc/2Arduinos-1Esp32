#include "Arduino.h"
#include "Vrekrer_scpi_parser.h"
#include <Wire.h>


SCPI_Parser my_instrument;

void setup()
{
  Wire.begin();
  my_instrument.RegisterCommand("*IDN?", &Identify);
  my_instrument.RegisterCommand(F("Esclavo#"), &WriteMovement);
  Serial.begin(9600);

}

void loop()
{
  my_instrument.ProcessInput(Serial, "\n");
}

void Identify(SCPI_C commands, SCPI_P parameters, Stream& interface) {
  interface.println(F("Hcal ,Arduino Master Instrument ,#00,v1.0.0"));
}



void WriteMovement(SCPI_C commands, SCPI_P parameters, Stream& interface) {
  String header = String(commands.Last());
  header.toUpperCase();
  int suffix = -1;
  sscanf(header.c_str(),"%*[ESCLAVO]%u", &suffix);
  String first_parameter = String(parameters.First());
  first_parameter.toUpperCase();
  if(suffix==1){
      int estado = 1;
      int estado1;
      // transmite al esclavo 1
      Wire.beginTransmission(1);
      Wire.write(estado);
      Wire.endTransmission();

      
      // Solicita información al esclavo 1
      Wire.requestFrom(1, 1);
      while(Wire.available()){
        estado1 = Wire.read();
      }

      delay(1000);
      estado = 0;
      // transmite al esclavo 1
      Wire.beginTransmission(1);
      Wire.write(estado);
      Wire.endTransmission();

      // Solicita información al esclavo 1
      Wire.requestFrom(1, 1);
      while(Wire.available()){
        estado1 = Wire.read();
      }
      interface.println("información cualquiera que desee enviar al esp32");
    }
}

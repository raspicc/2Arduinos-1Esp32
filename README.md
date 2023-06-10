# Communication between two arduinos uno and an esp32

Los códigos proporcionados enciende y apaga un led usando el pin 10 del arduino esclavo.

![image](https://github.com/raspicc/2Arduinos-1Esp32/assets/61076206/a33a86a9-f9f2-4858-b351-599593c16c68)

Mediante comunicación serial entre ESP32 y un Arduino Uno maestro se logró controlar varios Arduinos Uno esclavos.
La idea de este proyecto es que cada arduino uno esclavo sea el encargado de administrar todos los parámetros de un experimento, es decir a cada arduino esclavo se le asignará un experimento.

El arduino maestro actuará de intermediario para que el esp32 logré gestionar los distintos experimentos.
El esp32 podrá conectarse a internet y enviar los datos de cada experimento.

![image](https://github.com/raspicc/2Arduinos-1Esp32/assets/61076206/f93cae9b-1708-410a-9824-f268075812b4)

Se ha planteado este esquema para los experimentos remotos y así optimizar el uso de hardware ya que bastará usar solo un esp32.


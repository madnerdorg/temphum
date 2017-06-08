[Version française / French version](https://github.com/madnerdorg/temphum/blob/master/README.fr.md)

![Photo temphum](https://github.com/madnerdorg/temphum/raw/master/doc/temphum_device.jpg)   
temphum is an USB device based on an Arduino nano (clone) to get temperature/humidity data.

# Components
* Arduino nano CH340G: 2€
* DHT11 : 2€
* Resistor pack 400pcs (3€) (1 resistor: 0.0071€)
* Total : 6€ (4€) 

# Usage
* Copy **libraries/temphum** into Arduino Sketchbooks folder
* Upload temphum/temphum.ino
* Go to http://madnerd.org/interface/temphum

# Wiring
You need to add a resistor between 5v/pin 2.

![Wiring_temphum](https://github.com/madnerdorg/temphum/raw/master/doc/dht11_nano.jpg)

* Arduino - 2 : DATA (2) 
* Arduino - 2 : RESISTOR (4,7kΩ) --> VCC (1)
* Arduino - 5v : VCC (1)
* Arduino - GND : GND (4)

# 3D printing
Models by Olivier Sarrailh : https://github.com/madnerdorg/temphum/tree/master/stl  

# Commands available
* /info -------> Give name:port (temphum:42004)
* Once /info is sent , the device will send humidity(%);temp(°c) (for ex:50.00;24.00)

# Licences

## temphum.ino
* Author: Rémi Sarrailh (madnerd.org)       
* Licence: MIT   

## DHT_sensor_library
* Author : Tony DiCola (Adafruit Industries)
* Licence : MIT
* Link : https://github.com/adafruit/DHT-sensor-library


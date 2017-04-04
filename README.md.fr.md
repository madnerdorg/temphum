[English version](https://github.com/madnerdorg/temphum/)

![Photo temphum](https://github.com/madnerdorg/leds/raw/master/doc/temphum_device.jpg)   
temphum est un appareil USB fait à partir d'un arduino nano (clone) pour obtenir les données de température et d'humidité.

# Composants
* Arduino nano CH340G: 2€
* DHT11 : 2€
* Resistor pack 400pcs (3€) (1 resistor: 0.0071€)
* Total : 6€ (4€) 

# Utilisation
    * Copier **libraries/temphum** dans le carnet de croquis Arduino
    * Téléverser **temphum/temphum.ino**
    * Aller sur [TODO]

# Branchement
Vous devez mettre une résistance qui relie la broche 2 avec le 5v

![Wiring_temphum](https://github.com/madnerdorg/temphum/raw/master/doc/dht11_nano.jpg)

* Arduino - 2 : DATA (2) 
* Arduino - 2 : RESISTANCE (4,7kΩ) --> VCC (1)
* Arduino - 5v : VCC (1)
* Arduino - GND : GND (4)

# Modèle 3D
Modèle fait par Olivier Sarrailh : https://github.com/madnerdorg/temphum/tree/master/3D    

# Commandes disponibles
* /info -------> Affiche nom:port (temphum:42004)
* Une fois /info envoyé , le périphérique va envoyé humidité(%);temp(°c) (par ex:50.00;24.00)

# Licenses

## temphum.ino
* Auteur: Rémi Sarrailh (madnerd.org)       
* License: MIT   

## DHT_sensor_library
* Auteur : Tony DiCola (Adafruit Industries)
* License : MIT
* Lien : https://github.com/adafruit/DHT-sensor-library

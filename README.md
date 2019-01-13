# Foodcomputer
The goal of this project is to use Arduino and Raspberry Pi to fetch, store, and display sensor data from the aquaponic farm in the NYU makerspace and makershed. The arduino microcontroller is recording data of an underwater temperature sensor, CO2 sensor, air temperature and humidity sensor, water PH sensor, and water EC meter. This data is sent to the raspberry pi using arduino serial communication. The data is then (to be) displayed on graphs that allow manual input of data that cannot be measured using sensors by students working on the farm. Live graphs will also be displayed. The goal of this project is to completed by Late April 2019.
## Documentation
This repo contains all the necessary information and resources, as well as progress and updates on the food computer.
## Arduino Configuration
  A "genuino" is currently operating in the place of a genuine arduino uno, as confusing as that sounds. The microcontroller was programmed using the arduino IDE. The code uploaded is contained inside the 'sensor_read.ino' file. The following libraries were installed after being downloaded fromt the below github repositories:
 - Adafruit_Sensor (used for adafruit temperature and humidity sensors): https://github.com/adafruit/Adafruit_Sensor
 - Arduino Library for Maxim Temperature Integrated Circuits (DallasTemperature; used for underwater temperature sensor): https://github.com/milesburton/Arduino-Temperature-Control-Library
 - One Wire Library (also used for underwater temperature sensor): https://github.com/PaulStoffregen/OneWire

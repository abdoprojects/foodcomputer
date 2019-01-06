/***************************************************
 * Infrared CO2 Sensor0-5000ppm 
 * ****************************************************
 * This example The sensors detect CO2
 * 
 * @author lg.gang(lg.gang@qq.com)
 * @version  V1.0
 * @date  2016-7-6
 * 
 * GNU Lesser General Public License.
 * See <http://www.gnu.org/licenses/> for details.
 * All above must be included in any redistribution
 * ****************************************************/
// importing libraries and defining 
#include <OneWire.h> //library for water temp
#include <DallasTemperature.h> //library for water temp
#include <Adafruit_Si7021.h>
#include <DHT.h>
//
#define DHTPIN 3 // digital input for temp/humid
#define DHTTYPE DHT22 // temp/humid sensor model
#define ONE_WIRE_BUS 2 // digital input for water temp
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

int co2SensorIn = A0;
int phSensorIn = A1;
//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup(){  
  Serial.begin(9600);
  // Set the default voltage of the reference voltage
  analogReference(DEFAULT); 
}

void loop(){ 
  //Read voltages
  int co2SensorValue = analogRead(co2SensorIn);  
  
  // The analog signal is converted to a voltage 
  float co2Voltage = co2SensorValue *(5000/1024.0);
  
  //display co2 value and voltage
  if(co2Voltage == 0) {
    Serial.println("Fault");
  }
  else if(co2Voltage < 400) {
    Serial.println("preheating");
  }
  else {
    int voltage_diference = co2Voltage-400;
    float concentration=voltage_diference*50.0/16.0;
    // Print Voltage
    Serial.print("voltage (co2):");
    Serial.print(co2Voltage);
    Serial.println("mv, ");
    //Print CO2 concentration
    Serial.print(concentration);
    Serial.println("ppm");
  }
  
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus 
  /********************************************************************/
  Serial.print(" Requesting temperatures..."); 
  sensors.requestTemperatures(); // Send the command to get temperature readings 
  Serial.println("DONE"); 
  /********************************************************************/
  Serial.print("Temperature is: "); 
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?
  Serial.print("C");
  Serial.print('\n');
  // You can have more than one DS18B20 on the same bus.  
  // 0 refers to the first IC on the wire

  //display for humidity and temperature
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
  delay(1000);
  
  
  delay(2000);
}

// Prueba de Sensor de Temperatura y Humedad DHT
// Autor: Oscar Núñez Mori, 23 Feb. 2024. Jaén-PERÚ
// Basado en Ejmplo  Adafruit(s.f.) DHT Sensor Library.
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

#define DHTPIN 2     // Pin del Sensor.
// #define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Pin 1 del Sensor (Izquierda) a +5V. en Arduino Nano 3.x
// Pin 2 del Sensor (Medio) a DHTPIN en este caso pin 2
// Pin 3 del sensor (Derecha) a Tierra
// Poner resistencia de 10k entre pin 2 (data) y pin1 (Vcc)
// Initialize DHT sensor.

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Probando el Sensor DHT! \n");
  dht.begin();
}

void loop() {
  // Esperando unos segundos entre mediciones
  delay(2000);

  // La lectura de la temperatura o humedad toma 250 milisegundos
  // La lectura del sensor pueden tomar hasta 2 segundos
  float h = dht.readHumidity(); // Lectura humedad
  float t = dht.readTemperature(); // Lectura Temperatura en Celsius por defecto
  // Read temperature as Fahrenheit (isFahrenheit = true)
  // float f = dht.readTemperature(true);

  // Verifica lecturas si falla vuelve a intentar.
  if (isnan(h) || isnan(t)) {
    Serial.println("Falla de lectura del Sensor!\n");
    return;
  }

  // Calcula indice de calor en Fahrenheit por defecto
  //float hif = dht.computeHeatIndex(f, h);
  // Calculo de calor en Celcius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %. \n");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" gC. \n");
  Serial.print("Sensacion Termica: ");
  Serial.print(hic);
  Serial.print(" gC.\n");
  Serial.print("\n \n");
}

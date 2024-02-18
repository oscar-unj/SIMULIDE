/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/

// Modificado por Oscar NÚÑEZ MORI

int pot = 14;     // Pin Central  del Potenciómetro. (Entrada Analogia A0)
int led = 2;      // select the pin for the LED
int valorPot = 0;  // Variable almacenada proveniente del Potenciometro

void setup() {
  // led como salida (OUTPUT)
  pinMode(led, OUTPUT);
}

void loop() {
  // Lee valor del potenciometro.
  valorPot = analogRead(pot);
  // Prende el led
  digitalWrite(led, HIGH);
  // ValorPot en milisegundos.
  delay(valorPot);
  // Apaga el led.
  digitalWrite(led, LOW);
  // ValorPot en milisegundos.
  delay(valorPot);
}
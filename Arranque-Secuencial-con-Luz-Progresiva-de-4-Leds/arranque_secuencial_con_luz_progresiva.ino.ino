// Arranque Secuencial con luz progresiva de 4 leds.
// Autor: Oscar Núñez Mori. 23 Feb. 2024. Jaén-PERÚ
//
// Basado en OpenAI (2024, Feb 23). ChatGPT 3.5. 
// [Arranque Secuencial con Luz Progresiva de 4 Leds]
// https://chat.openai.com/share/9775c2be-5fda-4c0a-a3e9-cbb5f5fe11a7


// Definir pines de los LEDs
const int ledPines[] = {2, 3, 4, 5};
const int numLeds = 4;

// Definir los pines de los pulsadores
const int encenderPulsadorPin = 7;
const int apagarPulsadorPin = 8;

// Variable para el estado de los LEDs
int estadoLeds[numLeds] = {0};

// Variables para el estado de los pulsadores
int estadoEncenderPulsadorAnterior = HIGH;
int estadoEncenderPulsadorActual = HIGH;
int estadoApagarPulsadorAnterior = HIGH;
int estadoApagarPulsadorActual = HIGH;

// Variable para controlar si todos los LEDs están encendidos
bool todosLedsEncendidos = false;

void setup() {
  // Configurar pines de LEDs como salidas
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPines[i], OUTPUT);
  }

  // Configurar pines de pulsadores como entradas
  pinMode(encenderPulsadorPin, INPUT);
  pinMode(apagarPulsadorPin, INPUT);

  // Apagar todos los LEDs al inicio
  for (int i = 0; i < numLeds; i++) {
    analogWrite(ledPines[i], 0);
  }
}

void loop() {
  // Leer el estado actual de los pulsadores
  estadoEncenderPulsadorActual = digitalRead(encenderPulsadorPin);
  estadoApagarPulsadorActual = digitalRead(apagarPulsadorPin);

  // Verificar si el pulsador de encendido ha sido presionado
  if (estadoEncenderPulsadorActual == LOW && estadoEncenderPulsadorAnterior == HIGH) {
    // Verificar si todos los LEDs están apagados
    if (!todosLedsEncendidos) {
      // Encender LEDs de manera secuencial y progresiva
      for (int i = 0; i < numLeds; i++) {
        for (int nivel = 0; nivel <= 255; nivel++) {
          analogWrite(ledPines[i], nivel);
          delay(10);
        }
      }

      // Marcar que todos los LEDs están encendidos
      todosLedsEncendidos = true;
    }
  }

  // Verificar si el pulsador de apagado ha sido presionado
  if (estadoApagarPulsadorActual == LOW && estadoApagarPulsadorAnterior == HIGH) {
    // Apagar todos los LEDs
    for (int i = 0; i < numLeds; i++) {
      analogWrite(ledPines[i], 0);
    }

    // Habilitar nuevamente el pulsador de arranque
    todosLedsEncendidos = false;
  }

  // Actualizar estado de los pulsadores
  estadoEncenderPulsadorAnterior = estadoEncenderPulsadorActual;
  estadoApagarPulsadorAnterior = estadoApagarPulsadorActual;
}

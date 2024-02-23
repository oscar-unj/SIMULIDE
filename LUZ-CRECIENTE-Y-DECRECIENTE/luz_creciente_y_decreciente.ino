// Luz Creciente y Decreciente 
// Placa Arduino Nano 3.x
// Autor: Oscar Núñez Mori,  23-Feb. 2024. Jaén-PERÚ.
// Basado en OpenAI (2024, Feb 24) ChatGPT 3.5 [Luz Creciente y Decreciente]
// https://chat.openai.com/share/a84852ac-8d4e-42ba-a9bf-14f5a262d3ba


const int led = 6;  // Pin del LED
const int pulsador = 14; // Pin A0 del pulsador

int brillo = 0;  // Nivel de brillo del LED

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pulsador, INPUT_PULLUP);
}

void loop() {
  // Verificar si el pulsador está presionado
  if ( digitalRead(pulsador) == LOW) {
    // Incrementar el brillo mientras se mantiene presionado el pulsador
    brillo = brillo + 5;
    if (brillo > 255) {
      brillo = 255;  // Limitar el brillo máximo a 255
    }
    analogWrite(led, brillo);
    delay(50);  // Pausa para evitar rebotes
  } else {
    // Decrementar el brillo mientras se mantiene suelto el pulsador
    brillo = brillo - 5;
    if (brillo < 0) {
      brillo = 0;  // Limitar el brillo mínimo a 0
    }
    analogWrite(led, brillo);
    delay(50);  // Pausa para evitar rebotes
  }
}

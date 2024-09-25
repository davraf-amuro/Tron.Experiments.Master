#include "led_facade.h"

void FlashingLed() {
  // Ottieni il tempo corrente
  unsigned long currentMillis = millis();

  // Controlla se è passato l'intervallo di tempo
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Leggi lo stato attuale del LED
    int ledState = digitalRead(LED_FLASHING);

    // Cambia lo stato del LED
    if (ledState == LOW) {
      digitalWrite(LED_FLASHING, HIGH);
      Serial.println("LED acceso");
      oledDecorator.SetRow2("LED acceso");
    } else {
      digitalWrite(LED_FLASHING, LOW);
      Serial.println("LED spento");
      oledDecorator.SetRow2("LED spento");
    }
  }
}
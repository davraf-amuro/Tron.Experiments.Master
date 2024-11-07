#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <esp_now.h>
#include "config.h" //parametri globali
#include "lan_facade.h"
#include "led_facade.h"
#include "espnow_facade.h"

unsigned long previousMillis = 0; // Memorizza l'ultimo tempo in cui il LED è stato aggiornato
const long interval = 1000; // Intervallo di tempo per il lampeggio del LED (1 secondo)
String macAddress; // Puntatore a char per memorizzare l'indirizzo MAC
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET);
OledDecorator oledDecorator(display);

void setup() {
    Serial.begin(115200); // Inizializza la comunicazione seriale

    //-------------------- Inizializzazione display OLED --------------------
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }
    Serial.println("Display inizializzato");
    // display.display();
    // delay(1000);
    // display.clearDisplay();
    oledDecorator.setRow1("Display Inizializzato");
    oledDecorator.render();

    //-------------------- Inizializzazione ESP-NOW --------------------
    WiFi.mode(WIFI_STA);
    Serial.println("WiFi inizializzato in modalità STA");
    if (esp_now_init() != ESP_OK) {
        Serial.println("Errore durante l'inizializzazione di ESP-NOW");
        return;
    }
    // Registra le funzioni di callback
    esp_now_register_recv_cb(OnDataRecv);
    esp_now_register_send_cb(OnDataSent);
    Serial.println("ESP-NOW inizializzato");
    oledDecorator.setRow2("ESP-NOW inizializzato");
    oledDecorator.render();

    // pinMode(LED_FLASHING, OUTPUT);

    // // Ottieni l'indirizzo MAC del dispositivo
    // Serial.println("Accedo ai dati di rete");
    // macAddress = GetMacAddress();
    // Serial.println("Mac Address:" + macAddress);
    // oledDecorator.setRow1("MA:" + macAddress);
    // // oledDecorator.setRow2("Riga 2");
    // // oledDecorator.setRow3("Riga 3");
    // oledDecorator.setRow4("-davraf-");
    // oledDecorator.render();

    // // Imposta il cursore nella posizione (x, y)
    // display.setCursor(0, 0);
    // // Imposta la dimensione del testo
    // display.setTextSize(1);
    // // Imposta il colore del testo
    // display.setTextColor(SSD1306_WHITE);
    // // Scrivi il testo "ciao"
    // display.print("ciao");
    // // Visualizza il testo sul display
    // display.display();
    // delay(3000);

    // display.setCursor(0, 20);
    // // Imposta la dimensione del testo
    // display.setTextSize(1);
    // // Imposta il colore del testo
    // display.setTextColor(SSD1306_WHITE);
    // // Scrivi il testo "ciao"
    // display.print("bello");
    // // Visualizza il testo sul display
    // display.display();
}

void loop() {
    Serial.println("Ciao");

    oledDecorator.setStyle(OledDecorator::Style::STYLE_4ROWS);
    oledDecorator.setRow3("");
    oledDecorator.setRow4("Ciao");
    oledDecorator.render();
    delay(1000);
    oledDecorator.setRow4("");
    oledDecorator.setRow3("Ciao");
    oledDecorator.render();
    delay(1000);

    oledDecorator.setStyle(OledDecorator::Style::STYLE_2ROWS);
    oledDecorator.render();
    delay(2000);
    // FlashingLed();
    
    // // Esempio di invio dati
    // struct_message outgoingMessage;
    // strcpy(outgoingMessage.a, "I am the MASTER!");
    // outgoingMessage.b = 123;
    // outgoingMessage.c = 45.67;
    // outgoingMessage.d = true;

    // // Indirizzo MAC del destinatario (sostituisci con l'indirizzo corretto)
    // uint8_t broadcastAddress[] = {0xEC, 0x64, 0xC9, 0x86, 0x1A, 0x2C}; //EC:64:C9:86:1A:2C

    // esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &outgoingMessage, sizeof(outgoingMessage));

    // if (result == ESP_OK) {
    //     Serial.println("Invio riuscito");
    //     oledDecorator.setRow3("ESP-NOW inviato");
    // } else {
    //     Serial.println("Errore durante l'invio");
    //     oledDecorator.setRow3("ESP-NOW errore");
    // }

    // oledDecorator.render();
}


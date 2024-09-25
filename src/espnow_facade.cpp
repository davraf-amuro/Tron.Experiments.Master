#include "espnow_facade.h"

struct_message incomingMessage;
esp_now_peer_info_t peerInfo;
static char macReceiver[18];

// Callback per la ricezione dei dati
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {
    memcpy(&incomingMessage, data, sizeof(incomingMessage));
    snprintf(macReceiver, sizeof(macReceiver), "%02X:%02X:%02X:%02X:%02X:%02X", 
             mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
    Serial.print("ESP-NOW incoming from: ");
    Serial.println(macReceiver);
    Serial.print("Bytes received: ");
    Serial.println(data_len);
    Serial.print("Char: ");
    Serial.println(incomingMessage.a);
    Serial.print("Int: ");
    Serial.println(incomingMessage.b);
    Serial.print("Float: ");
    Serial.println(incomingMessage.c);
    Serial.print("Bool: ");
    Serial.println(incomingMessage.d);
}

// Callback per l'invio dei dati
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.print("Last Packet Send Status: ");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
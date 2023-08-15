/* SENDER ESP8266 */

#define LED D0

void setup() {
    // Set baud rate, switch Rx/Tx pins to D7/D8
    Serial.begin(115200);
    Serial.swap();
    pinMode(LED, OUTPUT);
}

int i;
void loop() {
    // Create msg, and send using UART over Rx/Tx (D7/D8)
    String toPrint = "Hi ESP #2! " + String(i);
    Serial.println(toPrint);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    digitalWrite(LED, HIGH);
    i++;
}

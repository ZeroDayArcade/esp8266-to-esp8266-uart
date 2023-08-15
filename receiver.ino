/* RECEIVER ESP8266 */

// Create data buffer for messages up to 40 characters
char msgBuffer [40];
volatile byte indx;

// Set baud and switch Rx/Tx to D7/D8
void setup() {
    Serial.begin(115200);
    Serial.swap();
}

void loop() {
    // Listen for received UART data on Rx/Tx (D7/D8)
    if (Serial.available() > 0) {
        byte currentByte = Serial.read();
        if (indx < sizeof msgBuffer) {
            msgBuffer [indx++] = currentByte;

            // If end of message, send to dev computer
            if (currentByte == '\r') {
                String message = String(msgBuffer);
                Serial.swap();
                delay(200);
                Serial.println(message);
                delay(200);
                Serial.swap();
                delay(200);
                indx = 0;
            }
        }
    }
}

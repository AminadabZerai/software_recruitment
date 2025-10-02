

const uint8_t MOVE_INSTRUCTION = 0x1E; // Instruction code to move the servo to a specific position from the image

const uint16_t HIGH_SERVO_POS = 0x01FF; // 150 degrees
const uint16_t LOW_SERVO_POS = 0x0332;  // 240 degrees


long lastReadTime = 0;
const long READ_INTERVAL = 100; // Every 100 ms


int JOYSTICK_PIN = A2;  // Analog pin for joystick

void setup() {
  Serial.begin(19200);
}

void loop() {
    long currentTime = millis();
    if (currentTime - lastReadTime >= READ_INTERVAL) {
        lastReadTime = currentTime;
        int sensorValue = analogRead(JOYSTICK_PIN);

        uint16_t servo_pos = map(sensorValue, 0, 1023, LOW_SERVO_POS, HIGH_SERVO_POS);
        

        // Send the binary command: [Instruction] [Low Byte] [High Byte] from what I understood from the task description
        Serial.write(MOVE_INSTRUCTION);
        Serial.write(servo_pos & 0xFF); // Low byte 
        Serial.write((servo_pos >> 8)& 0xFF); // High byte
        
    }
}


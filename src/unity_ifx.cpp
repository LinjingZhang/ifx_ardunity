/**
 * @file unity_ifx.cpp
 * @brief IFX Unity Arduino Implementation
 * 
 * Arduino-specific implementation of Unity output functions and
 * test synchronization utilities.
 */

#include <Arduino.h>
#include "unity_ifx.h"

extern "C" {

/**
 * @brief Output a single character via Arduino Serial
 * 
 * Unity callback function to output characters to Arduino Serial port.
 * This allows Unity test results to be displayed on the Serial monitor.
 */
void putCharacter(char c) {
    Serial.print(c);
    Serial.flush();
}

/**
 * @brief Flush Arduino Serial output
 * 
 * Unity callback function to ensure all output is flushed to Serial.
 */
void flushCharacter(void) {
    Serial.flush();
}

/**
 * @brief Test synchronization via Serial communication
 * 
 * Reads from Serial until the test start marker "[@START_TEST@]" is received,
 * then echoes the message back. This allows coordination between the Arduino
 * and host system for automated testing.
 */
void readSerialAndRespond(void) {
    String s("");
    
    do {
        s = Serial.readString();
    } while (s.indexOf("[@START_TEST@]") == -1);
    
    Serial.println(s);
    Serial.flush();
}

/**
 * @brief Print array contents to Serial
 * 
 * Prints the contents of a uint8_t array in a formatted way for debugging.
 * Output format: "title : [value1, value2, value3, ]"
 */
void printArray(const char *title, volatile uint8_t *data, uint8_t quantity) {
    Serial.print(title);
    Serial.print(" : [");

    for (uint8_t i = 0; i < quantity; ++i) {
        Serial.print(data[i]);
        Serial.print(", ");
    }

    Serial.println("]");
    Serial.flush();
}

} // extern "C"
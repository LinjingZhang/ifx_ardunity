/**
 * @file unity_ifx.h
 * @brief IFX Unity Extensions for Arduino
 * 
 * This file provides IFX-specific extensions to the Unity testing framework
 * for Arduino environments, including custom test macros and output functions.
 */

#ifndef UNITY_IFX_H
#define UNITY_IFX_H

#define TEST_IFX(group, name)                                                                     \
    static void TEST_##group##_##name##_(void);                                                   \
    static void TEST_##group##_##name##_run(void);                                                \
    void TEST_##group##_##name##_run(void) {                                                      \
        UnityTestRunner(TEST_##group##_SETUP, TEST_##group##_##name##_, TEST_##group##_TEAR_DOWN, \
                        "TEST(" #group ", " #name ")", TEST_GROUP_##group, #name, __FILE__,       \
                        __LINE__);                                                                \
    }                                                                                             \
    void TEST_##group##_##name##_(void)


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Output a single character (Unity callback)
 * 
 * This function is called by Unity to output individual characters.
 * Implementation is platform-specific (Arduino Serial, etc.)
 * 
 * @param c Character to output
 */
void putCharacter(char c);

/**
 * @brief Flush output buffer (Unity callback)
 * 
 * This function is called by Unity to ensure all output is flushed.
 * Implementation is platform-specific.
 */
void flushCharacter(void);

/**
 * @brief Test synchronization function
 * 
 * Reads from Serial and responds when test start marker is received.
 * Used for coordinating test execution between Arduino and host.
 */
void readSerialAndRespond(void);

/**
 * @brief Print array contents to Serial
 * 
 * Utility function to print an array of uint8_t values for debugging.
 * 
 * @param title Title/label to print before the array
 * @param data Pointer to the array data
 * @param quantity Number of elements in the array
 */
void printArray(const char *title, volatile uint8_t *data, uint8_t quantity);


#ifdef __cplusplus
}
#endif

// Utility macros
#define MILLISECONDS_PER_SECOND 1000
#define MICROSECONDS_PER_SECOND 1000000
#define MICROS_TO_MILLISECONDS(us) ((unsigned long)((double)(us) / (double)MILLISECONDS_PER_SECOND))

#endif // UNITY_IFX_H
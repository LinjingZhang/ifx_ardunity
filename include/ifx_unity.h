/**
 * @file ifx_unity.h
 * @brief IFX Arduino Unity Testing Framework - Main Include File
 * 
 * This is the main header file for the IFX Arduino Unity testing framework.
 * Include this file to get access to all Unity testing functionality
 * optimized for Arduino environments.
 * 
 * @author IFX Arduino Unity Team
 * @version 1.0
 */

#ifndef IFX_UNITY_H
#define IFX_UNITY_H

// Standard C includes
#include <stdbool.h>

// Unity testing framework
#include "Unity/src/unity.h"
#include "Unity/extras/fixture/src/unity_fixture.h"

// IFX Unity configuration and extensions
#include "unity_config.h"
#include "unity_ifx.h"

/**
 * @brief Main test group macro for Arduino tests
 * 
 * Use this macro to define test groups that will run on Arduino.
 * 
 * @param group The test group name
 * @param name The individual test name
 * 
 * Example:
 * @code
 * TEST_IFX(MyGroup, ShouldDoSomething) {
 *     TEST_ASSERT_EQUAL(1, 1);
 * }
 * @endcode
 */
#define TEST_IFX(group, name) TEST_IFX_IMPL(group, name)

// Arduino-specific includes (only when compiling for Arduino)
#ifdef ARDUINO
    #include <Arduino.h>
#endif

#endif // IFX_UNITY_H
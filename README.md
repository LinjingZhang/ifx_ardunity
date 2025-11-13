# IFX Ardunity - Unity Testing Framework for Arduino

## Overview

IFX Ardunity provides a simple adapter layer to run Unity C testing framework in Arduino environments. It handles the Arduino-specific setup and allows you to write and run unit tests using Arduino CLI.

## Features

- Unity C testing framework integration
- Arduino Serial output for test results
- Simple build process with Arduino CLI


## Files

```
ifx_ardunity/
├── include/              # Public API headers
│   ├── ifx_unity.h     # Main include file (use this!)
│   ├── unity_ifx.h     # IFX Unity extensions
│   └── unity_config.h  # Unity configuration
├── src/                 # Implementation
│   └── unity_ifx.cpp   # Arduino Serial & sync functions
├── examples/            # Example projects
│   └── basic/          # Basic usage example
│       └── basic_test.ino
├── tests/              # Test cases
├── Unity/              # Unity framework (submodule)
├── Makefile           # Build system
└── README.md          # This file
```
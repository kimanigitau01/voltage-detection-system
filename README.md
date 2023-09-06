# Phase Failure Detection System for Three-Phase Induction Motors

This repository contains the code and documentation for a Phase Failure Detection System designed to monitor the operation of three-phase induction motors. The system is implemented using an Arduino and a set of push buttons, relays, LEDs, and a LiquidCrystal display to provide real-time feedback on the status of the motor phases.

## Overview

The Phase Failure Detection System is designed to detect if any of the three phases of a three-phase induction motor has failed. It monitors the status of each phase using push buttons and provides visual feedback on an LCD display. Additionally, it can activate a relay and an LED to signal a phase failure condition.

## Hardware Components

The following hardware components are used in this system:

- Arduino board (compatible with the LiquidCrystal library)
- LiquidCrystal display for visual feedback
- Push buttons (3) to simulate the status of each phase
- Relay to trigger an external action in the event of a phase failure
- LED to provide a visual indicator of the system's status

## Code Structure

The Arduino code is structured as follows:

- **Libraries**: The code uses the LiquidCrystal library for controlling the LCD display.

- **Pin Definitions**: Hardware pins are defined for push buttons, relay, LED, and the LCD.

- **Setup**: In the setup function, pin modes are set, the initial state of the relay and LED is configured, and the LCD display is initialized with a startup message.

- **Loop**: The main loop continuously reads the status of the three push buttons, calculates the state of the motor phases, and updates the LCD display accordingly. It also controls the relay and LED to indicate phase failure conditions.

- **State Function**: A separate function is used to calculate the overall state of the motor phases based on the status of the push buttons.

## Usage

1. Connect the hardware components as per the defined pin assignments in the code.
2. Upload the Arduino code to your Arduino board.
3. Open the serial monitor (if TEST_PROTOTYPE is defined) to monitor the push button states and calculated voltage state.
4. Observe the LCD display for real-time feedback on the status of the motor phases.
5. In the event of a phase failure, the relay is activated, and the LED is turned off.
...
## Circuit Diagram
The hardware for this project is as follows:
![img-to-circuit-diagram](img/Screenshot%20from%202023-09-06%2020-52-40.png)
[link-to-tinkerCAD-simulation](https://www.tinkercad.com/things/b8YAaqjXBGW?sharecode=0dbFyJwSw-gdwLExRLWjtMcC0cFYBktt-lLg3yy8B4o)
## Setup Procedure
click Here to find out more on [how to setup the project](debug-files/README.md)

## GitHub Repository

Find this code and documentation on [GitHub](https://github.com/kimanigitau01/voltage-detection-system.git)

## License

This project is open-source and available under the [MIT License](https://github.com/git/git-scm.com/blob/main/MIT-LICENSE.txt). Feel free to modify and use it according to your requirements.

## Author

- Peter Nyakoni
- Manasseh Gitau

Please feel free to contribute to this project by submitting issues or pull requests. Your feedback and contributions are greatly appreciated!

---


# IoT-Based Lift Monitoring Using KiwisIoT

## Project Overview

This project demonstrates an IoT-based lift monitoring system using the NodeMCU ESP8266 and KiwisIoT platform. The system monitors lift-related sensor data and sends the information to an online dashboard, allowing users to observe lift conditions remotely.

## Hardware Components

- NodeMCU ESP8266
- Sensors used for lift monitoring
- Jumper wires
- Power supply

## Software Requirements

- Arduino IDE
- ESP8266 Board Package
- Required Sensor Libraries
- KiwisIoT Arduino Library
- KiwisIoT Dashboard

## Circuit Connections

Connect the sensors to the NodeMCU ESP8266 according to the pin configuration used in the project.

## Working Principle

The sensors collect lift-related data and transmit it to the NodeMCU ESP8266. The controller processes the sensor readings and sends the information to the KiwisIoT platform through Wi-Fi.

The dashboard allows users to monitor lift-related parameters remotely and observe changes in the system through real-time data visualization.

## KiwisIoT Dashboard

- View live sensor readings.
- Monitor lift-related parameters remotely.
- Track sensor data through the dashboard.
- Visualize system information online.

## Configuration

Update your Wi-Fi credentials and KiwisIoT Topic ID in the project configuration.

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

## Applications

- Lift monitoring demonstrations
- Smart building systems
- Elevator condition monitoring
- IoT-based infrastructure monitoring
- Building automation

## Project Reference

**Hackster.io Project:**  
[IoT-Based Lift Monitoring Using KiwisIoT](https://www.hackster.io/harispidy07/iot-based-lift-monitoring-using-kiwisiot-ec951c)

**KiwisIoT Platform:**  
[https://kiwisiot.in/](https://kiwisiot.in/)

**KiwisIoT GitHub Repository:**  
[https://github.com/Kiwistron/KiwisIoT-Projects](https://github.com/Kiwistron/KiwisIoT-Projects)

## Author

**Hariprasath S**

GitHub: [https://github.com/harispidy07](https://github.com/harispidy07)

---

_Connecting lift monitoring systems with IoT-based remote visualization._

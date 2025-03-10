# Solar Panel Cleaning and Monitoring System

This project aims to automate the cleaning and monitoring of solar panels using ESP8266, ThingSpeak integration, and various sensors to ensure optimal performance.

## Features
- Automated solar panel cleaning mechanism
- Real-time environmental monitoring using sensors
- Data logging to ThingSpeak for analysis
- Wi-Fi connectivity for remote monitoring

## Hardware Components
- ESP8266 Wi-Fi Module
- DHT11 Sensor (Temperature & Humidity)
- ACS712 Sensor (Current Measurement)
- Dust Sensor
- LDR Sensor (Light Intensity Measurement)
- Motor Driver for Cleaning System

## Folder Structure
- **cleaning/**: Motor control code for forward, reverse, and stop functions
- **esp/**: ESP8266 code for Wi-Fi connection and HTTPS API request
- **monitoring/**: Sensor data collection and ThingSpeak integration

## Installation and Setup
### 1. Clone the Repository
git clone https://github.com/pranjalparmar23/Solar-Panel-Cleaning-and-Monitoring-System.git

### 2. Hardware Setup
- Connect the sensors and motor driver as per your circuit design.
- Ensure the ESP8266 module is configured with your Wi-Fi credentials.

### 3. Code Configuration
- Update the following credentials in the respective files:
  - **Wi-Fi Credentials:**
    #define STASSID "your-ssid"
    #define STAPSK "your-password"

  - **ThingSpeak Credentials:**
    const String apiKey = "YOUR_API_KEY";
    const String channelID = "YOUR_CHANNEL_ID";

### 4. Upload Code to ESP8266
- Use Arduino IDE to upload the provided ESP8266 code from the `esp/` folder.

### 5. Run the Cleaning System
- Upload the motor control code from the `cleaning/` folder to automate the cleaning mechanism.

## Usage
- The system will automatically read data from the sensors and send it to ThingSpeak.
- The cleaning mechanism will activate as programmed to ensure panel efficiency.

## Results
- Real-time data visualization on ThingSpeak.
- Enhanced solar panel efficiency through automated cleaning.

## Proposed System 
![unnamed](https://github.com/user-attachments/assets/1e34c2f1-8c93-4f50-84d3-6cc102fd159f)

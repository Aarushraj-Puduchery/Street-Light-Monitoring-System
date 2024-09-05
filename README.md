# Street-Light-Monitoring-System

The proposed system for street light monitoring and management harnesses the power of the Internet of Things (IoT) to address the limitations of traditional street lighting approaches. Conventional methods primarily rely on fixed schedules and basic control mechanisms, leading to challenges in adapting to diverse environmental conditions and varying usage patterns. These systems often struggle with inefficiencies, such as lights remaining on during periods of sufficient natural daylight or failing to adjust to changes in weather, traffic volumes, and emergencies. Additionally, the lack of real-time data collection and analysis hinders the ability of traditional systems to optimize energy use, reduce maintenance costs, and enhance public safety.

## Project Images

|![image](https://github.com/user-attachments/assets/bdc6600b-4531-4c8f-9c2d-aec4374b26c0)|![image](https://github.com/user-attachments/assets/04039a36-a11f-4fc1-b163-cc800ab05ce1)|
|---|---|

## Block Diagram
![Street Light Monitoring System Block Diagram](https://github.com/user-attachments/assets/d59b7a48-3edb-42d2-ac0a-544345b2201a)

## Schematic Diagram
![Schematic_smart-street-light-monitoring-system_2024-07-12](https://github.com/user-attachments/assets/59028d05-aa2e-4788-bf8f-89316146f1c2)

## PCB LAYOUT OF PROPOSED SYSTEM
![PCB_PCB_smart-street-light-monitoring-system_2024-07-12](https://github.com/user-attachments/assets/f47b74ca-d197-4f95-8743-04c572c69aab)

>[!NOTE]
>Check out this link: https://www.linkedin.com/posts/aarushraj-puduchery_single-layer-pcb-using-ironing-method-activity-7216661555927482368-7IlG?utm_source=share&utm_medium=member_android for how I made this PCB.

## Demo Video

## Software Used
### Arduino IDE
![image](https://github.com/user-attachments/assets/f5da6250-1279-42eb-8298-4ad95f68b64b)
### Google Firebase
![image](https://github.com/user-attachments/assets/1fe29400-da76-418a-b405-b10e70c72492)
### MIT App Inventor 2
![image](https://github.com/user-attachments/assets/dcf9b4cb-9016-440a-a44a-14ec0116871b)
### EASYEDA
![image](https://github.com/user-attachments/assets/cafd2047-b59e-4206-add5-6ccf5a451ca0)

## Components List
|S.No|  Name  | Cost | Quantity | Total Cost | Link |
|---| --- | --- | --- | --- | --- |
|1| NodeMCU ESP8266 AMICA CP2102 WiFi Development Board | ₹265.00 | 1 | ₹265.00 | https://robocraze.com/products/nodemcu-esp8266-amica-cp2102-driver?srsltid=AfmBOoogMvcexCtmSbWse7CRjlj3xKAwc4Z1z6Tf-QVRbGfN5wyhwVLc |
|2| Tiny RTC Real Time Clock DS1307 I2C IIC Module | ₹44.00 | 1 | ₹44.00 | https://robu.in/product/tiny-rtc-real-time-clock-ds1307-i2c-iic-module-for-arduino/ |
|3| CD74HC4067 16 Channel Multiplexer | ₹47.00 | 1 | ₹47.00 | https://www.electronicscomp.com/cd74hc4067-16-channel-multiplexer-breakout-board-module-india?gad_source=1&gclid=CjwKCAjw8diwBhAbEiwA7i_sJbTI_0htwSTLoZ-y8TKZmN8GVIqDA2loj_VPuERGRcLqPaKO2KgiRhoCEmwQAvD_BwE |
|4| SN74HC595N DIP16  | ₹25.00 | 1 | ₹25.00 | https://robu.in/product/sn74hc595n-dip16/?gad_source=1&gclid=CjwKCAjwreW2BhBhEiwAavLwfKoBFJ_23Bn5KDN6wh2gz5CmOH_B6LbxO2LP0kftHpQ2IwlCdJLXRhoC6VYQAvD_BwE |
|5| Yellow LED 5mm Diffused | ₹1.77 | 6 | ₹10.62 | https://www.electronicscomp.com/yellow-led-5mm-diffused-india?gad_source=1&gclid=CjwKCAjwreW2BhBhEiwAavLwfEKZqn70XbV5qivTH7jNCnR4E9VbRmuFl2wI0-HgR3Z_GR2AaKfENRoCVPkQAvD_BwE |
|6| 5mm LDR | ₹2.80 | 6 | ₹16.80 | https://robu.in/product/5mm-ldr-pack-of-10/ |
|7| Female Header pins | ₹20.00 | 5 | ₹100.00 | https://robu.in/product/2-54mm-1x40-pin-female-single-row-header-strip-pack-of-10/ |
|8| 220 resistor 1/4W | ₹0.50 | 16 | ₹8.00 | https://robu.in/product/220-ohm-resistor-0-25w-metal-film-pack-of-100/ |

> [!NOTE]
> Components price may vary.

## BLOCK CODE OF APK
### Main Screen Block
![image](https://github.com/user-attachments/assets/4d1963b8-9a4c-4af1-b34f-36285026e106)

### Interface Screen Block
![image](https://github.com/user-attachments/assets/ef8e9105-d4c9-4910-96b5-f1d988146c27)

### Admin Block Interface Blocks
![image](https://github.com/user-attachments/assets/c5df06f1-3d34-4241-ba56-95fa62b53a4c)

### ECE Block Interface Blocks
![image](https://github.com/user-attachments/assets/8c732269-fa9f-4fea-a791-41144fc555c4)

## Source Code
1. Install all the Libraries in the Libraries folder.
>[!IMPORTANT]
>in ...\Arduino\libraries\firebase-arduino-master\sr, open the 'FirebaseHttpClient.c' file and in line-43 replace the Firebase-Fingerprint with lastest one.
2. `StreetLight_monitoring_system.ino` file which is the main code.
>[!NOTE]
>before uploading make sure to change the wifi SSID and Password.
3. Install the Apk on your mobile.

## Working
The implementation of the IoT-based Street Light Monitoring System yielded significant results and insights into urban infrastructure management. The system's architecture diagram illustrates the integration of smart sensors, wireless communication modules, and centralized management software with existing street lighting infrastructure. This setup enabled real-time monitoring and dynamic control of street lights based on ambient conditions, traffic patterns, and environmental factors, as depicted in the real-time monitoring interface image.

|![image](https://github.com/user-attachments/assets/08e035a3-c3eb-4b6c-a385-1e24bf05adef)|
|---|

if there is any light not working, it will first indicate in the specific block interface, for example in Admin Block. it will send a send to a particular number and also the data is logged into google sheets with Block and light number.

|![image](https://github.com/user-attachments/assets/561fa25b-48e4-48d6-9c85-48f0a43fd729)| ![image](https://github.com/user-attachments/assets/94ba5efe-c1b4-410b-a8dc-9546dd285521)|
|---|---|

Also we can schedule the turning on and off of the lights and check the status of it using the main screen interface map

|![image](https://github.com/user-attachments/assets/3264957c-5c08-4878-ad53-c2e8ea8499c8)| ![image](https://github.com/user-attachments/assets/cbf9a3fc-4671-4749-a962-1e8f64b36f20)|
|---|---|

It is a Realtime Block Map where the Balls represent the Lights and when it is turned On, it is turns into Green and when Lights are Off, then it is turns into Red.

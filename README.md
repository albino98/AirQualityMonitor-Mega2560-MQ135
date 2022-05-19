# AirQualityMonitor-Mega2560-MQ135
Air quality monitor system with Mega2560 R3 board and MQ135 sensor.

## Connections

| Arduino Mega            | MQ-135  |
|---                      |---      |
| 5V                      | Vcc     |
| GND                     | GND     |
| A0                      | A0      |


| Arduino Mega            | Lcd     |
|---                      |---      |
| - Breadboard (gnd)      | K       |
| 5V                      | A       |
| 2                       | D7      |
| 3                       | D6      |
| 4                       | D5      |
| 5                       | D4      |
| 11                      | E       |
| - Breadboard (gnd)      | RW      |
|  12                     | RS      |
|  6                      | V0      |
| + Breadboard (5v)       | Vdd     |
| - Breadboard (bnd)      | Vss     |


| Arduino Mega            | DHT11   |
|---                      |---      |
| 29                      | Signal  |
| + Breadboard (5v)       | Vcc     |
| GND                     | GND     |


| Arduino Mega            |                       |   RGB Led   |
|---                      |---                    |---          |
| 39                      | 220 Ohm Resistor      |Red Pin      |
| GND                     |                       |Cathode (GND)|
| 37                      | 220 Ohm Resistor      |Green Pin    |
| 35                      | 220 Ohm Resistor      |Blu   Pin    |


| Arduino Mega            | Breadboard   |
|---                      |---           |
| GND                     | - (GND)      |
| 5V                      | + (Vcc)      |

<br/>
<br/>
<br/>


![immagine](https://user-images.githubusercontent.com/63566699/168480130-0ef0f336-6f63-43b6-8ace-ef48d2dd34be.png)

<br/>
<br/>

## Code

[Arduino Code](Mega2560-MQ135/Mega2560-MQ135.ino).

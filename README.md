# Smoke/Gas Leakage System


![Project Image](https://cdn.discordapp.com/attachments/861933527586177055/970639375337664522/National_Hamburger_Day_Banner_Landscape.jpg)

> This is a project real time gas/smoke/airquality monitoring system.

---

### Table of Contents
You're sections headers will be used to reference location of destination.

- [Description](#description)
- [How To Use](#how-to-use)
- [References](#references)
- [License](#license)
- [Author Info](#author-info)

---

## Description

There are two locations to monitor gas leakages, for example, the kitchen and storeroom. The state of each location can be updated to a web page as well a warning can be generated in each location in the form of visible as well as audible. Monitoring can be enabled and disabled by the same webpage(blynk). 

Each location can consist of a sensor to measure the air quality and two actuators (RGB LED and busser) to generate the warnings.

The RGB LED acts as follow:
- When the detection is disabled, LED is in blue color.
- When the system is on green indicates the normal condition while red indicates a gas leakage.

The buzzer act as a siren and depending on the degree of gas leakage, a suitable warning can be generated at least at three different levels.no beeps during non-leakages, short beeps for minor gas detections, and continuous beeps for the worst case.

 The web interface:
- There is webpage that indicate the state of both locations as well. In addition, a Webpage can be used to enable/disable the monitoring condition of each location.   


#### Technologies

- Arduino uno
- Arduino esp8266 nodemcu
- Blynk Libary
- 2 MQ2
- 2 HD11
- 2 Buzzer
- 2 RGB led

[Back To The Top](#read-me-template)

---

## How To Use

#### Installation



#### Additional Boards Manager URLs for esp6288
>Arduino - File - Preferences - Paste in Additional Boards Manager URLs Section.

```c++
    https://arduino.esp8266.com/stable/package_esp8266com_index.json
```
[Back To The Top](#read-me-template)

---

## References
- Arduino CC - (https://arduino.cc)
- Arduino Store - (https://store.arduino.cc/)
- Blynk - (https://blynk.cloud/)

[Back To The Top](#read-me-template)

---

## License

MIT License

Copyright (c) [2017] [James Q Quick]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

[Back To The Top](#read-me-template)

---

## Author Info

- Twitter - [@Hashx_official](https://twitter.com/Hashx_official)
- Discord - [Hash X](https://discord.gg/c8HjHVFkun)

[Back To The Top](#read-me-template)
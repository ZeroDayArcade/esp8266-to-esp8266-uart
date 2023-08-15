# esp8266-to-esp8266-uart
This code and corresponding tutorial explain how to communicate between two ESP8266 NodeMCU's via a wired UART connection rather than using WiFi. There are a number of reasons you might want to do this. For starters, you may not want to transmit all data between devices over WiFi. You may want each board to use its WiFi capabilities for a specific purpose like hitting an API, while you isolate the inter-board communication to a wired connection. Knowing how to do this also provides the basis for setting up wired communication between an ESP8266 NodeMCU and a digital device that has no native wireless capabilities, effectively giving it wireless network and internet access. 
<br/><br/>
Because both boards are the same and run on the same voltage, no resistors are needed, just female-to-female jumper wires for UART, and USB to Micro USB cables to power each board. Specifically, we'll be using the ESP8266 NodeMCU 1.0 (ESP-12E Module)
<br/><br/>

### Follow along the full tutorial: [Setting Up UART Communication Between Two ESP8266's](https://zerodayarcade.com/tutorials/hello-world-assembly-macos)

The full tutorial provides significantly more detail and additional diagrams. If you have any trouble running this demo, please see the full tutorial linked above. Follow the steps below to run the setup:
<br/><br/>


## Get the code
Clone this project:
```
git clone https://github.com/ZeroDayArcade/esp8266-to-esp8266-uart.git
```

## Flash both ESP8266's
Now open the Arduino IDE and flash both boards:
- Flash one board with `sender.ino`. This is now your **Sender ESP8266**

- Flash the other board with `receiver.ino`. This is now your **Receiver ESP8266**

We'll be wiring them together for 2-way UART communication so both can send and receive data to/from the other. But In this demo the **Sender ESP8266** will send messages to the **Receiver ESP8266** which will then relay those messages to your computer to view in the Arduino IDE Serial Monitor to confirm the communication.

## Wire the boards together
**With female-to-female jumper wires:**  
Connect D7 of sender to D8 of receiver  
Connect D8 of sender to D7 of receiver  
Connect GND of sender to GND of receiver (I would use GND next to D5)  

## Run the setup
Open the Serial Monitor in the Arduino IDE. With the Serial Monitor opened and both boards off, power on the **Sender ESP8266** with a seperate USB port/power source from the one the Serial Monitor is listening on. It's LED should now be blinking indicating it is sending messages. 

Now power on the **Receiver ESP8266** by connecting it to your dev computer with a USB to Micro USB cable. Connect it to the USB port the Serial Monitor *is* listening on. You should now see messages printing in the Serial Monitor:

![image](https://github.com/ZeroDayArcade/esp8266-to-esp8266-uart/assets/141867962/c5eca0e0-c62e-4a43-ac53-91ec33871398)

If you are seeing this, that means the UART communication between sender ESP8266 and receiver ESP8266 is working!
<br/>

## A lot more you can do with ESP8266 and UART
You can use UART communication like this from a ESP8266 to other devices as well. Here's an example of using an ESP8266 as a wireless adapter for a Game Boy Advance SP to give it access to the internet: [Video](https://youtu.be/_I2X50VyxGc)
<br/>

In this example the GBA is downloading a webpage from [https://example.com](https://example.com) The GBA also runs on 3.3V which makes the setup fairly straightforward.

<br/>

# More Zero Day Arcade Tutorials:
🎓  <a href="https://zerodayarcade.com/tutorials">zerodayarcade.com/tutorials</a> 

# Find Hacking Bounties in Gaming:
🎮  <a href="https://zerodayarcade.com/bounties">zerodayarcade.com/bounties</a>

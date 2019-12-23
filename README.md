# NANO-SAT-01

IMPORTANT: This is only a model, of course it does not act like a real satellite and it won't work in space (I don't believe you will bring him up there anyway).

  
  
  

### What can the satellite do?
```
-Charge himself with a solar panel
-Control the satellite and his functions via wifi from the terminal
-You can have an extern LED light up
-You can have the onboard (D13) LED light up
-You can force the beeper to make annoying sounds
-You can ask the satellite what the humidity and the temperature is
```

### What do I need to build it?
*(You also can use other electronic parts but then you probably have to change something in the code)*
```
-Arduino Nano 33 Iot (I choosed it because it has onboard Wifi)
-TP4056
-Solar Panel (5V)
-Voltage Booster (from 3.7V up to 5V)
-Lipo Battery (3.7V)
-DHT11
-LED
-Beeper (other names are buzzer or speaker)
-220 Ohm Resistor (for the LED)
-100 Ohm Resistor (for the beeper)
-1N4007 Diode
-Wires
-"Sticky" Button (Button, which keeps on when pressed)
```

*You probably also need following things*
```
-Soldering iron
-A case for your satellite
-Computer
```

*Software*
```
-Arduino IDE
-NANO-SAT-01 Terminal
```

### How to use the satellite
*When your'e finished building the satellite, follow this steps:*<br>
Firstly, connect the Arduino via USB with your computer. Make sure you disconnect the two power supply wires at the pins GND and VIN before you connect the Arduino with your computer! Then you probably have to install the Arduino Nano 33 Iot Board in the Arduino IDE (Follow this [guide](https://www.arduino.cc/en/Guide/NANO33IoT#toc2)). Change the Board under Tools->Board and then choose the right COM Port.
After that, change in the Arduino IDE in line 12 and 13 the two values of the variables "SECRET_SSID" and "SECRET_PASS". The SSID is the name of your wifi network, and the PASS is the password of your wifi network. The satellite can now establish a connection to the terminal.
Now you can uploud the sketch and after that disconnect the USB cable. Now you can connect the two power supply wires to the pins GND and VIN.
There should light up an onboard led and the beeper should make a short *beep*. Wait ~20 seconds until it beeps again. Then the arduino is connected to your wifi network.

Now you can open the terminal. It asks you about the ip address of the satellite. You should find the ip address in the online panel of your router. Enter the ip address and press enter. It now should display a welcome message. If it doesn't work, feel free to open an issue in this repository. Write "help" to see a list of all commands.


### Annotation
This project is completely non commercial and also open source. Feel free to develop new functions.

NANO-SAT-01 is only a hobby. I can't guarantee it will work but of course you can open a issue if you have questions or you need help.


### Circuit Diagram
Here's my circuit diagram of the satellite. I drawed it on my own, so it should be easy to understand.
![Satellite Circuit Diagram](https://github.com/louis-e/NANO-SAT-01/blob/master/img/schematic.png)


### Links to the software you need

| Name | Link | Explanation |
| ------ | ------ | ------ |
| Arduino IDE | https://www.arduino.cc/en/main/software | Needed to uploud and edit the sketch (code) |
| Satellite Sketch | https://github.com/louis-e/NANO-SAT-01/blob/master/satellite.ino | The code for the satellite |
| Terminal | https://github.com/louis-e/NANO-SAT-01/blob/master/Nano%20Sat%20Control.exe | Needed to send the satellite commands|


## Video Demonstration
This video is a little bit older and without a case for the satellite. Unfortunately Github doesn't has a embed function.
https://www.youtube.com/watch?v=-WKYAunGefg
<br>
*Wanna see me do it again?*


## Pictures of the Terminal
Here are two pictures of the Terminal which I had written in C#. I also used this library: https://gist.github.com/louis-e/888d5031190408775ad130dde353e0fd

<img alt="Terminal Picture 1" src="https://github.com/louis-e/NANO-SAT-01/blob/master/img/terminal1.png" width="700" height="400">
<img alt="Terminal Picture 2" src="https://github.com/louis-e/NANO-SAT-01/blob/master/img/terminal2.png" width="700" height="400">


## Pictures of my satellite
Finally, I want to show you some pictures of my satellite. I put it in a case and I decorated it. It's not finished yet, Iam going to do some improvements the next days.

<img alt="Production Picture 1" src="https://github.com/louis-e/NANO-SAT-01/blob/master/img/production1.png" width="600" height="400">
<img alt="Production Picture 2" src="https://github.com/louis-e/NANO-SAT-01/blob/master/img/production2.png" width="300" height="400">
<img alt="Production Picture 3" src="https://github.com/louis-e/NANO-SAT-01/blob/master/img/production3.png" width="525" height="400">
<img alt="Production Picture 4" src="https://github.com/louis-e/NANO-SAT-01/blob/master/img/production4.png" width="550" height="400">
<img alt="Production Picture 5" src="https://github.com/louis-e/NANO-SAT-01/blob/master/img/production5.png" width="650" height="400">
<img alt="Production Picture 6" src="https://github.com/louis-e/NANO-SAT-01/blob/master/img/production6.png" width="550" height="400">


License
----

MIT

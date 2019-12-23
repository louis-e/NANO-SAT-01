# NANO-SAT-01

IMPORTANT: This is only a model, of course it does not act like a real satellite and it won't work in space (I don't believe you will bring him up there anyway).

  
  
  

### What can the satellite do?
```-Charge himself with a solar panel
-Control the satellite and his functions via wifi from the terminal
-You can have an extern LED light up
-You can have the onboard (D13) LED light up
-You can force the beeper to make annoying sounds
-You can ask the satellite what the humidity and the temperature is
```

### What do I need to build it?
*(You also can use other electronic parts but then you probably have to change something in the code)*
```-Arduino Nano 33 Iot *(I choosed it because it has onboard Wifi)*
-TP4056
-Solar Panel (5V)
-Voltage Booster *(from 3.7V up to 5V)*
-Lipo Battery *(3.7V)*
-DHT11
-LED
-Beeper *(other names are buzzer or speaker)*
-220 Ohm Resistor *(for the LED)*
-100 Ohm Resistor *(for the beeper)*
-1N4007 Diode
-Wires
-"Sticky" Button (Button, which keeps on when pressed)
```

*You probably also need following things*
```-Soldering iron
-A case for your satellite
-Computer
```

*Software*
```-Arduino IDE
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

NANO-SAT-01 is only a hobby. I can't guarantee it will work but of course you can open a issue if you have questions or need help.


### Circuit Diagram
Here's my circuit diagram of the satellite. I drawed it on my own, so it is easy to understand.
![Satellite Circuit Diagram](https://github.com/louis-e/NANO-SAT-01/blob/master/img/schematic.png)


### Links to the software you need

| Name | Link | Explanation |
| ------ | ------ | ------ |
| Arduino IDE | https://www.arduino.cc/en/main/software | Needed to uploud and edit the sketch (code) |
| Satellite Sketch | [plugins/googledrive/README.md][PlGd] | The code for the satellite |
| Terminal | [plugins/github/README.md][PlGh] | Needed to send the satellite commands|


## Pictures of my satellite
Finally, I want to show you some pictures of my satellite. I put it in a case and I decorated it. It's not finished, Iam going to do some improvements the next days.

<img alt="Production Picture 1" src="https://github.com/louis-e/NANO-SAT-01/blob/master/img/production1.png" width="600" height="400">
![Production Picture 2](https://github.com/louis-e/NANO-SAT-01/blob/master/img/production2.png)
![Production Picture 3](https://github.com/louis-e/NANO-SAT-01/blob/master/img/production3.png)
![Production Picture 4](https://github.com/louis-e/NANO-SAT-01/blob/master/img/production4.png)
![Production Picture 5](https://github.com/louis-e/NANO-SAT-01/blob/master/img/production5.png)
![Production Picture 6](https://github.com/louis-e/NANO-SAT-01/blob/master/img/production6.png)




Dillinger uses a number of open source projects to work properly:

* [AngularJS] - HTML enhanced for web apps!
* [Ace Editor] - awesome web-based text editor
* [markdown-it] - Markdown parser done right. Fast and easy to extend.
* [Twitter Bootstrap] - great UI boilerplate for modern web apps
* [node.js] - evented I/O for the backend
* [Express] - fast node.js network app framework [@tjholowaychuk]
* [Gulp] - the streaming build system
* [Breakdance](https://breakdance.github.io/breakdance/) - HTML to Markdown converter
* [jQuery] - duh

And of course Dillinger itself is open source with a [public repository][dill]
 on GitHub.

### Installation

Dillinger requires [Node.js](https://nodejs.org/) v4+ to run.

Install the dependencies and devDependencies and start the server.

```sh
$ cd dillinger
$ npm install -d
$ node app
```

For production environments...

```sh
$ npm install --production
$ NODE_ENV=production node app
```

### Plugins

Dillinger is currently extended with the following plugins. Instructions on how to use them in your own application are linked below.

| Plugin | README |
| ------ | ------ |
| Dropbox | [plugins/dropbox/README.md][PlDb] |
| GitHub | [plugins/github/README.md][PlGh] |
| Google Drive | [plugins/googledrive/README.md][PlGd] |
| OneDrive | [plugins/onedrive/README.md][PlOd] |
| Medium | [plugins/medium/README.md][PlMe] |
| Google Analytics | [plugins/googleanalytics/README.md][PlGa] |


### Development

Want to contribute? Great!

Dillinger uses Gulp + Webpack for fast developing.
Make a change in your file and instantaneously see your updates!

Open your favorite Terminal and run these commands.

First Tab:
```sh
$ node app
```

Second Tab:
```sh
$ gulp watch
```

(optional) Third:
```sh
$ karma test
```
#### Building for source
For production release:
```sh
$ gulp build --prod
```
Generating pre-built zip archives for distribution:
```sh
$ gulp build dist --prod
```
### Docker
Dillinger is very easy to install and deploy in a Docker container.

By default, the Docker will expose port 8080, so change this within the Dockerfile if necessary. When ready, simply use the Dockerfile to build the image.

```sh
cd dillinger
docker build -t joemccann/dillinger:${package.json.version} .
```
This will create the dillinger image and pull in the necessary dependencies. Be sure to swap out `${package.json.version}` with the actual version of Dillinger.

Once done, run the Docker image and map the port to whatever you wish on your host. In this example, we simply map port 8000 of the host to port 8080 of the Docker (or whatever port was exposed in the Dockerfile):

```sh
docker run -d -p 8000:8080 --restart="always" <youruser>/dillinger:${package.json.version}
```

Verify the deployment by navigating to your server address in your preferred browser.

```sh
127.0.0.1:8000
```

#### Kubernetes + Google Cloud

See [KUBERNETES.md](https://github.com/joemccann/dillinger/blob/master/KUBERNETES.md)


### Todos

 - Write MORE Tests
 - Add Night Mode

License
----

MIT


**Free Software, Hell Yeah!**

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>


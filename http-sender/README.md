# BeagleBone Black / Wireless with I2T Sensors Stack  --  HTTP Protocol

The *BeagleBone Black* and *BeagleBone Black Wireless* are a series of small single-board computers developed by *beagleboard.org*, an OpenSource community.

This Repository contains the source code and the steps to follow to be able to make ***BeagleBone Black / Wireless*** read sensor data and send it, in an organized way, to the **[Tangle](https://www.youtube.com/watch?v=ESF8UZM70wU) (DLT)** of the **[IOTA Network](https://www.iota.org/)** through the **[Streams](https://www.iota.org/solutions/streams)** layer.

## Setting up your BeagleBone Black / Wireless with the I2T Sensors Stack

The following installation is done on **"Debian OS"** (embedded in the board) and works for *BeagleBone Black* and *BeagleBone Black Wireless*.

This is the list of Sensors/Modules that you can connect and it will be recognized immediately.
- ***BME280*** (*Bosch*) - Temperature, Humidity and Pressure sensor. -> Connected by *I2C Bus* via: *PIN20/SDA* and *PIN19/SCL* (*/dev/i2c-2*) --- Be careful with the supply of this sensor, the BM280 is powered with 3.3V, if your module does not have a voltage regulator (some modules do not have it) the sensor can be damaged if you supply 5V.
- ***MPU6050*** (*InvenSense-TDK*) - Acelerometer and Gyroscope 6-axis. -> Connected by *I2C Bus* via: *PIN20/SDA* and *PIN19/SCL* (*/dev/i2c-2*).
- ***BH1750*** (*ROHM*) - Ambient Light Sensor. -> Connected by *I2C Bus* via: *PIN20/SDA* and *PIN19/SCL* (*/dev/i2c-2*).
- ***Generic Adjustable Sound Sensor with digital output*** (like *KY038 Module*) - -> Digital Signal on *GPIO67* (*PIN8*), GND in *GPIO66* (*PIN7*) (to enable data collection).
- Also, you can connect a ***Green LED*** in *GPIO60* (*PIN12*) that blink when the data is sent to the Tangle, and a ***Red LED*** in *GPIO48* (*PIN15*) that will Blink in a certain way when it detects certain errors (totally optional).


## Setting up the Sensors Software

This software is written entirely in **C language**. External libraries are used, such as ***simpleBBB_lib*** (optimized library for BeagleBone Black I/O hardware handling), ***cURL*** (HTTP Client library) and among others already integrated in *Debian OS*.


### C Software Configuration:
In *Shell* of BeagleBone:

#### 1) Install dependencies:
cURL:
```
sudo apt-get install libcurl4-openssl-dev
```
simpleBBB_lib:
```
cd ~
git clone https://github.com/Gustbel/simpleBBB-lib.git && cd simpleBBB-lib
bash install.sh
```

#### 2) Copy the repository to the local file system of your Raspberry.
```
cd ~
git clone https://github.com/iot2tangle/BeagleBone-Black.git
cd BeagleBone-Black/http-sender
```
#### 3) Edit the file config.h

Edit the **config.h** file to define the values for your configuration: The *endpoint* and *port* that will have the *I2T Streams HTTP Gateway* running, the *Device Id*, and others configurations. The *Device Id* you define here must be between the devices you set in on the *Gateway configuration file*. 

Keep in mind that any changes on the config file will require to recompile the code.

```
const char* id_name = "BeagleBoneB-HTTP";

/* Endpoint Configuration */
const char* endpoint = "192.168.1.113/sensor_data";    /* Endpoint (HTTP), must NOT include 'http://xxx' or 'tcp://xxx' */
int port = 8080;

/* Enable Sensors */
bool isEnable_TemperatureIntern = true;
bool isEnable_TemperatureExtern = true;	   /* true: Enable  --  false: Disable */
bool isEnable_Humidity = true;
...

/* Interval of time */
long interval = 30;    /* Time in seconds between */
```

#### 4) Compile the code with:
```
make
```
#### 5) Run:
```
./BeagleboneBW-HTTP
```


If the *I2T Streams HTTP Gateway* is configured correctly (we will explain this next), ***you will be sending data to Tangle via Streams***. 

The following capture shows a *BeagleboneBW* with a *BME280* connected (note how the sensor is detected automatically):

![Raspberry with BME280 sending data to the Tangle](https://i.postimg.cc/cH6TWpXP/Screenshot-from-2020-10-16-11-33-05.png)

Here we can see the result when all the sensors have been connected:

![Raspberry with all sensors sending data to the Tangle](https://i.postimg.cc/XvsxTjcw/Screenshot-from-2020-10-16-11-34-46.png)
	
# Setting up the Streams HTTP Gateway

## Preparation

Install Rust if you don't have it already. More info about Rust here https://www.rust-lang.org/tools/install

```
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

Make sure you also have the build dependencies installed, if not run:  

```
sudo apt update
sudo apt install build-essential pkg-config libssl-dev
```

## Installing the Streams Gateway
Get the Streams Gateway repository
https://github.com/iot2tangle/Streams-http-gateway

```
git clone https://github.com/iot2tangle/Streams-http-gateway
```

Navigate to the root of **Streams-http-gateway** directory and edit the **config.json** file to define yours *device names*, *endpoint*, *port*, you can also change the IOTA Full Node used, among others.

## Start the Streams Server

### Sending messages to the Tangle

Run the Streams Gateway:

```
cargo run --release  
```

This will compile and start the *Streams HTTP Gateway*. Note that the compilation process may take from 3 to 25 minutes (Pi3 took us around 15/25 mins, Pi4 8 mins and VPS or desktop machines will generally compile under the 5 mins) depending on the device you are using as host.
You will only go through the compilation process once and any restart done later will take a few seconds to have the Gateway working.

Once started, the ***Channel Id*** will be displayed, and the gateway will be open waiting for data to send to the Tangle.

![Streams Gateway receiving data](https://i.postimg.cc/zfz0tbWz/Screenshot-from-2020-10-16-11-44-59.png)
*The Channel Id that will allow subscribers to access the channel data.*

### Reading messages from the Tangle

You can read the received messages directly from the "I2T Explorer": https://explorer.iot2tangle.io/ using the Channel Id printed by the Gateway in shell.

![I2T Explorer](https://i.postimg.cc/wTNf7dgp/Screenshot-from-2020-10-16-11-46-16.png)


*For inquiries, improvements or errors detected, please start an issue in this repository.*

# UE4-JoyConDriver
Unreal Engine 4/5 Nintendo Switch Joy Con Driver

## About
This project is a plugin for Unreal Engine 4.27.x/5.2 that allows you to connect the Nintendo Switch Joy Cons to Unreal without the need for a driver and allowing you to use its features such as accelerometer, gyroscope and IMU.

## Why ?
The drivers for Joy Cons are limited and there are very cool features present in Joy Cons such as motion sensors and HD Rumble, the goal is to allow using these features within Unreal without headaches and with simplicity.

The project is still in alpha, so I would say that it is not yet simple enough.

## Requirements
* At least one Nintendo Switch Joy Con
* A Bluetooth adapter compatible with Joy Con
* Unreal Engine 4.27.x/5.2

## [Getting Started](https://github.com/jpdante/UE4-JoyConDriver/wiki/Getting-Started)

### API Reference
* [Blueprint Events](https://github.com/jpdante/UE4-JoyConDriver/wiki/Blueprint-Events)
* [Blueprint Functions](https://github.com/jpdante/UE4-JoyConDriver/wiki/Blueprint-Functions)
* [Blueprint Structures](https://github.com/jpdante/UE4-JoyConDriver/wiki/Blueprint-Structures)
* [CPP Functions](https://github.com/jpdante/UE4-JoyConDriver/wiki/CPP-Functions)

## Known issues
* When connecting a Joy Con in the editor it will remain connected even after the simulation/play is over and will stop working when playing again, the only solution is to resume de connection with ResumeConnection node.

## Assets Copyright
### Nintendo Switch Inspired Controller (JoyCon Plus)
Published on Jan 27, 2021 By Harry Felton (harryfelton)

License: Commercial use is allowed, you must attribute the
creator, you may remix this work and the remixed work should be
made available under this license.

[https://www.youmagine.com/designs/27960](https://www.youmagine.com/designs/27960)

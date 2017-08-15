# Wallsy
Firmware for a hacked Disney U-Control Wall-e

## What the frig is this?
Me and someone without a github replaced the logic board in a U-Control Wall-e with a [Teensy LC](https://www.pjrc.com/teensy/teensyLC.html).
We added a distance sensor (a Sharp optical ridiculously expensive one since the Chinese ultrasonic cheap ones wouldn't arrive in time)
and a yellow LED in the middle of the sun on Wall-e's 'display'.

## Why would you do that?
It's fun!

## How do I use this?
Get a Teensy, wire it up, modify the `#define`'s in the `main.ino` file and upload to the Teensy.
That is, if your Arduino IDE has the [Teensy libraries](https://www.pjrc.com/teensy/teensyduino.html) installed.

## What works and what doesn't?
- [ ] motor control
- [x] LED blinking
- [ ] IR control
- [ ] Sounds
- [ ] Distance sensing

Yes, for now you let it run by programming moves...

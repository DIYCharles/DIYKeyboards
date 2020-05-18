# Very Simple  USB Macropad

Very simple and easy to understand code to make your own custom macropad. Each key switch requires its own pin on the pro micro. This is not the optimal configuration but make it very easy to use. 

Currently the code does not support the encoders.
![alt text](https://i.imgur.com/JUtJT0c.jpg "4x4")


#Setup
To wire up a key connect one of the pins of the momentary switch to ground and the other pin to a digital pin 2-21. The switch will activate the key when the pin is shorted to ground then it will delay so that the key is not input more times than desired.

##Program Pro Micro
To program click the verify and upload then quickly enter bootloader mode. If you don't do it fast enough it will not connect.

##Enter Bootloader Mode 
To enter bootloader mode on the pro micro short the rst pin to the ground pin twice quickly. This will keep it in bootloader mode for 8s.

1x4 Macropad With Encoder
=========

This is a build of a 1x4 Macropad with an ecoder using a Arduino Pro Micro and QMK Firmware 

![alt text](https://raw.githubusercontent.com/DIYCharles/DIYKeyboards-/master/photos/img1.jpg "img1.jpg")

Table of contents
=================

<!--ts-->
   * [Wiring](#Wiring)
   * [Build](#Build)
   * [QMK Firmware](#QMK-Firmware)
   * [Compile And Flash](#Compile-And-Flash)
<!--te-->


Wiring
============

I wired this in the COL2ROW diode configuration. How this works is each column is connected to its own pin then the other side of the switch is connected to a diode with the line on the far side. The other side of the diode is connected to the ends of all the other diodes in the same row.

![alt text](https://raw.githubusercontent.com/DIYCharles/DIYKeyboards-/master/photos/img3.jpg "img3.jpg")

The rotary encoder has 5 pins. The two on one side are a switch that is activated by pressing in the dial like a R3 on a game controller. The other side with 3 pins are connected to pins on the arduino with the middle pin connected to ground.

![alt text](https://raw.githubusercontent.com/DIYCharles/DIYKeyboards-/master/photos/img4.jpg "img4.jpg")






Build
============

I didn't put much thought into the design or build. There are 4 parts. They are held together by 4 M3x20mm screws and 8 M3 nuts. Install everything on the top plate and wire. Match the face plate with the base and cut the wires to size. Solder up the pro-micro and test. To get the M3 nuts to sit apply a soldering tip to them and melt them into the hole. 

![alt text](https://raw.githubusercontent.com/DIYCharles/DIYKeyboards-/master/photos/img5.JPG "img5.jpg")

![alt text](https://raw.githubusercontent.com/DIYCharles/DIYKeyboards-/master/photos/img6.JPG "img6.jpg")

![alt text](https://raw.githubusercontent.com/DIYCharles/DIYKeyboards-/master/photos/img7.JPG "img7.jpg")

![alt text](https://raw.githubusercontent.com/DIYCharles/DIYKeyboards-/master/photos/img8.JPG "img8.jpg")




QMK Firmware
============

In the config.h file we set the pins on the pro-micro. Note they are not the same pins printed on the board. You can find the pin lables here https://deskthority.net/wiki/Arduino_Pro_Micro. DIODE_DIRECTION is importand to note.

```h
/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 5

/* key matrix pins */
#define MATRIX_ROW_PINS { F7 }
#define MATRIX_COL_PINS { B3, B4, B1, B2, B5 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { D1 }
#define ENCODERS_PAD_B { E6 }
#define ENCODER_DIRECTION_FLIP

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
```
In the kb/keymaps/default/keymap.c you can change the key bindings. Currently I have them set to 

* LCTL(KC_Z) **Undo**
* LCTL(KC_C) **Copy**
* LCTL(KC_V) **Paste**
* LCTL(LSFT(KC_M)) **Mute mic in MS Teams**
* KC_MUTE **Rotary encoder push button mutes speakers**

```c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		LCTL(KC_Z), LCTL(KC_C), LCTL(KC_V), LCTL(LSFT(KC_M)), KC_MUTE),
}
```

The rotary encoder is mapped in the keymap.c file with

* KC_AUDIO_VOL_UP and KC_AUDIO_VOL_DOWN **Turns the volume up and down**
  
```c
void encoder_update_user(int8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_AUDIO_VOL_UP);
    } else {
      tap_code(KC_AUDIO_VOL_DOWN);
    }
}
```

Compile And Flash
=====
* First install QMK and QMK Toolbox

To compile move the files into your qmk directory under keyboards like this.

![alt text](https://raw.githubusercontent.com/DIYCharles/DIYKeyboards-/master/photos/img9.jpg "img9.jpg")

load up your MSYS2 MinGW 64-bit where qmk is installed and run 

```bash
$ qmk compile -kb kb -km default
```

It should look like this

![alt text](https://raw.githubusercontent.com/DIYCharles/DIYKeyboards-/master/photos/img10.jpg "img10.jpg")

One complete under the /qmk-firmware/ will be a kb_default.hex

Load up QMK Toolbox. Click open and choose the /qmk_firmware/kb_default.hex. Click autoflash. Connect your pro-micro via usb. To enter bootloader mode short the reset and ground pins. QMK Toolbox will auto detect it and flash it. It should look like this.

![alt text](https://raw.githubusercontent.com/DIYCharles/DIYKeyboards-/master/photos/img11.png "img11.jpg")


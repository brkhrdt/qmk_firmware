# skelly

![skelly](imgur.com image replace me!)

*A short description of the keyboard/project*

Make example for this keyboard (after setting up your build environment):

    make skelly:default

Flashing example for this keyboard:

    make skelly:default:flash

Or explicit commands:

`qmk compile -c -kb skelly -km default`

Disconnect the two halves, hold top-left key (q or ') and attach usb, mount drive, then:

`qmk flash -kb skelly -km default`

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

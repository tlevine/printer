Tom's Printer
===========
Tom has a [thermal printer](http://learn.adafruit.com/mini-thermal-receipt-printer/microcontroller)
connected to a Beaglebone
and accessed over a local network. The Beaglebone runs the software in this repository.

Once it's running, you can print something like so.

    curl --data=blahblah http://printer

where `printer` is the printer's network address.

You can also print something by plugging a USB cable into the arduino and sending text over serial.

    # Directions here

## Installation
This requires an arduino with an ethernet shield and thermal printer.
You also need Ladyada's thermal printer library.
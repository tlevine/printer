Tom's Printer
===========
Tom has a [thermal printer](http://learn.adafruit.com/mini-thermal-receipt-printer/microcontroller)
connected to an Arduino and accessed over a local network.

When it's running, you can print something like so.

    curl --data foo=bar http://printer

where `printer` is the printer's network address.

You can also print something by plugging a USB cable into the arduino and sending text over serial.

    # Directions here

## Installation
This requires an arduino with an ethernet shield and thermal printer.
You also need Ladyada's thermal printer library.

Tom's Printer
===========
Tom has a [thermal printer](http://learn.adafruit.com/mini-thermal-receipt-printer/microcontroller)
connected to a Beaglebone
and accessed over a local network. The Beaglebone runs the software in this repository.

Once it's running, you can print something like so.

    curl --data=blahblah http://printer

where `printer` is the printer's network address.

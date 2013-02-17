Tom's Printer
===========
Tom has a [thermal printer](http://learn.adafruit.com/mini-thermal-receipt-printer/microcontroller)
connected to a Beaglebone
and accessed over a local network. The Beaglebone runs the software in this repository.

Once it's running, you can print something like so.

    curl --data=blahblah http://printer

where `printer` is the printer's network address.

## Installation
Run this stuff on the Beaglebone to install.

Install Python

    opkg update
    opkg install python-distutils python-mmap python-pyserial

Install PyBBIO

    git clone git://github.com/alexanderhiam/PyBBIO.git
    cd PyBBIO
    python setup.py install

Install the print server.

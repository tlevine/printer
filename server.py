from escpos import *

DEVICE = ''

p = printer.Serial(DEVICE)
p.text('ALL YOUR BASE ARE BELONG TO US.')
p.cut()

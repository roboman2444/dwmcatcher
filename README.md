# dwmcatcher
Origionally meant to be a solution to restarting DWM when changes were made to it without restarting X.

I use it in my xinitrc as exec dwmcatcher dwm

Can be used for other things.

##Usage:
dwmcatcher program [program args]
* Will start dwmcatcher with that program
* ex: dwmcatcher dwm

Sending signal USR1 to a dwmcatcher process will cause it to restart its watched program, sending sigterm to it

* dwmcatcher with no args uses killall dwmcatcher -q -USR1 for ease of use

Sending signal USR2 to a dwmcatcher process will cause it to restart the program the next time the program exits on its own

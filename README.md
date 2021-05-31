# CENG252-LAB04

In addition to console output we display graphic data on the Sense Hat using a low-level Linux graphics interface, the framebuffer (see linux/fb.h). The framebuffer is a linux device which can be opened as a file which may then be accessed using ioctl calls.  Frame buffers are a series of contiguous bytes representing pixel data on a display.  When you write data to these bytes, pixels on the display are activated or de-activated with various colours and intensities.  The Sense Hat has an 8X8 LED RGB array accessible as a Linux frame buffer (/dev/fb1).  Each pixel requires 2 bytes of data to encode Red, Green, and Blue colors using a standard RGB565 colour scheme.  This requires a frame buffer with 128 bytes (64 words, w=2 below).

RGB565 encodes red with the first 5-bits, then the 6 middle bits for green, and blue with the remaining 5-bits.  To set or extract this information in the frame buffer requires locating the proper word in the frame buffer and then masking, and shifting to set or extract the desired colour bits.  The code for this in sensehat.cpp:

1.	Opens the frame buffer for this device.
2.	Uses an ioctl call to get the variable screen information.
3.	Sets a pointer to the frame buffer is held in the class structure with the variable name fp.
4.	Has various functions that use this pointer and the screen information to modify the word corresponding to a specific x/y location that has the RGB565 data for a pixel (LightPixel(int row, int column, uint16_t couleur))
5.	Other LED matrix functions make various transformations of the data routed to the frame buffer.

In this lab we create a routine to display a Humber logo at start up, and then implement a simple electronic level display to show tilt in the x and y directions.

							
							
							
							
							
							
							
							
 

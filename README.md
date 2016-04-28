# VC0706
VC0706 serial camera library modified for use with linux boards

This is a fork of the adafruit VC0706 serial camera library (https://github.com/adafruit/Adafruit-VC0706-Serial-Camera-Library) modified for linux systems instead of arduino.

Requires Boost asio (http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio.html)

This version also allows output of image data via SPI ( use VC0706::readPictureDMA(uint32_t n) )

Note that the adafruit VC0706 camera (https://www.adafruit.com/products/397) does not have the SPI lines broken out.
If you plan to read pictures via SPI you will need to find a camera with SPI lines broken out. I found mine on aliexpress unfortunately :(

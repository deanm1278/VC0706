/* This script connects to the camera, prints out the version
 * and then waits a second before taking and outputting a picture
 * This picture will be output via SPI from the camera.
 * THIS EXAMPLE DOES NOT RETURN THE PICTURE TO THE MASTER. It only
 * outputs data from the camera SPI port.
 * 
 * Requires boost system library (boost asio for serial communication)
 */

#include <iostream>
#include "VC0706.h"

#define CAMERA_PATH "/dev/tty.camera"

VC0706 *camera;

using namespace std;

int main(int argc, char **argv) {
    try {
        //open the camera hardware
        camera = new VC0706(CAMERA_PATH);
        if (!camera->reset()) {
            cout << "camera reset failed!" << endl;
            return 1;
        }
        char *version = camera->getVersion();
        if (version) {
            cout << version << endl;
        } else {
            cout << "failed to get camera version!" << endl;
        }
        camera->setImageSize(VC0706_640x480);

    } catch (boost::system::system_error& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    usleep(999999);

    if (!camera->takePicture())
        cout << "failed to take pic" << endl;
    else
        cout << "picture taken!" << endl;

    uint32_t jpglen = camera->frameLength();
    
    //output the picture via SPI in one shot
    if(camera->readPictureDMA(jpglen) == -1){
        cout << "failed to read picture" << endl;
    }
    
    return 0;
}
import thumby

# THIS BIT IS NECESSARY
# NEEDED FOR CALLING OTHER FILES ;LKFADJBNGOUJSDFABNOLDFABN ONIKL

from sys import path
if not '/Games/OpenWorldTest' in path:
    path.append( '/Games/OpenWorldTest' )

import objectManager
import displayManager
import prefabManager
import inputManager

# Sets initial fps to 30
thumby.display.setFPS(30)

prefabManager.makeSun()

prefabManager.makeSun([10,10])

while(True):
    
    # Checks inputs w/ input manager
    inputManager.checkInputs()
    
    thumby.display.fill(0) # Fill display with black pixels
    
    displayManager.getUpdatedCameraLocation()
    
    objectManager.renderObjects()
    
    # adds one to the frame counter
    displayManager.frameCtr += 1

    thumby.display.update()
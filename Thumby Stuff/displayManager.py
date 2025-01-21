import thumby

from sys import path
if not '/Games/OpenWorldTest' in path:
    path.append( '/Games/OpenWorldTest' )
    
import cameraManager

# Counter that will be used to index different frames
frameCtr = 0

# Refence to where the camera is located
camLocat = [0,0]

def debugCamLocation():
    camLocatStr = str(camLocat[0]) + " " + str(camLocat[1])
    thumby.display.setFont("/lib/font3x5.bin", 3, 5, 1)
    thumby.display.drawText(camLocatStr, 5, 16, 1)

def getUpdatedCameraLocation():
    newLocat = cameraManager.getCameraLocation()
    
    camLocat[0] = newLocat[0]
    camLocat[1] = newLocat[1]
    
    # debugCamLocation()
    

# Displays an object dependent on it's location
def displayObject(sprite, animSpeed, x, y):
    
    sprite.x = (x - (sprite.width/2)) - camLocat[0]
    sprite.y = (y - (sprite.height/2)) - camLocat[1]
    
    sprite.setFrame(int(frameCtr/animSpeed))
    
    thumby.display.drawSprite(sprite)
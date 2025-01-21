import thumby

from sys import path
if not '/Games/OpenWorldTest' in path:
    path.append( '/Games/OpenWorldTest' )
    
import cameraManager

speed = 5

# checks the inputs of the player
def checkInputs():
    
    mod = [0,0]
    
    if thumby.buttonU.pressed():
        mod[1] -= speed
    
    if thumby.buttonD.pressed():
        mod[1] += speed
    
    if thumby.buttonL.pressed():
        mod[0] -= speed
    
    if thumby.buttonR.pressed():
        mod[0] += speed
    
    cameraManager.modifyCameraLocation(mod)
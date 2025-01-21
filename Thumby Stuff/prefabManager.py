import thumby

from sys import path
if not '/Games/OpenWorldTest' in path:
    path.append( '/Games/OpenWorldTest' )
    
import objectManager

def makeSun (locat=None):
    
    # BITMAP: width: 7, height: 7
    sun1 = bytearray([0,42,28,62,28,42,0])

    # BITMAP: width: 7, height: 7
    sun2 = bytearray([0,20,62,28,62,20,0])

    sunSPR = thumby.Sprite(7,7, sun1+sun2, 28, 10)
    
    if locat is not None: 
        objectManager.GameObject(sunSPR, 15, locat)
    else:
        objectManager.GameObject(sunSPR, 15)
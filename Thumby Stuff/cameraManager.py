import thumby

cameraLocat = [0,0]

def getCameraLocation():
    return cameraLocat

def modifyCameraLocation(mod):
    cameraLocat[0] += mod[0]
    cameraLocat[1] += mod[1]
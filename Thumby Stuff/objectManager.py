import thumby

# THIS BIT IS NECESSARY
# NEEDED FOR CALLING OTHER FILES ;LKFADJBNGOUJSDFABNOLDFABN ONIKL

from sys import path
if not '/Games/OpenWorldTest' in path:
    path.append( '/Games/OpenWorldTest' )

import displayManager

# Way to track all currently active game objects

objects = []

# When an object gets made, this gets called so that it may get kept track of

def addObjectToList (something):
    objects.append(something)

# Renders all objects in the list
def renderObjects ():
    for something in objects:
        something.renderObject()

# basic class idea for a game object
class GameObject(object):
    # Initializes a gameobject with a sprite and sprite speed
    def __init__(self, sprite, animSpeed, locat=None):
        self.sprite = sprite
        self.animSpeed = animSpeed
        
        # If there is a given location, then it will set it in the world space
        if locat is not None:
            self.x = locat[0]
            self.y = locat[0]
            
        # If there isn't then it's x y position will be put in the center
        else:
            self.x = 36
            self.y = 20
        
        # Finally the object is added to the object list
        addObjectToList(self)
    
    # Returns the attached sprite
    def getSprite(self):
        return self.sprite
    
    def renderObject(self):
        displayManager.displayObject(self.sprite, self.animSpeed, self.x, self.y)
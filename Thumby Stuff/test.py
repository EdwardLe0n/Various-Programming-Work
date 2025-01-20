import thumby

# BITMAP: width: 7, height: 7
sun1 = bytearray([0,42,28,62,28,42,0])

# BITMAP: width: 7, height: 7
sun2 = bytearray([0,20,62,28,62,20,0])

# Counter that will be used to index different frames
frameCtr = 0

sunSPR = thumby.Sprite(7,7, sun1+sun2, 28, 10)

# Sets initial fps to 30
thumby.display.setFPS(30)

class GameObject(object):
    # Initializes a gameobject with a sprite
    def __init__(self, sprite):
        self.sprite = sprite
    
    # Returns the attached sprite
    def getSprite(self):
        return self.sprite

sun = GameObject(sunSPR)

while(True):
    thumby.display.fill(0) # Fill display with black pixels

    # Display the sprite frames & increase the frame counter
    # Added a divisor and conversion to an int so that it wouldn't spaz
    sun.getSprite().setFrame(int(frameCtr/15))
    
    # adds one to the frame counter
    frameCtr += 1
    
    thumby.display.drawSprite(sunSPR)

    thumby.display.update()

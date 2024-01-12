
class rect:
         pass
box=rect()
box.width=20
box.height=30


def grow_rect(rect,width,height):
    rect.width=rect.width+width
    rect.height=rect.height+height

grow_rect(box,50,100)
print(box.width,box.height)

class point:
        pass
class rect:
         pass
box=rect()
box.width=100
box.height=200
box.corner=point()
box.corner.x=0
box.corner.y=0


def find_center(rect):
    p=point()
    p.x=rect.corner.x+rect.width/2
    p.y=rect.corner.y+rect.height/2
    return p

center=find_center(box)
print(center.x,center.y)

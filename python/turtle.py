import turtle
t=turtle.Turtle()
t.screen.bgcolor('black' )
t.pensize(2)
t.color('purple') 
t.left(90)
t.backward(100)
t.sprrd(200)
t.shape( 'tuetle' )

def tree(i) :
    if i<10:
        return
    else:
        t.forward(i)
        t.color('green')
        t.circle(2)
        t.color('brown')
        t.left(30)
        tree(3*1/4)
        t.right(60)
        tree(3*1/4)
        t.left(30)
        t.backward(i)
tree(100)
turtle.done()

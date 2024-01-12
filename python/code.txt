import mysql.connector as connector
import math


db = connector.connect(
host = 'localhost',
user = 'root',
password = 'shs82199',
database = 'Shape'
)
mycursor = db.cursor()

val =[]

def insert():
    query = "INSERT INTO data (name, shape, parameter, value) VALUES ('{}','{}','{}',{})".format(ent.get()[16:],combobox1.get(),combobox2.get(),val[0])
    mycursor.execute(query)
    db.commit()




def fRect():
   
    def give():
        nonlocal a, b
        a=float(e1.get())
        b=float(e2.get())
        NewWin.destroy()
        Area_R=float(a*b)
        Per_R=2*(a+b)
        if combobox2.get()=="Area":
            txt="Area of rectangle is : "+str(Area_R)
            val.append(Area_R)
            cv.create_text(150, 300, text=txt)
            insert()
        else:
            txt="Perimeter of rectangle is : "+str(Per_R)
            val.append(Per_R)
            cv.create_text(150, 300, text=txt)
            insert()
            
    a=0
    b=0    
    NewWin=Toplevel(root)
    Label(NewWin, text="Enter the first side of rectangle").pack()
    e1=Entry(NewWin, bg="grey")
    e1.pack()
    Label(NewWin, text="Enter the second side of rectangle").pack()
    e2=Entry(NewWin, bg="grey")
    e2.pack()
    submit=Button(NewWin, text="Submit", command=give).pack()
    
def fSquare():
    
    def give():
        nonlocal a
        a=float(e1.get())
        NewWin.destroy()
        Area=float(a*a)
        Per=4*a
        if combobox2.get()=="Area":
            txt="Area of square is : "+str(Area)
            val.append(Area)
            cv.create_text(150, 300, text=txt)
            insert()
        else:
            txt="Perimeter of square is : "+str(Per)
            val.append(Per)
            cv.create_text(150, 300, text=txt)
            insert()
            
    a=0  
    NewWin=Toplevel(root)
    Label(NewWin, text="Enter the side of square").pack()
    e1=Entry(NewWin, bg="grey")
    e1.pack()
    submit=Button(NewWin, text="Submit", command=give).pack()
   
def circ():
   
    def give():
        nonlocal a
        a=float(e1.get())
        NewWin.destroy()
        Area=math.pi*a**2
        Per=2*math.pi*a
        if combobox2.get()=="Area":
            txt="Area of circle is : "+str(Area)
            val.append(Area)
            cv.create_text(150, 300, text=txt)
            insert()
        else:
            txt="Perimeter of circle is : "+str(Per)
            val.append(Per)
            cv.create_text(150, 300, text=txt)
            insert()
            
    a=0  
    NewWin=Toplevel(root)
    Label(NewWin, text="Enter radius of circle").pack()
    e1=Entry(NewWin, bg="grey")
    e1.pack()
    submit=Button(NewWin, text="Submit", command=give).pack()

     
def para():
    def give():
        nonlocal a, b,c
        a=float(e1.get())
        b=float(e2.get())
        c = float(e3.get())
        NewWin.destroy()
        Area=a*b
        Per=2*a + 2*c
        if combobox2.get()=="Area":
            txt="Area of parallelogram is : "+str(Area)
            val.append(Area)
            cv.create_text(150, 300, text=txt)
            insert()
        else:
            txt="Perimeter of parallelogram is : "+str(Per)
            val.append(Per)
            cv.create_text(150, 300, text=txt)
            insert()
            
    a=0
    b=0
    c=0
    NewWin=Toplevel(root)
    Label(NewWin, text="Enter the base of parallelogram").pack()
    e1=Entry(NewWin, bg="grey")
    e1.pack()
    Label(NewWin, text="Enter height of parallelogram").pack()
    e2=Entry(NewWin, bg="grey")
    e2.pack()
    Label(NewWin, text="Enter width of parallelogram").pack()
    e3=Entry(NewWin, bg="grey")
    e3.pack()
    submit=Button(NewWin, text="Submit", command=give).pack()

def rhom():
    def give():
        nonlocal a, b,c
        a=float(e1.get())
        b=float(e2.get())
        c = float(e3.get())
        NewWin.destroy()
        Area=(a*b)/2
        Per=4*c
        if combobox2.get()=="Area":
            txt="Area of rhombus is : "+str(Area)
            val.append(Area)
            cv.create_text(150, 300, text=txt)
            insert()
        else:
            txt="Perimeter of rhombus is : "+str(Per)
            val.append(Per)
            cv.create_text(150, 300, text=txt)
            insert()
            
    a=0
    b=0
    c=0
    NewWin=Toplevel(root)
    Label(NewWin, text="Enter length of first diagonal").pack()
    e1=Entry(NewWin, bg="grey")
    e1.pack()
    Label(NewWin, text="Enter length of second diagonal").pack()
    e2=Entry(NewWin, bg="grey")
    e2.pack()
    Label(NewWin, text="Enter side of rhombus").pack()
    e3=Entry(NewWin, bg="grey")
    e3.pack()
    submit=Button(NewWin, text="Submit", command=give).pack()
    
    

def Triangle():
    def give():
        nonlocal a, b,c
        a=float(e1.get())
        b=float(e2.get())
        c = float(e3.get())
        NewWin.destroy()
        s = (a+b+c)/2
        area =math.sqrt(s*(s-a)*(s-b)*(s-c))
        per = a+b+c
        if combobox2.get()=="Area":
            txt="Area of Triangle is : "+str(area)
            val.append(area)
            cv.create_text(150, 300, text=txt)
            insert()
        else:
            txt="Perimeter of triangle is : "+str(per)
            val.append(per)
            cv.create_text(150, 300, text=txt)
            insert()
            
    a=0
    b=0
    c=0
    NewWin=Toplevel(root)
    Label(NewWin, text="Enter first side").pack()
    e1=Entry(NewWin, bg="grey")
    e1.pack()
    Label(NewWin, text="Enter secind side").pack()
    e2=Entry(NewWin, bg="grey")
    e2.pack()
    Label(NewWin, text="Enter third side").pack()
    e3=Entry(NewWin, bg="grey")
    e3.pack()
    submit=Button(NewWin, text="Submit", command=give).pack()
    
    
    
   
def Cone():
    def give():
        nonlocal a, b
        a=float(e1.get())
        b=float(e2.get())
        NewWin.destroy()
        Area=3.14* a* math.sqrt((a*a + b*b))
        vol=0.33*3.14*a*a*b
        if combobox2.get()=="Area":
            txt="Area of Cone is : "+str(Area)
            val.append(Area)
            cv.create_text(150, 300, text=txt)
            insert()
        else:
            txt="Volume of cone is : "+str(vol)
            val.append(vol)
            cv.create_text(150, 300, text=txt)
            insert()
            
    a=0
    b=0    
    NewWin=Toplevel(root)
    Label(NewWin, text="Enter radius of cone").pack()
    e1=Entry(NewWin, bg="grey")
    e1.pack()
    Label(NewWin, text="Enter height of cone").pack()
    e2=Entry(NewWin, bg="grey")
    e2.pack()
    submit=Button(NewWin, text="Submit", command=give).pack()
    
    
    
   
    
def Cylinder():
    def give():
        nonlocal a, b
        a=float(e1.get())
        b=float(e2.get())
        NewWin.destroy()
        pi = 3.14
        Area=2*pi*a*b + 2*pi*a*a
        vol=pi*a*a*b
        if combobox2.get()=="Area":
            txt="Area of Cylinder is : "+str(Area)
            val.append(Area)
            cv.create_text(150, 300, text=txt)
            insert()
        else:
            txt="Volume of Cylinder is : "+str(vol)
            val.append(vol)
            cv.create_text(150, 300, text=txt)
            insert()
            
    a=0
    b=0    
    NewWin=Toplevel(root)
    Label(NewWin, text="Enter radius of cylinder").pack()
    e1=Entry(NewWin, bg="grey")
    e1.pack()
    Label(NewWin, text="Enter height of cylinder").pack()
    e2=Entry(NewWin, bg="grey")
    e2.pack()
    submit=Button(NewWin, text="Submit", command=give).pack()
    
    



#Tkinter part

options=[
    "Square",
    "Rectangle",
    "Triangle",
    "Cone",
    "Cylinder",
    "Circle",
    "Rhombus",
    "Parallelogram",
]
 



from tkinter import *
from tkinter import ttk
from tkinter.messagebox import showinfo

root=Tk()
root.title("Calculator")
lb1=Label(root,text="Hello")
lb1.pack()
ent=Entry(root,width=50)
ent.pack()
ent.insert(0,"Enter your name:")

def Enter():
    L=ent.get()
    lb1.config(text="Hello "+L[16:])
    
bt1=Button(root,text="Enter",command=Enter,bg="blue",fg="white")
bt1.pack()

def show():
    lb2.config( text="Selected shape: "+combobox1.get())

def show2():
    lb3.config(text="Selected paramater: "+combobox2.get())

clicked = StringVar()
clicked.set("Square")




def chosen_shape(x):
    
    if combobox1.get()=="Square":
        combobox2.config(value=sq_options)
        combobox2.pack()
        combobox2.current(0)
        fSquare()
        cv.create_rectangle(100,100,100,100,fill="black")
        #shape_chosen ="Square"
    
    elif combobox1.get()=="Rectangle":
        combobox2.config(value=rect_options)
        combobox2.pack()
        combobox2.current(0)
        fRect()
        cv.create_rectangle(50,150,250,50,fill="black")
        #shape_chosen==""

    elif combobox1.get()=="Triangle":
        combobox2.config(value=tri_options)
        combobox2.pack()
        combobox2.current(0)
        Triangle()
        #cv3=
        #shape_chosen=="Triangle"

    elif combobox1.get()=="Cone":
        combobox2.config(value=cone_options)
        combobox2.pack()
        combobox2.current(0)
        Cone()
        #cv4=
        #shape_chosen=="Cone"

    elif combobox1.get()=="Cylinder":
        combobox2.config(value=cyl_options)
        combobox2.pack()
        combobox2.current(0)
        Cylinder()
        #cv5=
        #shape_chosen=="Cylinder"

    elif combobox1.get()=="Circle":
        combobox2.config(value=cir_options)
        combobox2.pack()
        combobox2.current(0)
        circ()
       #cv6=Canvas.create_oval(110,10,210,10,outline="black",fill="black",width=2)
        #cv6.pack()
        #shape_chosen =="Circle"

    elif combobox1.get()=="Rhombus":
        combobox2.config(value=rhom_options)
        combobox2.pack()
        combobox2.current(0)
        rhom()
        #cv7=
        #shape_chosen=="Rhombus"

    elif combobox1.get()=="Parallelogram":
        combobox2.config(value=para_options)
        combobox2.pack()
        combobox2.current(0)
        para()
        #cv8=
        #shape_chosen=="Parallelogram"


#Shape selection combobox
combobox1= ttk.Combobox(root, value=options)
combobox1.pack()
combobox1.current(0)
combobox1.bind("<<ComboboxSelected>>",chosen_shape)

sq_options=["Area",
                "Perimeter"]

rect_options=["Area",
                  "Perimeter"]


tri_options=["Area",
                 "Perimeter"]
                
cone_options=["Area",
            "volume"]

cyl_options=["Area",
            "Volume",
            "Perimeter"]

cir_options=["Area",
                 "Perimeter"]

rhom_options=["Area",
                  "Perimeter"]

para_options=["Area",
                  "Perimeter"]


bt2= Button(root, text="Select shape", command= show, bg="blue", fg="white")
bt2.pack()

lb2=Label(root, text=" ")
lb2.pack()



#Combobox
combobox2= ttk.Combobox(root, value=[" "])
combobox2.pack()

bt3= Button(root, text="Select paramter", command=show2, bg="blue", fg="white")
bt3.pack()

lb3= Label(root, text=" ")
lb3.pack()

lb4=Label(root,text="shape:")
lb4.pack()
cv=Canvas(root,width=500, height=500)
cv.pack()


root.mainloop()





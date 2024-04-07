import turtle

def draw_support():
    turtle.color("brown")
    turtle.begin_fill()
    for _ in range(2):
        turtle.forward(20)
        turtle.left(90)
        turtle.forward(100)
        turtle.left(90)
    turtle.end_fill()

def draw_base():
    turtle.penup()
    turtle.goto(0, -50)
    turtle.pendown()
    turtle.color("gray")
    turtle.begin_fill()
    turtle.circle(50)
    turtle.end_fill()

def draw_gondola():
    turtle.penup()
    turtle.goto(-10, -50)
    turtle.pendown()
    turtle.color("blue")
    turtle.begin_fill()
    for _ in range(4):
        turtle.forward(20)
        turtle.left(90)
    turtle.end_fill()

def draw_mast():
    turtle.penup()
    turtle.goto(0, 50)
    turtle.pendown()
    turtle.color("black")
    turtle.width(5)
    turtle.forward(100)

def draw_joystick():
    turtle.penup()
    turtle.goto(0, 60)
    turtle.pendown()
    turtle.color("black")
    turtle.width(1)
    turtle.circle(10)

def main():
    turtle.speed(2)
    turtle.bgcolor("skyblue")

    draw_support()
    draw_base()
    draw_gondola()
    draw_mast()
    draw_joystick()

    turtle.hideturtle()
    turtle.done()

if __name__ == "__main__":
    main()

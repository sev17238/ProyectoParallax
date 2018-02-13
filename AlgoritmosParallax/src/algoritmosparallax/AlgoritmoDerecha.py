
//Algoritmo funcional en rur-ple que sige el principio de seguir siempre a la derecha
//para encontrar el camino hacia la salida del laberinto.

//Se define una funcion para girar a la derecha
def turn_right():
    turn_left()
    turn_left()
    turn_left()

//Mientras no haya un beeper. En este caso se pone un beeper en la salida del laberinto 
//para que reeborg se detenga al salir.
while not next_to_a_beeper():
    if front_is_clear():
        move()
    else:
        turn_left()
    if right_is_clear():
        turn_right()

//Una vez afuera reeborg es apagado.
turn_off()
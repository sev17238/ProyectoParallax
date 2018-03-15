/* 
 * Algoritmo de la mano derecha implementado en Rurple con un contador que permite salir de 
 * un loop probocado por una isla en un laberinto.
*/
count = 0
count2 = 0
#Funcion para dar vuelta
#a la derecha.
def turn_right():
    turn_left()
    turn_left()
    turn_left()
#Mientras reeborg no llege a un beeper,
#realizara las siguietnes instrucciones.
while not next_to_a_beeper():
    if front_is_clear():
        move()
    else:
        turn_left()
    if not front_is_clear():
        count = count +1
    if right_is_clear():
        #if count2 == 4 and count == 5:
        if count2 == count-1:
            turn_left()
            turn_left()
            count = 0
            count2 = 0
        else:
            turn_right()
            count2 = count2 + 1
            
            

#Al encontrar un beeper el ciclo while
#termina y reeborg se apaga.
turn_off()
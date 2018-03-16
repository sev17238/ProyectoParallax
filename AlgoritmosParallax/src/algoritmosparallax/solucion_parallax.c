
/*
 * Algoritmos y estructuras de datos
 * Proyecto Parallax, Resolucion de laberinto
 * Josue Lopez 17081
 * Paul Belches 17000
 * Diego Sevilla 17238
 */

//Librerias importadas
#include "simpletools.h"                       // Se incluye la libreria simpletools
#include "abdrive.h"                          // Se incluye la libreria de abdrive
#include "ping.h"                             // Si incluye la libreria del sensor ultrasonico

// Variables globales
int irLeft, irRight;                           // Se declaran las variables que representan los sensores infrarojos
int distance;                                   // Se declara la variable distancia

int main(){                                    // funcion principal

  low(26);                                      // Puertos D/A0 y D/A1 se inicializan en nivel bajo 0 voltios
  low(27);  
 
  while(1){
     freqout(11, 1, 28000);                      // lED infrarrojo inzquierdo
    irLeft = input(10);                         // Sensor infrarojo izquierdo en puerto 10

    freqout(1, 1, 28000);                       // se repite para el lado derecho
    irRight = input(2);
    
     distance = ping_cm(8);                    // se toma la distancia en cm del sensor Ping)))
    
    if(distance > 8){                         //Si no hay pared
      pause(10);
      drive_speed(64,64);                      // El robot abanza a 64 ticks/s
    }else{                                    //De lo contrario...
      drive_speed(0,0); 
      drive_goto(-26,25);                     //El robot voltea a la izquierda 
    }      
    if(irRight == 1){                         //Si no hay pared a la derecha
        drive_speed(0,0); 
        drive_goto(62,10);                     //El robot voltea a la derecha
        drive_speed(0,0);  
        //drive_goto(62,5);
        drive_goto(32,32);
    }
         
  }         
}  



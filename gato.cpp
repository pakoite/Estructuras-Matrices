
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int gato[3][3];
    int jugador = 1;
    int pc = 2;
    int turno;                 
    int x, y;
    int i, j;
    int ganador = 0;
    int casillas_ocupadas = 0;
    int puntos_jugador = 0;
    int puntos_pc = 0;

    srand(time(0)); // para random
    turno = rand() % 2 ? jugador : pc; // decide quien empieza

    // limpiar matriz
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            gato[i][j] = 0;
        }
    }

    while(1){
        // mostrar tablero
        printf("\nTablero:\n");
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                printf("[%d]", gato[i][j]);
            }
            printf("\n");
        }

        // turno del jugador o pc
        if(turno == jugador){
            printf("\nTurno del jugador (x y entre 0 y 2): ");
            scanf("%d %d",&x,&y);

            // validar rango
            if(x<0 || x>2 || y<0 || y>2){
                printf("Coordenadas fuera del rango!\n");
                continue;
            }
        } else {
            x = rand() % 3;
            y = rand() % 3;
             printf("\nTurno del PC: %d %d\n",x,y);
        }

        // si la casilla ya está ocupada
        if(gato[x][y] != 0){
              printf("Esa casilla ya esta ocupada!\n");
            continue;
        }

        // marcar casilla
        gato[x][y] = turno;
        casillas_ocupadas++;

        // revisar si alguien gana (a partir del 5° movimiento)
        if(casillas_ocupadas >= 5){
            for(i=0;i<3;i++){
                if(gato[i][0]==turno && gato[i][1]==turno && gato[i][2]==turno){
                    ganador = turno;
                }
                if(gato[0][i]==turno && gato[1][i]==turno && gato[2][i]==turno){
                    ganador = turno;
                }
            }
            if(gato[0][0]==turno && gato[1][1]==turno && gato[2][2]==turno){
                ganador = turno;
            }
            if(gato[0][2]==turno && gato[1][1]==turno && gato[2][0]==turno){
                ganador = turno;
            }
        }

        // si alguien ganó
        if(ganador != 0){
            if(ganador == jugador){
                printf("\nGano el jugador!\n");
                puntos_jugador++;
            } else {
                printf("\nGano la PC!\n");
                puntos_pc++;
            }

            printf("\nPuntuaciones -> Jugador: %d | PC: %d\n", puntos_jugador, puntos_pc);

            // reiniciar tablero
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    gato[i][j] = 0;
                }
            }

            ganador = 0;
            casillas_ocupadas = 0;
            turno = rand() % 2 ? jugador : pc;
            printf("\nReiniciando juego...\n");
            continue;
        }

        // si hay empate
        if(casillas_ocupadas == 9){
            printf("\nEmpate!\n");
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    gato[i][j] = 0;
                }
            }

            casillas_ocupadas = 0;
             ganador = 0;
            turno = rand() % 2 ? jugador : pc;
             printf("\nPuntuaciones -> Jugador: %d | PC: %d\n", puntos_jugador, puntos_pc);
            printf("\nReiniciando juego...\n");
            continue;
        }

        // cambiar turno
         if(turno == jugador){
            turno = pc;
        } else {
            turno = jugador;
        }
    }

    return 0;
}
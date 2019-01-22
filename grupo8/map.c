#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char resource;
	int amount;
} goods;

typedef struct {
	goods n, s, e, w;
	int player;
	char city;
} block;

typedef struct {
    int *block;
    int wool;
    int brick;
    int lumber;
    int grain;
    int iron;
    int desert;
    int points;
} player1;

typedef struct {
    int *block;
    int wool;
    int brick;
    int lumber;
    int grain;
    int iron;
    int desert;
    int points;
} player2;

int main(char *argv[]) {

	FILE *fp;
	char buff[255], good[2], rsrc[2];
	int xdim = 0;
	int ydim = 0;
	int pos;
    int i, j;
	int num;
	char run, a;
	run = a;
	block *map;


        fp = fopen("map.ini", "r");
        if (fp == NULL) {
            perror("Can't open INI");
            exit(1);
        }

        while(xdim == 0) {
            fscanf (fp, "%s\n", buff);
            if (strcmp(buff, "xdim")){
                xdim = buff[5] - '0';
            }
        }
        while(ydim == 0) {
            fscanf (fp, "%s\n", buff);
            if (strcmp(buff, "ydim")) ydim = buff[5] - '0';
        }
        //printf("xdim: %d, ydim: %d\n", xdim, ydim);

        map = (block*)calloc((xdim*ydim), sizeof(block));

        for(pos = 0; pos < (xdim * ydim); pos++) {
            //printf("pos = %d\n", pos);
            for(i = 0; i < 4; i++) {
                //printf("i = %d\n", i);
                num = 0;
                fscanf(fp, "%c=%c%d\n", good, rsrc, &num);
                //printf("%s: %s %d %d\n", good, rsrc, num, num > 0 ? num : 1);
                if (good[0] == 'N') {
                    map[pos].n.resource = rsrc[0];
                    map[pos].n.amount = num > 0 ? num : 0;
                }
                else if (good[0] == 'S') {
                    map[pos].s.resource = rsrc[0];
                    map[pos].s.amount = num > 0 ? num : 0;
                }
                else if (good[0] == 'E') {
                    map[pos].e.resource = rsrc[0];
                    map[pos].e.amount = num > 0 ? num : 0;
                }
                else if (good[0] == 'W') {
                    map[pos].w.resource = rsrc[0];
                    map[pos].w.amount = num > 0 ? num : 0;
                }
            }
        }


        /*for (int i=0; i<(xdim*ydim); i++) {
            int j = 0;
            printf("x = %d\n", i);
            while (j < ydim) {
                int i = 0;
                printf("y = %d\n", y);
                while (i<4) {
                    fscanf (fp, "%c=%c%d", left, right, num);
                    printf("%s, %s, %d\n", left, right, *num);
                    if (left == "N") {
                        map[x*ydim+y].n.resource = right;
                        map[x*ydim+y].n.amount = num;
                        i++;
                    }
                    if (left == "S") {
                        map[x*y+y].s.resource = right;
                        map[x*y+y].s.amount = num;
                        i++;
                    }
                    if (left == "E") {
                        map[x*y+y].e.resource = right;
                        map[x*y+y].e.amount = num;
                        i++;
                    }
                    if (left == "W") {
                        map[x*y+y].w.resource = right;
                        map[x*y+y].w.amount = num;
                        i++;
                    }
                    i++;
                }
                y++;
            }
        }*/
        //int i;
        /*for (i = 0; i<(xdim*ydim); i++)
        printf("%d N: %c %d S: %c %d E: %c %d W: %c %d\n", 0,
                map[i].n.resource, map[i].n.amount,
                map[i].s.resource, map[i].s.amount,
                map[i].e.resource, map[i].e.amount,
                map[i].w.resource, map[i].w.amount);*/
int turn = 1;
while (run == a){

       drawMap(xdim, ydim, map);
       options(turn, map);
       turn = (turn % 2) + 1;
        /*for (i=0; i<(xdim*ydim); i++) {
                printf("%2d N: %c %2d S: %c %2d E: %c %2d W: %c %2d\n", i,
                map[i].n.resource, map[i].n.amount,
                map[i].s.resource, map[i].s.amount,
                map[i].e.resource, map[i].e.amount,
                map[i].w.resource, map[i].w.amount);
        }*/
    }
}

int options(int turn, block *map)
{
  int player = 1;
  int i, c, o, roll, dice1, dice2;
  char option[2];
  srand(time(NULL));

  dice1 = ( 1 + (rand() % 6));
  dice2 = ( 1 + (rand() % 6));
  roll = (dice1+dice2);

  printf("It is... Player %d's turn.\n", turn);
  printf("Dice has been rolled. [%d]\n", roll);
  printf("Choose your option!\na = Village/City placements\nb = Village to City upgrade\nd = Turn in resources for points\n");
  scanf("%s", option);

  if(option[0] == 'a')
    {
      printf("Where do you want to put your village?\n");
      scanf("%d", &i);
      if (map[i].player != NULL)
        {
          printf("Oops. This place is occupied.\n");
          return 0;
        }

      else
        {
          map[i].player = turn;
          map[i].city = 1;
          return 0;
        }
    }
  else if (option[0] == 'b') {
      printf("Which village would you like to upgrade?\n");
      scanf("%d", &i);
      if(map[i].player != turn || map[i].city != 1) {
          printf("You must pick a village you own.\n");
          return 0;
      } else {
          map[i].city = 2;
          return 0;
      }
  } else if (option[0] == 'd') {
      printf("Which village/city and which resource would you like to turn in?\n");
  }
}

void drawMap(int xdim, int ydim, block *map)
{
    int i, j;
    for(i=0; i<xdim; i++){

        for(j=0; j<ydim; j++){printf("+-------------");}
        printf("\n");
        for(j=0; j<ydim; j++){printf("|     #%2d     ", i*ydim+j);}
        printf("\n");
        for(j=0; j<ydim; j++){printf("| N: %c (%2d)   ", map[i*ydim+j].n.resource, map[i*ydim+j].n.amount);}
        printf("\n");
        for(j=0; j<ydim; j++){printf("| S: %c (%2d)   ", map[i*ydim+j].s.resource, map[i*ydim+j].s.amount);}
        printf("\n");
        for(j=0; j<ydim; j++){printf("| E: %c (%2d)   ", map[i*ydim+j].e.resource, map[i*ydim+j].e.amount);}
        printf("\n");
        for(j=0; j<ydim; j++){printf("| W: %c (%2d)   ", map[i*ydim+j].w.resource, map[i*ydim+j].w.amount);}
        printf("\n");
        for(j=0; j<ydim; j++){
            if (map[i*ydim+j].player == 0 || map[i*ydim+j].city == 0){
                    printf("|             ");
            }
            else{
                printf("| PL%d   (%d)   ", map[i*ydim+j].player, map[i*ydim+j].city);
                }
            }
        printf("\n");
       //for(j=0; j<ydim; j++){
            //printf("| N: %c (%2d)   \n", map[i*ydim+j].n.resource, map[i*ydim+j].n.amount);
            //printf("| S: %c (%2d)   \n", map[i*ydim+j].s.resource, map[i*ydim+j].s.amount);
            //printf("| E: %c (%2d)   \n", map[i*ydim+j].e.resource, map[i*ydim+j].e.amount);
            //printf("| W: %c (%2d)   \n", map[i*ydim+j].w.resource, map[i*ydim+j].w.amount);
            //printf("| PL%d     (%c) \n", map[i].player, map[i].city);
        //}
    }
}

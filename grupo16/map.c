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
	int city;
} block;

int main(int argc, char *argv[]) {

	FILE *fp;
	char buff[255], good[2], rsrc[2];
	char *c;
	int xdim = 0;
	int ydim = 0;
	int pos;
    int i;
	int num;
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
	printf("xdim: %d, ydim: %d\n", xdim, ydim);

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
                map[pos].n.amount = num > 0 ? num : 1;
            }
            else if (good[0] == 'S') {
                map[pos].s.resource = rsrc[0];
                map[pos].s.amount = num > 0 ? num : 1;
            }
            else if (good[0] == 'E') {
                map[pos].e.resource = rsrc[0];
                map[pos].e.amount = num > 0 ? num : 1;
            }
            else if (good[0] == 'W') {
                map[pos].w.resource = rsrc[0];
                map[pos].w.amount = num > 0 ? num : 1;
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


	for (i=0; i<(xdim*ydim); i++) {
		printf("%2d N: %c %2d S: %c %2d E: %c %2d W: %c %2d\n", i,
			map[i].n.resource, map[i].n.amount,
			map[i].s.resource, map[i].s.amount,
			map[i].e.resource, map[i].e.amount,
			map[i].w.resource, map[i].w.amount);
	}
}

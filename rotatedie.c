#include <stdio.h>


int die[5];

enum INDECES  {CURR = 0, NORTH = 1, SOUTH = 2, EAST = 3, WEST = 4};

void outState(void)
{
	printf ("CURR: %d  NORTH: %d  SOUTH: %d  EAST  %d   WEST: %d\n", 
		die[CURR], die[NORTH], die[SOUTH], die[EAST], die[WEST]);

}

int main (void)
{
	int dir, oppDir;

	die[CURR] = 0;
	die[NORTH] = 3;
	die[SOUTH] = 2;
	die[EAST] = 1;
	die[WEST] = 4;

	die[CURR] = 2;
	die[NORTH] = 0;
	die[SOUTH] = 5;
	die[EAST] = 4;
	die[WEST] = 1;

	dir = NORTH;
	oppDir = SOUTH;
	

	outState();
	die[dir] = die[CURR];
	die[CURR] = die[oppDir];
	die[oppDir] = 5 - die[dir];	

	outState();

	die[dir] = die[CURR];
	die[CURR] = die[oppDir];
	die[oppDir] = 5 - die[dir];	
	
	outState();
	die[dir] = die[CURR];
	die[CURR] = die[oppDir];
	die[oppDir] = 5 - die[dir];	
	
	outState();
	die[dir] = die[CURR];
	die[CURR] = die[oppDir];
	die[oppDir] = 5 - die[dir];	
	
	outState();


/*

	curr = $80	; 
	dir = $85	; 

	ldx CURR		;
	lda curr, x	; 
	ldx dir			; die[dir] = die[CURR];
	sta curr, x	; 

	ldx oppDir		;
	lda arrayaddr, x	;
	ldx curr		; die[curr] = die[oppdir]
	sta arrayaddr, x	;

	ldx dir
	lda #5
	sec
	sbc curr,x
	ldx oppDir
	sta curr, x
	


	

	


*/
	

	return 0;
}

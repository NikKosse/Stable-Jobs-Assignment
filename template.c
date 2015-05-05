#include <stdio.h>
 
int verbose = 1;
enum {
	clown = -1, //used to set a person as not engaged or married to anyone
	abe, bob, col, dan, ed, fred, gav, hal, ian, jon, //each person is assigned to a number, abe = 0, jan = 19
	abi, bea, cath, dee, eve, fay, gay, hope, ivy, jan,
};
const char *name[] = {
	"Abe", "Bob", "Col",  "Dan", "Ed",  "Fred", "Gav", "Hal",  "Ian", "Jon",
	"Abi", "Bea", "Cath", "Dee", "Eve", "Fay",  "Gay", "Hope", "Ivy", "Jan"
};
int pref[jan + 1][jon + 1] = {
	{ abi, eve, cath, ivy, jan, dee, fay, bea, hope, gay },//Abe's prefrences
	{ cath, hope, abi, dee, eve, fay, bea, jan, ivy, gay },//Bob's prefrences
	{ hope, eve, abi, dee, bea, fay, ivy, gay, cath, jan },//Col's prefrences
	{ ivy, fay, dee, gay, hope, eve, jan, bea, cath, abi },//Dan's prefrences
	{ jan, dee, bea, cath, fay, eve, abi, ivy, hope, gay },//Ed's prefrences
	{ bea, abi, dee, gay, eve, ivy, cath, jan, hope, fay },//Fred's prefrences
	{ gay, eve, ivy, bea, cath, abi, dee, hope, jan, fay },//Gav's prefrences
	{ abi, eve, hope, fay, ivy, cath, jan, bea, gay, dee },//Hal's prefrences
	{ hope, cath, dee, gay, bea, abi, fay, ivy, jan, eve },//Ian's prefrences
	{ abi, fay, jan, gay, eve, bea, dee, cath, ivy, hope },//Jon's prefrences
 
	{ bob, fred, jon, gav, ian, abe, dan, ed, col, hal   },//Abi's prefrences
	{ bob, abe, col, fred, gav, dan, ian, ed, jon, hal   },//Bea's prefrences
	{ fred, bob, ed, gav, hal, col, ian, abe, dan, jon   },//Cath's prefrences
	{ fred, jon, col, abe, ian, hal, gav, dan, bob, ed   },//Dee's prefrences
	{ jon, hal, fred, dan, abe, gav, col, ed, ian, bob   },//Eve's prefrences
	{ bob, abe, ed, ian, jon, dan, fred, gav, col, hal   },//Fay's prefrences
	{ jon, gav, hal, fred, bob, abe, col, ed, dan, ian   },//Gay's prefrences
	{ gav, jon, bob, abe, ian, dan, hal, ed, col, fred   },//Hope's prefrences
	{ ian, col, hal, gav, fred, bob, abe, ed, jon, dan   },//Ivy's prefrences
	{ ed, hal, gav, abe, bob, jon, col, ian, fred, dan   },//Jan's prefrences
};
int pairs[jan + 1], proposed[jan + 1];
 
//function to take in a man and a woman and pair them together
void engage(int man, int woman)
{
	pairs[man] = woman;
	pairs[woman] = man;
	if (verbose) printf("%4s is engaged to %4s\n", name[man], name[woman]);
}
 
//function to take a man and a woman and set them back to unmarried
void dump(int woman, int man)
{
	pairs[man] = pairs[woman] = clown;
	if (verbose) printf("%4s dumps %4s\n", name[woman], name[man]);
}
 
//function to determine how desireable a person is to a given suitor
/* how high this person ranks that: lower is more preferred */
int rank(int this, int that)
{
	int i;
	for (i = abe; i <= jon && pref[this][i] != that; i++);
	return i;
}

//function to propose a marriage between two people. 
void propose(int man, int woman)
{
	int fiance = pairs[woman];
	if (verbose) printf("%4s proposes to %4s\n", name[man], name[woman]);
 
	if (fiance == clown) {//if they aren't married
		engage(man, woman);
	} else if (rank(woman, man) < rank(woman, fiance)) {//check rank and accept or reject based on that
		dump(woman, fiance);//dump current fiance
		engage(man, woman);//make new one
	}
}

//function to compare one man and wife with the rest and check the prefrences of each member
int covet(int man1, int wife2)
{
	if (rank(man1, wife2) < rank(man1, pairs[man1]) &&
			rank(wife2, man1) < rank(wife2, pairs[wife2])) {
		printf( "    %4s (w/ %4s) and %4s (w/ %4s) prefer each other"
			" over current pairing.\n",
			name[man1], name[pairs[man1]], name[wife2], name[pairs[wife2]]
		);
		return 1;
	}
	return 0;
}

//function to take in two men and pass them to covet
int thy_neighbors_wife(int man1, int man2)
{	/* +: force checking all pairs; "||" would shortcircuit */
	return covet(man1, pairs[man2]) + covet(man2, pairs[man1]);
}

//function to check if the marriages are stable
int unstable()
{
	int i, j, bad = 0;
	for (i = abe; i < jon; i++) {//nested loops to check all the prefrences of each person
		for (j = i + 1; j <= jon; j++)
			if (thy_neighbors_wife(i, j)) bad = 1;//check if there exists a couple who both covet the other's SO
	}
	return bad;
}

 
int main()
{
	int i, unengaged;
	/* init: everyone marries the clown */
	for (i = abe; i <= jan; i++)
		pairs[i] = proposed[i] = clown;
 
	/* rounds */
	int bleh = 0;
	do {
		if(verbose) printf("Iteration: %d\n", bleh++);
		unengaged = 0;
		for (i = abe; i <= jon; i++) {
if (pairs[i] != clown) continue;
			unengaged = 1;
			propose(i, pref[i][++proposed[i]]);
		}
	} while (unengaged);
 
	printf("Pairing:\n");
	for (i = abe; i <= jon; i++)
		printf("  %4s - %s\n", name[i],
			pairs[i] == clown ? "clown" : name[pairs[i]]);
 
	printf(unstable()
		? "Marriages not stable\n" /* draw sad face here */
		: "Stable matchup\n");
 
	printf("\nBut if Bob and Fred were to swap:\n");
	i = pairs[bob];
	engage(bob, pairs[fred]);
	engage(fred, i);
	printf(unstable() ? "Marriages not stable\n" : "Stable matchup\n");
 
	return 0;
}

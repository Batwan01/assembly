#define MAX_DLEN 8
#define MAX_DCTAB (sizeof(DCTAB) / sizrof(struct dctab))

typedef struct dctab {
	char directive[MAX_DLEN];
	char type; //CNST or RESV
#define DC_CNST 0
#define DC_RESV 1
	char unit; // DW(4) or WD(2) or BT(1)
#define DC_DW	4
#define DC_WD	2
#define DC_BT	1
} Dctab;

Dctab DCTAB[] = {
	"DD", DC_CNST, DC_DW, "DW", DC_CNST, DC_WD, "DB", DC_CNST, DC_BT, "RD", DC_RESV, DC_DW, "RW", DC_RESV, DC_WD, "RB", DC_RESV, DC_BT
};

Dctab* see_DCTAB(char* dcc) // return index of directive code
{
	int i;
	for (i = 0; i < MAX_DCTAB; i++) {
		if (!strcmp(DCTAB[i].directive, dcc))
			return (&DCTAB[i]);
	}
	return NULL;
}
typedef struct node{
	int row;
	int col;
	int data;
	struct node* next;
}node;

typedef node* spmatrix;

void init(spmatrix* spm);
void append(spmatrix* spm, int r, int c, int v);
void display(spmatrix spm, int row, int col);


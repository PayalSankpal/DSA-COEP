#define PLUS 100
#define MINUS -100

typedef struct number{
    node* p;
    int sign;
    int dec;
} number;

void init_num(number* n);
char storenumber(number* n);
void displaynumber(number num);
int greaterthan(number* num1, number* num2);
int isEqual(number* num1, number* num2);
number* subtractnumbers(number* num1, number* num2);
number* addnumbers(number* num1, number* num2);
number* mulnumbers(number* num1, number* num2);
int isZero(number* num1);
number* divnumbers(number* num1, number* num2);
number* modulus(number* num1, number* num2);
number* expo(number* num1, number* num2);


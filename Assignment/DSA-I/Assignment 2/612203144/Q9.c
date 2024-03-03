#include<stdio.h>
#define PI 3.1427

float power(float a, float b);
int fact(int a);

float sine(float rad);
float cosine(float rad);
float exponential(int x);

int main(){
	int deg=30, x=30;
	float rad, sin, cos, exp;


	rad= deg*(PI/180);


	sin=sine(rad);
	cos=cosine(rad);
	exp=exponential(x);


	printf("sin%d = %f\n", deg, sin);
	printf("cos%d = %f\n", deg, cos);
	printf(" e^(%d) = %f", x, exp);	


	return 0;
}

float power(float a, float b){
	float pow=1;
	for(b; b>0; b--){
		pow*=a;
	}
	return pow;
}

int fact(int a){
	int fact=1; 
	for (a; a>0; a--){
		fact*=a;
	}
	return fact;
}
	

float sine(float rad){
	int i;
	float sin=rad, term, powerterm, factorialterm;
	for(i=1; i<10; i++){
		powerterm = power(rad, 2*i+1);
		factorialterm = fact(2*i+1);
		term = powerterm/factorialterm;
		sin+=power(-1,i)*term;
	}
	return sin;	
}

float cosine(float rad){
	int i;
	float cos=1, term, powerterm, factorialterm;
	for(i=1; i<10; i++){
		powerterm = power(rad,2*i);
		factorialterm = fact(2*i);
		term = powerterm/factorialterm;
		cos+=power(-1,i)*term;
	}
	return cos;	
}

float exponential(int x){
	int i;
	float exp=1, term, powerterm, factorialterm;
	for(i=1; i<10; i++){
		powerterm = power(x,i);
		factorialterm = fact(i);
		term = powerterm/factorialterm;
		exp+=term;
	}
	return exp;
}

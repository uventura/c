/**@file: newton-raphson.c
 * @author: Ualiton Ventura da Silva
 * @disciplina: Algoritmos e Programação de Computadores
 *
 * Objetivo: Descobrir uma raiz de uma função utilizando
 * o método de Newton-Raphson. */

#include <stdio.h>

float modulo(float n)
{
	if(n > 0)
		return n;
	return -n;
}

float exponencial(float x, int n)
{
	if(n == 0)
		return 1;
	return x * exponencial(x, n - 1);
}

float polinomial(int grau, float x, float *coefs)
{
	int i;
	float resultado = 0;

	for(i = 0; i < grau+1; i++)
	{
		resultado += exponencial(x, grau - i) * coefs[i];
	}

	return resultado;
}

void exibe_polinomial(int grau)
{
	int i;

	for(i = 0; i < grau; i++)
	{
		printf("(a%d)(x^%d) + ", i,grau - i);
	}

	printf(" a%d\n", grau);
}

float newton_raphson(int grau, float *coefs, float *coefs_linha)
{
	/*
		Coeficientes de f(x) => coefs;
		Coeficientes de f'(x) => coefs_linha
	*/

	int i = 0, tentativas = 1000;

	float x = 1;
	float derivada, func;

	while(i < tentativas && modulo(polinomial(grau, x, coefs)) > 0.0001)
	{
		func = polinomial(grau, x, coefs);
		derivada = polinomial(grau-1, x, coefs_linha);
		
		if(derivada != 0)
			x = x - (func / derivada);
		i++;
	}

	return x;
}

int main()
{
	int grau, i;

	printf("Digite o grau da funcao: ");
	scanf("%d", &grau);

	printf("\n  Sua funcao e do tipo f(x) = ");
	exibe_polinomial(grau);

	float coef[grau+1], coef_linha[grau];
	printf("\nDê seus coeficientes: \n");
	
	for(i = 0; i < grau+1; i++)
	{
		printf("  a%d:", i);
		scanf("%f", &coef[i]);

		if(i != grau)
			coef_linha[i] = (grau-i) * coef[i];
	}

	printf("\n-> Raiz Aproximada: %.5f\n", newton_raphson(grau, coef, coef_linha));

	return 0;
}
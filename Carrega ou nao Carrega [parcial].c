//https://www.urionlinejudge.com.br/judge/pt/problems/view/1026

#define alocar_vetor(quantidade, tamanho) calloc(quantidade, tamanho)
#define testar_alocacao(vetor) if(vetor == NULL){printf("Erro de alocacao. O programa sera finalizado\n");return 1;}
#define _bits 32
#include <stdio.h>
#include <stdlib.h>

/**
 * Converte um numero binario para decimal.
 * @param numero[] sequencia de bits do numero a ser convertido.
 * @return o numero decimal que representa o binario convertido.
 */
int converter_binario_decimal(int numero[]){
	int i, decimal = 0, fator = 1;
	for(i = _bits - 1; i >= 0; i--){
		decimal += numero[i] * fator;
		fator *= 2;
	}
	return decimal;
}

/**
 * Converte um numero decimal para binario.
 * @param numero o numero a ser convertido.
 */
void converter_decimal_binario(int numero, int vetor[]){
	int i = _bits - 1;
	while(numero != 0){
		vetor[i] = numero % 2;
		numero /= 2;
		i--;
	}
}

/**
 * Soma dois numeros binarios.
 * @param vetorum[] primeiro termo da soma.
 * @param vetordois[] segundo termo da soma.
 */
void somar_binarios(int vetorum[], int vetordois[]){
	int i;
	for(i = 0; i < _bits; i++)
		vetorum[i] == vetordois[i] ? (vetorum[i] = 0) : (vetorum[i] = 1);
}

/**
 * Preenche um vetor com numeros zero.
 * @param vetor[] o vetor a ser preenchido.
 */
void zerar_vetor(int vetor[]){
	int i;
	for(i = 0; i < _bits; i++)
		vetor[i] = 0;
}

int main(){
	int num, ndois, i;
	int *vum, *vdois;
	vum = (int *) alocar_vetor(_bits, sizeof(int));
	testar_alocacao(vum);
	vdois = (int *) alocar_vetor(_bits, sizeof(int));
	testar_alocacao(vdois);
	while(scanf("%d %d", &num, &ndois) != EOF){
		converter_decimal_binario(num, vum);
		converter_decimal_binario(ndois, vdois);
		somar_binarios(vum, vdois);
		num = converter_binario_decimal(vum);
		printf("%d\n", num);
		zerar_vetor(vum);
		zerar_vetor(vdois);
	}
	free(vum);
	free(vdois);
	vum = vdois = NULL;
	return 0;
}
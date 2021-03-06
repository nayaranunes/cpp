/*
São dadas 3 pilhas de blocos. Cada pilha tem uma quantidade X de blocos 
e cada bloco tem uma altura H. As pilhas, eventualmente, terão alturas diferentes, 
já que os blocos que as formam são diferentes. No entanto, qual a maior altura 
que é possível deixar as três pilhas, de forma que todas tenham a mesma altura?

Exemplo: suponha uma primeira pilha formada por 5 blocos. 
Os três primeiros blocos tem altura 1, o quarto tem altura 2 e o quinto tem altura 3. 
A altura dessa pilha, portanto, é 8. Agora uma segunda pilha formada por 3 blocos. 
Um de altura 2, outro de altura 3, outro de altura 4. A altura dessa segunda pilha é 9. 
E por último, a terceira pilha formada de 4 blocos. O primeiro de altura 1, 
o segundo de altura 4, e os dois últimos de altura 1 cada. A altura dessa pilha é 7.

Qual a maior altura que é possível deixar as 3 pilhas, de forma que todas tenham a mesma altura?

Resposta: 5

Na primeira pilha, tiramos o bloco de tamanho 3, que é o bloco que está no topo da pilha. 
Só se pode tirar o bloco que está no topo. E aí a pilha 1 fica com tamanho 8 - 3 = 5
Na segunda pilha, tiramos o bloco de tamanho 4, que também é o que está no topo. 
E então a segunda pilha fica com altura 9 - 4 = 5. A terceira pilha nós primeiro 
tiramos o bloco de tamanho 1, que está no topo, para depois podermos tirar o outro bloco de tamanho 1. 
Nesse caso a pilha fica com tamanho 7 - 2 = 5

E então todas tem tamanho 5, que é o maior tamanho de forma que as pilhas fiquem iguais.
A entrada é dada da seguinte forma:
Na primeira linha, há tres inteiros N1, N2, N3, representando, respectivamente, 
a quantidade de blocos da primeira, segunda e terceira pilhas.
Depois, haverá três linhas. A primeira, dessas três, contém N1 inteiros, 
sendo que eles representam a altura dos blocos da primeira pilha.
A segunda tem N2 inteiros, e a terceira N3, funcionando de forma análoga.

A saída deve ser um número inteiro H, que é a maior altura que é possível deixar as três pilhas.

Para esse caso, a entrada seria dada assim:
5 3 4
3 2 1 1 1
4 3 2
1 1 4 1

E a saída:
5
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int N1, N2, N3, H1 = 0, H2 = 0, H3 = 0;
	cin >> N1 >> N2 >> N3;

	vector<int> n;
	
	stack<int> pilha1;
	stack<int> pilha2;
	stack<int> pilha3;

	for (int i = 0; i < N1; i++) {

		int a;
		cin >> a;
		H1 += a;
		n.push_back(a);	
	}

	for (int j = 0; !n.empty(); j++) {
		pilha1.push(n[n.size()-1]);
		n.pop_back();
	}

	for (int i = 0; i < N2; i++) {
						
		int a;
		cin >> a;
		H2 += a;
		n.push_back(a);
	}

	for (int j = 0; !n.empty(); j++) {
		pilha2.push(n[n.size()-1]);
		n.pop_back();
	}

	for (int i = 0; i < N3; i++) {
						
		int a;
		cin >> a;
		H3 += a;
		n.push_back(a);
	}

	for (int j = 0; !n.empty(); j++) {
		pilha3.push(n[n.size()-1]);
		n.pop_back();	
	}
	
	while (!(H1 == H2 && H1 == H3)) {

		if (H1 > H2 && H1 > H3) {
			H1 -= pilha1.top();
			pilha1.pop();
		} else {
			if (H2 > H3) {		
				H2 -= pilha2.top();
				pilha2.pop();
			} else {
			
				H3 -= pilha3.top();
				pilha3.pop();
			}
		}
	}

	cout << "H pilha1 = " << H1 << endl;
	cout << "H pilha2 = " << H2 << endl;
	cout << "H pilha3 = " << H3 << endl;
	
	return 0;
}

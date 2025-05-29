#include <stdio.h>
#include <limits.h>

//Equipe: Amanda, Diogo, Hiago

//Programação dinamica - Seleção dos pacotes

struct pacote {
	int peso;
	int volume;
	int dia_de_entrega;
};

struct caminhao{
	int capacidade_de_carragamento;
	int numero_identificador;
	pacote pacotes_que_serao_levados[];
};


void carregarCaminhoes(caminhao caminhoes[], pacote pacotes[])
{
	pacote tabela_de_pacotes[];
	pacote pacotes_disponiveis[] = pacotes;
	caminhao caminhao_atual;
	pacote pacotes_que_serao_levados[];
	for(int i=0; i < sizeof(caminhoes); i++)
	{
		caminhao_atual = caminhoes[i];
		tabela_de_pacotes = preencherTabelaDeCarregamento(caminhao_atual, pacotes_disponiveis);
		pacotes_que_serao_levados = tabela_de_pacotes[len(tabela_de_pacotes) - 1][camihao_atual.capacidade_de_carregamento - 1];
		caminhao_atual.pacotes_que_serao_levados = pacotes_que_serao_levados;
		printf("Caminhao %d - Pacotes...", caminhao.numero_identificador);
		for(int k = 0; k < len(pacotes_que_serao_levados); k++)
		{
			pacote pkg = caminhao_atual.pacotes_que_serao_levados[k];
			printf("Pacote - ( kg = %d ); ( dia = %d) ", pkg.peso, pkg.dia_de_entrega);
		}
		pacotes_disponiveis = retirarPacotesPostosNoCaminhaoDosPacotesDisponiveis(pacotes_disponiveis, pacotes_que_serao_levados);
	}
}


pacote[] inicializaTabelaDePacotes(int numero_de_pacotes, int capacidade_de_carregamento){
	pacote tabela_inicial_pacotes[numero_de_pacotes][capacidade_de_carregamento];
	pacote pkg_ini;
	pkg_ini.peso = INT_MAX;
	for(int i = 0; i < numero_de_pacotes; i++)
	{
		for(int j = 0; j < capacidade_de_carregamento; j++)
		{
			tabela_inicial_pacotes[i][j] = pkg_ini;
		}
	}
	return tabela_inicial_pacotes;
}

int somaDosDiasDeEntrega(int indice, pacote tabela_de_pacotes[][])
{
	pacote pacotes = tabela_de_pacotes[indice];
	int soma_dias = 0;
	for(int i = 0; i < len(pacotes); i++)
	{
		soma_dias += pacotes[i].dia_de_entrega;
	}
	return soma_dias;
}

void preencherTabelaDeCarregamento(caminhao *caminhao, pacote pacotes_disponiveis[])
{
	pacote pacote_atual;
	pacote tabela_de_pacotes[] = inicializaTabelaDePacotes(len(pacotes_disponiveis),caminhao.capacidade_de_carragamento);
	int carga_atual;
	for(int i = 0; i < len(pacotes_disponiveis); i++)
	{
		pacote = pacotes_disponiveis[i];
		carga_atual = 1;
		while(carga_atual <= caminhao.capacidade_de_carragamento)
		{
			if(pacote.peso < carga_atual)
			{
				if(somaDosDiasDeEntrega(carga_atual - pacote.peso - 1, tabela_de_pacotes) + pacote.dia_de_entrega <= somaDosDiasDeEntrega(carga_atual, tabela_de_pacotes))
				{
					pacote novos_pacotes[len(tabela_de_pacotes[carga_atual - pacote.peso -1]) + 1]
					novos_pacotes = tabela_de_pacotes[carga_atual - pacote.peso -1];
					novos_pacotes[len(novos_pacotes) - 1] = pacote;
					tabela_de_pacotes[carga_atual] = novos_pacotes;
				} 
			}
	
			if(pacote.peso == carga_atual)
			{
				if(pacote.dia_de_entrega < somaDosDiasDeEntrega(carga_atual, tabela_de_pacotes))
				{
					tabela_de_pacotes[carga_atual] = pacote;
				}
			} 
			carga_atual += 1;
		}	
	}		
}


int main()
{
	caminhao caminhao_1;
	caminhao_1.capacidade_de_carragamento = 5;
	
	caminhao caminhao_2;
	caminhao_2.capacidade_de_carragamento = 4;
	
	pacote pacote_1;
	pacote_1.peso = 1;
	pacote_1.dia_de_entrega = 3;
	
	
	pacote pacote_2;
	pacote_2.peso = 3;
	pacote_2.dia_de_entrega = 2;
	
	
	pacote pacote_3;
	pacote_3.peso = 2;
	pacote_3.dia_de_entrega = 1;
	
	caminhao frota_de_caminhoes[2] = {caminhao_1, caminhao_2};
	pacote pacotes[3] = {pacote_1, pacote_2, pacote_3};
	
	
	carregarCaminhoes(frota_de_caminhoes, pacotes);
	
	
	
	
	
	return 0;
}

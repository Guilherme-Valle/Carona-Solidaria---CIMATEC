#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct carro {
	char placacarro [9];
	char modelocarro [15];
	char corcarro [10];
	int anocarro;
};
struct endereco {
	char bairro [30];
	char complemento [35];
};
struct usuarios {
	
	char nome [30];
	int cpf;
	int senha;
	char email [30];
	struct carro car;
	struct endereco end;
	char numerocelular [10];
	float nota;
	int dispmot;
	int dispcarona;
	int registmotorista;	
	int carro;
	int numviagens;
};

int motorista (struct usuarios vetmotorista[], int jy){
	system ("cls");
	int u, z,i, o=25, nuta;
	do {	
	if (vetmotorista[jy].carro == 0){
		system ("cls");
		printf ("Você não registrou um carro, para atuar como motorista.\n\n");
		break;
	}
	printf(" #         #                                                   \n");
    printf(" ##       ##    ###  #####  ###   #####  #  ### #####    #     \n");
    printf(" # #     # #   #   #   #   #   #  #   #  # #      #     # #    \n");
    printf(" #  #   #  #   #   #   #   #   #  ####   #  ###   #    #   #   \n");
    printf(" #   # #   #   #   #   #   #   #  #   #  #     #  #   #######  \n");
    printf(" #    #    #    ###    #    ###   #    # #  ###   #  #       # \n");
    printf("\n");
	printf ("\n\n|======== Bem vindo, usuário %s ! Você realizou login como motorista ========|\n", vetmotorista[jy].nome);
	printf ("Para escolher uma opção do menu, digite o número correspondente\n\n|==== 1 - Fornecer carona ====|\n|===== 2 - Solicitações de carona =====|\n");
	printf ("|===== 3 - Verificar sua avaliação =====|\n\n Digite 0 para voltar ao menu principal.");
	scanf ("%d", &o);
	switch (o)
	{
		case 1: 
				system ("cls");
				fflush (stdin);
				if (vetmotorista[jy].dispmot == 0){
					printf ("Agora você está disponível para fornecer caronas! Receberá solicitações dos usuários que o requisitarem.");
					vetmotorista[jy].dispmot = 1;
					} else if (vetmotorista[jy].dispmot == 2) {
						printf ("Você está, atualmente, fornecendo carona para a instituição CIMATEC \n \n Deseja encerrar a viagem? Caso sim, digite 1. \n");
						scanf ("%d", &u);
						if (u == 1){
							system ("cls");
							printf ("Avalie seu passageiro! Digite a nota dele\n");
							scanf ("%f", &nuta);
							if (nuta >= 0 && nuta <= 5){
							vetmotorista[jy].nota =+ nuta;
							vetmotorista[jy].dispmot = 0;
							vetmotorista[jy].numviagens++;
						} else { 
							printf ("Sua nota foi inválida! Iremos considerar ela como 0. \n");
							vetmotorista[jy].dispmot = 0;
							vetmotorista[jy].numviagens++;
						}
				}					
			} else {
				printf ("\n\nVocê está com a carona em aberto! Vá até a tela de solicitações de carona, para escolher um caroneiro\n");
			}
				break;				
		case 2:  
				system ("cls");
				printf ("Aqui estão suas solicitações de carona \n\n");
				for (i = 0; i < 100; i++){ 
					if (vetmotorista[i].dispcarona == 1){
						
						printf ("Nome do caroneiro: %s \n Número do celular: %s \n E-mail: %s \n", vetmotorista[i].nome, vetmotorista[i].numerocelular,  vetmotorista[i].email);
						printf ("Endereço: %s \n Complemento do endereço: %s \n\n",  vetmotorista[i].end.bairro, vetmotorista[i].end.complemento);
						printf ("Avaliação do usuário: %f", vetmotorista[i].nota/vetmotorista[i].numviagens);
						printf ("Deseja fornecer carona solidária para este usuário? \n Digite 1 para fornecer.");
						scanf ("%d", &z);
						if (z == 1){
							vetmotorista[jy].dispmot = 2;
							vetmotorista[i].dispcarona = 2;
							vetmotorista[i].registmotorista = jy; // O número, no caso, corresponde a posição dos vetores, para que os perfis respectivos possam ser chamados em qualquer momento nas diferentes functions
							vetmotorista[jy].registmotorista = i;
						} else {
							printf ("Usuário recusado \n\n");
						}	
					}
				}				
				break;				
		case 3: 
				system ("cls");
				printf ("Sua avaliação, de 1 a 5 estrelas, segundo os usuários, corresponde a \n: %f estrelas!", vetmotorista[jy].nota/vetmotorista[jy].numviagens);
				
			
				break;
				
		default:
				printf ("Opção inválida!");
				system ("cls");
				break;						
		}
	} while (o != 0); 
}

int carona (struct usuarios vetcarona[], int jj){
	system ("cls");
	int r = 1, ki, viaj, yp, canc, notaa;
	do {	
	system ("cls");
	printf ("\n\n |======== Bem vindo, usuário %s, você realizou login como caroneiro! ========|\n\n", vetcarona[jj].nome);
	if (vetcarona[jj].dispcarona == 0){
			printf ("=== Atualmente disponível ===\nPara escolher uma opção do menu, digite o número correspondente\n\n|==== 1 - Solicitar carona ====|\n|===== 2 - Verificar sua avaliação =====|\n |==== 3 - Alterar endereço ====|\n \n");
		} else if (vetcarona[jj].dispcarona == 2){
			 printf ("=== Atualmente recebendo carona ===\nPara escolher uma opção do menu, digite o número correspondente\n\n|==== 1 - Carona atual ====|\n|===== 2 - Verificar sua avaliação =====|\n |==== 3 - Alterar endereço ====|\n\n");
		} else {
			printf ("=== Carona solicitada ===\nPara escolher uma opção do menu, digite o número correspondente\n\n|==== 1 - Cancelar solicitação ====|\n|===== 2 - Verificar sua avaliação =====|\n |==== 3 - Alterar endereço ====|\n \n");
		}
	printf ("Digite 0 para voltar para o menu principal\n");
	scanf ("%d", &r);
	switch (r)
	{
		case 1:
				if (vetcarona[jj].dispcarona == 0){
					system ("cls");
					printf ("Deseja solicitar uma carona? \n Você irá realizar uma solicitação para os motoristas disponíveis\n");
					printf ("Digite 1 para solicitar\n");
					scanf ("%d", &ki);
					if (ki == 1){
					printf ("Solicitação realizada! Aguarde algum motorista aceitar você\n");
						vetcarona[jj].dispcarona = 1;
					}
				} else if (vetcarona[jj].dispcarona == 2){
					system ("cls");
					printf ("Sua viagem atual é com o motorista de seguintes informações: \n Nome do motorista: %s \n Destino: CIMATEC \n  E-mail do motorista: %s\n", vetcarona[vetcarona[jj].registmotorista].nome, vetcarona[vetcarona[jj].registmotorista].email);
					printf ("Placa do carro: %s \n Modelo do carro: %s \n Cor do carro: %s \n Celular do motorista: %s \n ", vetcarona[vetcarona[jj].registmotorista].car.placacarro, vetcarona[vetcarona[jj].registmotorista].car.modelocarro, vetcarona[vetcarona[jj].registmotorista].car.corcarro, vetcarona[vetcarona[jj].registmotorista].numerocelular);
					printf ("Avaliação do motorista: %d\n\n", vetcarona[vetcarona[jj].registmotorista].nota/vetcarona[vetcarona[jj].registmotorista].numviagens);
					printf ("A viagem já foi encerrada? Digite 1 se sim");
					scanf ("%d", &viaj);
					if (viaj == 1){
						vetcarona[jj].dispcarona = 0;
						printf ("Avalie o seu motorista. Digite seu número de estrelas, de 1 a 5 \n");
						scanf ("%f", &notaa);
						if (notaa >= 0 && notaa <= 5){
							vetcarona[vetcarona[jj].registmotorista].nota = notaa;
							vetcarona[jj].numviagens++;
						} else {
							system ("cls");
							printf ("A nota é inválida, consideraremos a nota como 0!");
							vetcarona[jj].numviagens++;
						}
						
						
					}
					
				} else {
					system ("cls");
					printf ("\nDeseja cancelar a solicitação de carona? \n Digite 1 para cancelar\n");
					scanf ("%d", &canc);
					system ("cls");
					if (canc == 1){
						printf ("Sua solicitação foi cancelada!\n");
						vetcarona[jj].dispcarona = 0;
						
					}
				} 
				
				break;
		case 2:
				system ("cls");
				printf ("Sua avaliação pelos outros usuários é : %f \n ", vetcarona[jj].nota/vetcarona[jj].numviagens);
				break;
		
		case 3: 
				system ("cls");
				printf ("Deseja alterar seu endereço? Digite 1 se sim \n \n");
				scanf ("%d", &yp);
				if (yp == 1){
					printf ("Digite seu novo endereço \n Digite o bairro \n");
					fflush (stdin);
					fgets (vetcarona[jj].end.bairro, 30, stdin);
					fflush (stdin);
					printf ("\n Agora o complemento do endereço");
					fgets (vetcarona[jj].end.complemento, 35, stdin);
					fflush (stdin);
					
				} 
				
				break;
				
		default:
				system ("cls");
				printf ("Opção inválida!");
				
				break;
				
			}
				
	
	
	
	} while (r != 0);
}

int tela1 (struct usuarios vetor1[], int j){
	int choose;
	system("cls");
	printf("Login realizado com sucesso!\n");
	printf("\n");
    printf("&&&&   &&&&  &       &       &       &  &  &   &  &&&&&    &&&  \n");
    printf("&   &  &     &&     &&        &     &   &  &&  &  &    &  &   & \n");
    printf("&&&&   &&&&  & &   & &   &&&   &   &    &  & & &  &    &  &   & \n");
    printf("&   &  &     &  & &  &   &&&    & &     &  &  &&  &    &  &   & \n");
    printf("&&&&   &&&&  &   &   &           &      &  &   &  &&&&&    &&&  \n");
	printf("\n");
	printf("%s",vetor1[j].nome);
	printf("========= \nVocê agora, deve selecionar se atuará como motorista ou se receberá a carona \n=========\n");
	printf("\n Digite 1, caso seja um motorista \n Digite 2 para receber a carona\n");
	scanf ("%d", &choose);
	switch (choose){
		case 1:
			motorista (vetor1, j);
			break;
		case 2:
			carona (vetor1, j);
			break;
		default:
				system ("cls");
				printf ("Opção inválida!");
				
				break;
	}		
}

int login (struct usuarios vet[]){
	int i, cp, senha1;
	system ("cls");
	printf("=========================================================================\n");
	printf("+ @@@@@ @@@@  @        @       @@@@  @@@@    @     @@@    @@@  @  @   @ +\n");
    printf("+   @   @     @       @ @      @   @ @       @    @   @  @     @  @@  @ +\n");
    printf("+   @   @@@@  @      @   @     @   @ @@@@    @    @   @  @ @@  @  @ @ @ +\n");
    printf("+   @   @     @     @@@@@@@    @   @ @       @    @   @  @  @  @  @  @@ +\n");
    printf("+   @   @@@@  @@@@ @       @   @@@@  @@@@    @@@@  @@@    @@@  @  @   @ +\n");
    printf("=========================================================================\n");
	printf("DIGITE SEU CPF       =\nSEGUIDO DA SUA SENHA =\n");
	printf("======================\n");
	printf("\n");
	scanf ("%d\n", &cp);
	for (i=0; i < 100; i++){
		if (cp == vet[i].cpf){
			scanf ("%d", &senha1);
			if (senha1 == vet[i].senha){
				system ("cls");
				tela1 (vet, i);
			} else {
				system ("cls");
				printf ("Senha inválida.");
			}
			
		} else
			system ("cls"); 
			("CPF não registrado.");
	}
}

int registrar (struct usuarios vet[], int x){
	int i,cpfi, carru;
	printf("                              *********************************************************************************************************\n");
	printf("                              *  *****  *****  *         *        ****   *****    *****   *****   ****  *  **** ***** *****   ***     *\n");
	printf("                              *    *    *      *        * *       *   *  *        *   *   *      *      * *       *   *   *  *   *    *\n");
	printf("                              *    *    *****  *       *****      *   *  *****    ****    *****  * ***  *  ****   *   ****   *   *    *\n");
	printf("                              *    *    *      *      *     *     *   *  *        *   *   *      *   *  *      *  *   *   *  *   *    *\n");
	printf("                              *    *    *****  ***** *       *    ****   *****    *    *  *****   ****  *  ****   *   *    *  ***     *\n");
	printf("                              *********************************************************************************************************\n");
	printf("                              *                                                                                                       *\n");
	printf("                              *-----------------------------> INFORME SEU CPF (LIMITE DE 11 DIGITOS) <--------------------------------*\n");
	printf("\n");
	printf("                              ");
	scanf ("%d",&cpfi);
	for (i=0; i < 100; i++){
		if (vet[i].cpf == cpfi){
			printf ("CPF já registrado!\n");
			break;
		} else {
			vet[x].cpf = cpfi;
		}
	}
	printf("\n");
	fflush(stdin);
	printf("                              *---------------------------------------> INFORME SEU NOME <--------------------------------------------*\n");
	printf("\n");
	printf("                              ");
	fgets (vet[x].nome, 30, stdin);
	printf("\n");
	fflush(stdin);
	printf("                              *---------------------------------------> INFORME SEU EMAIL <-------------------------------------------*\n");
	printf("\n");
	printf("                              ");
	fgets (vet[x].email, 30, stdin);
	printf("\n");
	fflush(stdin);
	printf("                              *---------------------------------> INFORME SEU NÚMERO DE CELULAR <-------------------------------------*\n");
	printf("\n");
	printf("                              ");
	fgets (vet[x].numerocelular, 10, stdin);
	printf("\n");
	fflush(stdin);
	printf("                              *------------------------------> AGORA INFORME SEU ENDEREÇO E BAIRRO <----------------------------------*\n");
	printf("\n");
	printf("                              ");
	fgets (vet[x].end.bairro, 30, stdin);
	printf("\n");
	fflush(stdin);
	printf("                              *------------------------------> INFORME O COMPLEMENTO PARA O ENDEREÇO <---------------------------------*\n");
	printf("\n");
	printf("                              ");
	fgets (vet[x].end.complemento, 35, stdin);
	printf("\n");
	fflush(stdin);
	system("cls");
	printf("                                                      *******************************************************\n");
	printf("                                                      * #####     #      #####  #####  #####        ####### *\n");
	printf("                                                      * #    #   # #     #   #    #    #                  # *\n");
	printf("                                                      * #####   #####    ####     #    #####        ####### *\n");
	printf("                                                      * #      #     #   #   #    #    #            #       *\n");
	printf("                                                      * #     #       #  #    #   #    #####        ####### *\n");
	printf("                                                      *******************************************************\n");
	printf("\n");
	printf("                                                      VOCÊ POSSUI UM CARRO?\n");
	printf("\n");
	printf("                                                      ------------------------\n");
	printf("                                                      --> SE POSSUI DIGITE 1 -\n");
	printf("                                                      --> SE NÃO DIGITE 2    -\n");
	printf("                                                      ------------------------\n");
	printf("                                                      ");
	scanf ("%d", &carru);
	fflush(stdin);
	if (carru == 1){
		vet[x].carro = 1;
		system("cls");
		printf("                                              ====================================================================\n");
		printf("                                              *   ####  #####  #   #      ####     #      #####  #####    ###    *\n");
		printf("                                              *  #      #      #   #     #        # #     #   #  #   #   #   #   *\n");
		printf("                                              *   ####  #####  #   #     #       #####    ####   ####    #   #   *\n");
		printf("                                              *      #  #      #   #     #      #     #   #   #  #   #   #   #   *\n");
		printf("                                              *  ####   #####   ###       #### #       #  #    # #    #   ###    *\n");
		printf("                                              ====================================================================\n");
		printf("\n");
		printf("                                              *= DIGITE AS INFORMAÇÕES DO SEU CARRO || INFORME A PLACA DO CARRO =*\n");
		printf("\n");
		printf("                                              ");
		fgets (vet[x].car.placacarro, 8, stdin);
		fflush(stdin);
		printf("\n");
		printf("                                              *==================> INFORME O MODELO DO CARRO <===================*\n");
		printf("\n");
		printf("                                              ");
		fgets (vet[x].car.modelocarro, 15, stdin);
		fflush(stdin);
		printf("\n");
		printf("                                              *====================> INFORME A COR DO CARRO <====================*\n");
		printf("\n");
		printf("                                              ");
		fgets (vet[x].car.corcarro, 10, stdin);
		fflush(stdin);
		printf("\n");
		printf("                                              *=============> INFORME O ANO DE FABRICAÇÃO DO CARRO <=============*\n");
		printf("\n");
		printf("                                              ");
		scanf ("%d", &vet[x].car.anocarro);
		fflush(stdin);		
	}
	system("cls");
	printf("                                                    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("                                                    !  @@@@  @   @      @        @@@@  @@@@@  @   @  @  @     @     !\n");
	printf("                                                    ! @      @   @     @ @      @      @      @@  @  @  @    @ @    !\n");
	printf("                                                    !  @@@   @   @    @   @      @@@   @@@@@  @ @ @  @@@@   @   @   !\n");
	printf("                                                    !     @  @   @   @@@@@@@        @  @      @  @@  @  @  @@@@@@@  !\n");
	printf("                                                    ! @@@@    @@@   @       @   @@@@   @@@@@  @   @  @  @ @       @ !\n");
    printf("                                                    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("\n");
	printf("                                                    -> PARA COMPLETAR SEU CADASTRO <-\n");
	printf("                                                    -> CRIE UMA SENHA\n\n");
	printf("                                                    ");
	scanf ("%d", &vet[x].senha);
	fflush (stdin);
	system ("cls");	
}

main (){
	struct usuarios Usuariox [100];
	int z,k, num = 0;
	setlocale (LC_ALL, "Portuguese");
	int menu = 1;
	z = 0;
	do {
	system("MODE con cols=168 lines=60");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                                                                                                                                                 \n");
	printf("                                 **********************************************************************************************************\n");
	printf("                                 *                                                                             ################           *\n");
	printf("                                 *                                                                            #  ############  #          *\n");
	printf("                                 *              #     #        ###     #####     #####                       #  #            #  #         *\n");
	printf("                                 *             # #   # #      #   #    #   #     #                          #  #              #  #        *\n");
	printf("                                 *            #   # #   #     #   #    ####      #####                     #  #                #  #       *\n");
	printf("                                 *           #     #     #    #   #    #   #     #                      # #   ##################   # #    *\n");
	printf("                                 *          #             #    ###     #    #    #####                 #     ###              ###     #   *\n");
	printf("                                 *                                                                     #    #   #            #   #    #   *\n");
	printf("                                 *     #####   #####     #    #####   #   #   #####     #######        #     ###              ###     #   *\n");
	printf("                                 *     #       #   #     #    #       ##  #   #    #   #               #                              #   *\n");
	printf("                                 *     #####   ####      #    #####   # # #   #    #    ######         ###   ###################    ###   *\n");
	printf("                                 *     #       #   #     #    #       #  ##   #    #          #          #   #                  #   #     *\n");
	printf("                                 *     #       #    #    #    #####   #   #   #####    #######            ###                    ###      *\n");
	printf("                                 *                                                                                                        *\n");
	printf("                                 **********************************************************************************************************\n");
	printf("                                 *                            ->  Bem vindo ao aplicativo de carona solidária!  <-                        *\n");
	printf("                                 *                          -> Já possui uma conta? Digite 1 para realizar login! <-                      *\n");
	printf("                                 *                             -> É um novo usuário? Digite 2 para se registrar! <-                       *\n");
	printf("                                 *                                                                                                        *\n");
	printf("                                 *                                      >>>> Para sair, digite 0. <<<<                                    *\n");
	printf("                                 **********************************************************************************************************\n");
	printf("                                 ");
		if (z == 0){
			for (k = 0; k < 100; k++){
				Usuariox[k].dispmot = 0;
				Usuariox[k].dispcarona = 0;
				Usuariox[k].nota = 0;
				Usuariox[k].carro = 0;
				Usuariox[k].cpf = 0;
			}
		} // Isso inicializa algumas variáveis dos usuários do sistema como 0, limpando os eventuais lixos de memória 
		scanf ("%d", &menu);
		z++;
		system ("cls");
		switch (menu){
			case 1:
			login (Usuariox);
			break;		
			case 2: 
			registrar (Usuariox, num);
			num++;
			break;
			case 0:
			printf ("Obrigado por usar o aplicativo! Créditos - Equipe NAE Batedeira\n\n");
			break;
			default:
			printf ("Digite uma opção válida.\n\n");						
		}				 				
	} while (menu != 0);	
}
	

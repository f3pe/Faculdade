algoritmo "JOGO DA VELHA "
// Criadores: Marianna Ferreira Silva e Felipe Coutinho da Silva

//menu//
procedimento menu()
inicio
      repita
            escreval ("================ JOGO DA VELHA ======================")
            escreval("1) Humano x Humano")
            escreval("2) Humano x Maquina")
            escreval("3) Sair")
            leia(op)
            escolha op
                    caso 1
                         hxh()
                    caso 2
                         hxm()
                    caso 3
                         fimalgoritmo
                    outrocaso
                         escreva("opção invalida")
            fimescolha
      ate falso
fimprocedimento

 // Humano x Humano //
procedimento hxh()
inicio
      limpatela
      cont2 <- 1
      pre()
      escreva("Nome do jogador 1:")
      leia(nome)
      escreva ("Nome do jogador 2:")
      leia(nome2)
      escreval(nome," X ",nome2)
      escreval("Qual símbolo será utilizado pelo: ",nome,"?")
      escreval ("[X] ou [O]")
      leia(simbolo)
      se (simbolo = "X") ou (simbolo = "x") entao
         simbolo <- "X"
         simboloSec <- "O"
      senao
         simbolo <- "O"
         simboloSec <- "X"
      fimse
      visual()
      enquanto (cont2 <= 9) faca
               escreval("=======================")
               escreval ("VEZ DO JOGADOR 1")
               escreval("=====================")
               jogada()
               visual()
               verificar()
               escreval("========================")
               escreval ("VEZ DO JOGADOR 2")
               escreval("=======================")
               jogadaSec()
               visual()
               verificar()
               cont2 <- cont2 + 1
      fimenquanto
      menu()
fimprocedimento

//Humano x Maquina
procedimento hxm()
inicio
         limpatela
         cont2 <- 1
         pre()
         escreva("Nome do jogador:")
         leia(nome)
         escreval(nome," X Maquina")
         escreval("Qual símbolo será utilizado pelo: ",nome,"?")
         escreval ("[X] ou [O]")
         leia(simbolo)
         se (simbolo = "X") ou (simbolo = "x") entao
            simbolo <- "X"
            simboloSec <- "O"
         senao
            simbolo <- "O"
            simboloSec <- "X"
         fimse
         visual()
         enquanto (cont2 <= 9) faca
               escreval("=======================")
               escreval ("VEZ DO JOGADOR ")
               escreval("=====================")
               jogada()
               visual()
               verificar()
               escreval("========================")
               escreval ("VEZ DO COMPUTADOR")
               escreval("=======================")
               comp()
               visual()
               verificar()
               cont2 <- cont2 + 1
         fimenquanto
fimprocedimento

// verificação //
procedimento verificar()
var ok: logico
inicio
      para l de 1 ate 3 faca
         se (velha[l, 1] = simbolo) e (velha[l, 2] = simbolo) e (velha[l, 3] = simbolo) ou (velha[1, l] = simbolo) e (velha[2, l] = simbolo) e (velha[3, l ] = simbolo) ou (velha[1, 1] = simbolo) e (velha[2, 2] = simbolo) e (velha[3, 3] = simbolo) ou (velha[1, 3] = simbolo) e (velha[2, 2] = simbolo) e (velha[3, 1] = simbolo) entao
            escreval ("O jogador ", nome, " ganhou!!! ")
            menu()
         fimse
         se (velha[l, 1] = simboloSec) e (velha[l, 2] = simboloSec) e (velha[l, 3] = simboloSec) ou (velha[1, l] = simboloSec) e (velha[2, l] = simboloSec) e (velha[3, l] = simboloSec) ou (velha[1, 1] = simboloSec) e (velha[2, 2] = simboloSec) e (velha[3, 3] = simboloSec) ou (velha[1, 3] = simboloSec) e (velha[2, 2] = simboloSec) e (velha[3, 1] = simboloSec) entao
            se op = 1 entao
               escreval("O jogador ", nome2, " ganhou!!! ")
            senao
               escreval("O computador ganhou!!!")
            fimse
            menu()
         fimse
      fimpara
      ok <- falso
      para l de 1 ate 3 faca
           para c de 1 ate 3 faca
                se (velha[l, c] <> "X") e (velha[l, c] <> "O") entao
                   ok <- verdadeiro
                fimse
           fimpara
      fimpara
      se nao ok entao
         escreval("Deu velha!!!")
         menu()
      fimse
fimprocedimento

// preenchimento //
procedimento pre()
inicio
      n <- 0
      para l de 1 ate 3 faca
           para c de 1 ate 3 faca
                n <- n + 1
                velha[l, c] <- numpcarac(n)
           fimpara
      fimpara
fimprocedimento

// interface //
procedimento visual()
inicio
   escreval("+-------+-------+-------+")
   para l de 1 ate 3 faca
      para c de 1 ate 3 faca
         escreva ("|   ")
         escreva(velha[l,c]:4)
      fimpara
      escreval("|  ")
      escreval("+-------+-------+-------+")
   fimpara
fimprocedimento

// jogada //
procedimento jogada()
var n: caracter
inicio
      valido <- falso
      repita
         Escreval("Digite em qual posição jogar")
         leia(n)
            para l de 1 ate 3 faca
                 para c de 1 ate 3 faca
                      se (n = velha[l, c]) entao
                         velha[l, c] <- simbolo
                         valido <- verdadeiro
                      fimse
                 fimpara
            fimpara
         se não valido entao
            escreval("jogada invalida")
         fimse
      ate valido
fimprocedimento

// jogada do segundo jogador //
procedimento jogadaSec()
var n: caracter
inicio
   valido <- falso
      repita
         Escreval("Digite em que posição escolhe jogar jogo")
         leia(n)
            para l de 1 ate 3 faca
                 para c de 1 ate 3 faca
                      se (n = velha[l, c])  entao
                         velha[l,c] <- simboloSec
                         valido <- verdadeiro
                      fimse
                 fimpara
            fimpara
         se não valido entao
            escreval("jogada invalida")
         fimse
      ate valido
fimprocedimento

// jogada do computador //
procedimento comp()
inicio
   aleatorio 1, 3
   valido <- falso
   repita
      leia(l)
      leia(c)
      se (velha[l, c] <> "X") e (velha[l, c] <> "O") entao
         velha[l, c] <- "O"
         valido <- verdadeiro
      fimse
   ate valido
   limpatela
   aleatorio off
fimprocedimento

var
nome, nome2, simbolo, simboloSec, op3: caractere
velha: vetor [1..3,1..3] de caractere
l, c, op, op1, op2, cont2, n: inteiro
cont, valido: logico

inicio
menu()
fimalgoritmo

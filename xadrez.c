/* xadrez.c — Nível MESTRE 
   - Torre: recursão (5x "Direita")
   - Bispo: recursão (5x "Cima Direita") E também com loops aninhados
     (externo = vertical; interno = horizontal)
   - Rainha: recursão (8x "Esquerda")
   - Cavalo: loops aninhados + múltiplas condições + continue/break
     (EXATAMENTE 1 movimento em L para CIMA e DIREITA → Cima, Cima, Direita)
*/

#include <stdio.h>

/* ------------------------- PARÂMETROS (entradas no código) ------------------------- */
enum {
    TORRE_PASSOS   = 5,  // 5 Direita
    BISPO_PASSOS   = 5,  // 5 Cima Direita
    RAINHA_PASSOS  = 8,  // 8 Esquerda
    CAVALO_L_MOVES = 1   // EXATAMENTE 1 movimento em L (↑↑→), conforme enunciado
};

/* =============================== RECURSIVIDADE =============================== */
/* padrão: condição de parada → imprime 1 passo → chama com (passos-1) */

void torre_rec(int passos) {
    if (passos <= 0) return;
    printf("Direita\n");
    torre_rec(passos - 1);
}

void bispo_rec(int passos) {
    if (passos <= 0) return;
    printf("Cima Direita\n");
    bispo_rec(passos - 1);
}

void rainha_rec(int passos) {
    if (passos <= 0) return;
    printf("Esquerda\n");
    rainha_rec(passos - 1);
}

/* =========================== LOOPS ANINHADOS PEDIDOS =========================== */
/* Bispo com loops aninhados:
   - externo = vertical (CIMA) controla a quantidade de casas
   - interno = horizontal (DIREITA) faz o componente lateral de cada passo
*/
void bispo_loops_aninhados(int passos) {
    for (int up = 0; up < passos; up++) {          // vertical
        for (int right = 0; right < 1; right++) {  // horizontal (1 por passo)
            printf("Cima Direita\n");
        }
    }
}

/* Cavalo — loops complexos (aninhados + múltiplas condições + continue/break)
   1 movimento em L para CIMA e DIREITA  → 2x "Cima" + 1x "Direita"
*/
void cavalo_L_complexo(int movimentos) {
    if (movimentos <= 0) return;

    for (int m = 0; m < movimentos; m++) {   // cada iteração = 1 "L"
        if (movimentos > 1000) {             // proteção ilustrativa
            puts("Quantidade de movimentos muito alta — interrompendo.");
            break;
        }

        for (int seg = 0; seg < 3; seg++) {  // seg 0 e 1 = Cima; seg 2 = Direita
            if (seg < 2) {
                printf("Cima\n");
                continue;                    // passa direto para o próximo segmento
            }
            if (seg == 2) {
                printf("Direita\n");
                // poderia haver um break aqui se quiséssemos encerrar antes
            }
        }
    }
}

/* =================================== MAIN =================================== */
int main(void) {
    puts("TORRE (recursiva) — 5x Direita:");
    torre_rec(TORRE_PASSOS);

    puts("");

    puts("BISPO (recursiva) — 5x Cima Direita:");
    bispo_rec(BISPO_PASSOS);

    puts("");

    puts("RAINHA (recursiva) — 8x Esquerda:");
    rainha_rec(RAINHA_PASSOS);

    puts("");

    puts("BISPO (loops aninhados) — 5x Cima Direita:");
    bispo_loops_aninhados(BISPO_PASSOS);

    puts("");

    puts("CAVALO (loops complexos) — 1 movimento em L (Cima, Cima, Direita):");
    cavalo_L_complexo(CAVALO_L_MOVES);

    return 0;
}

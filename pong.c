#include <stdio.h>

int printSchet(int chet1, int chet2);
int printTable(int raketka1, int raketka2, int shari, int sharj);
int updatestatewithstenka(int lr, int shari);
int updatestatewithraketka(int raketka1, int raketka2, int lr, int shari, int sharj);
int updatestatewithstenkagorizont(int ud, int shari);
int victory(int user);

int printTable(int raketka1, int raketka2, int shari, int sharj) {
  int i, j;
  for (i = 0; i < 23; i++) {
    if (i == 0 || i == 22)
      for (j = 0; j < 80; j++)
        if (j == 0 || j == 79)
          printf("+");
        else {
          printf("-");
        }
    else {
      printf("|");
      for (j = 1; j < 79; j++)
        if ((j == 3 && (i >= raketka1 && i <= raketka1 + 2)) || (j == 76 && (i >= raketka2 && i <= raketka2 + 2))) {
          printf("|");
        }
      else if (j == sharj && i == shari) {
        printf("o");
      } else {
        printf(" ");
      }
      printf("|");
    }
    printf("\n");
  }
  return 0;
}

int printSchet(int chet1, int chet2) {
  int i, j;
  for (i = 0; i < 2; i++) {
    if (i == 1) {
      for (j = 0; j < 80; j++) {
        printf("-");
      }
    } else {
      printf("|");
      for (j = 1; j < 79; j++) {
        if ((chet1 > 9 && chet2 > 9) && j == 36) {
          printf("%d : %d", chet1, chet2);
          j = j + 6;
        } else if ((chet1 <= 9 && chet2 > 9) && j == 37) {
          printf("%d : %d", chet1, chet2);
          j = j + 5;
        } else if ((chet1 > 9 && chet2 <= 9) && j == 36) {
          printf("%d : %d", chet1, chet2);
          j = j + 5;
        } else if ((chet1 <= 9 && chet2 <= 9) && j == 37) {
          printf("%d : %d", chet1, chet2);
          j = j + 4;
        } else {
          printf(" ");
        }
      }
      printf("|");
    }

    printf("\n");
  }
  return 0;
}

int main() {
  int raketka1 = 10, raketka2 = 10, shari = 12, sharj = 72, schet1 = 0, schet2 = 0;
  char symbol = ' ';
  char enter;
  int lr = 1;
  int ud = 1;
  int stenka;
  printTable(raketka1, raketka2, shari, sharj);
  printSchet(schet1, schet2);
  while (symbol != 'e') {
    scanf("%c%c", & symbol, & enter);
    if (symbol == 'a' || symbol == 'A') {
      if (raketka1 != 1) raketka1 -= 1;
    } else if (symbol == 'z' || symbol == 'Z') {
      if (raketka1 != 19) raketka1 += 1;
    } else if (symbol == 'k' || symbol == 'K') {
      if (raketka2 != 1) raketka2 -= 1;
    } else if (symbol == 'm' || symbol == 'M') {
      if (raketka2 != 19) raketka2 += 1;
    } else if (symbol == 'e') {
      return 0;
    } else if (symbol == ' ') {}
    shari = shari + ud;
    sharj = sharj + lr;
    stenka = updatestatewithstenka(lr, sharj);
    if (stenka > 0) {
      if (stenka == 1)
        if (schet1 < 20) {
          schet1 += 1;
          shari = 11;
          sharj = 75;
          lr = -1;
        }
      else
        victory(1);
      if (stenka == 2)
        if (schet2 < 20) {
          schet2 += 1;
          shari = 11;
          sharj = 5;
          lr = 1;
        }
      else
        victory(2);
    }
    if (updatestatewithraketka(raketka1, raketka2, lr, shari, sharj) == 1)
      lr = -lr;

    if (updatestatewithstenkagorizont(ud, shari) == 1)
      ud = -ud;

    printTable(raketka1, raketka2, shari, sharj);
    printSchet(schet1, schet2);
  }
  return 0;
}

int updatestatewithstenka(int lr, int sharj) {
  sharj = sharj + lr;
  if (sharj < 1) {
    return 2;
  }
  if (sharj > 78) {
    return 1;
  }
  return 0;
}

int updatestatewithraketka(int raketka1, int raketka2, int lr, int shari, int sharj) {
  if ((shari >= raketka1 && shari <= raketka1 + 2) && (sharj == 3 - lr))
    return 1;
  if ((shari >= raketka2 && shari <= raketka2 + 2) && (sharj == 76 - lr))
    return 1;
  return 0;
}

int updatestatewithstenkagorizont(int ud, int shari) {
  if (shari == 0 - ud)
    return 1;
  if (shari == 22 - ud)
    return 1;
  return 0;
}

int victory(int user) {
  printf("Winner %d ", user);
  return 0;
}
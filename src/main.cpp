#include <iostream>
#include <vector>

char player_1 = 'X';
  char player_2 = 'O';
  int coordinates_1;
  int coordinates_2;
  bool bFaild; 
  char field[3][3] = {{'.','.','.'}, 
                       {'.','.','.'},
                       {'.','.','.'}};


bool winner(char arr[3][3]){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(((arr[0][0] == 'X') && (arr[0][1] == 'X') && (arr[0][2] == 'X')) || 
         ((arr[1][0] == 'X') && (arr[1][1] == 'X') && (arr[1][2] == 'X')) ||
         ((arr[2][0] == 'X') && (arr[2][1] == 'X') && (arr[2][2] == 'X')) ||

         ((arr[0][0] == 'X') && (arr[1][0] == 'X') && (arr[2][0] == 'X')) ||
         ((arr[0][1] == 'X') && (arr[1][1] == 'X') && (arr[2][1] == 'X')) ||
         ((arr[0][2] == 'X') && (arr[1][2] == 'X') && (arr[2][2] == 'X')) ||

         ((arr[0][0] == 'X') && (arr[1][1] == 'X') && (arr[2][2] == 'X')) ||
         ((arr[2][0] == 'X') && (arr[1][1] == 'X') && (arr[0][2] == 'X'))){
        std::cout << "Player 1 won" << std::endl;
        return true;
      }else if(((arr[0][0] == 'O') && (arr[0][1] == 'O') && (arr[0][2] == 'O')) || 
               ((arr[1][0] == 'O') && (arr[1][1] == 'O') && (arr[1][2] == 'O')) ||
               ((arr[2][0] == 'O') && (arr[2][1] == 'O') && (arr[2][2] == 'O')) ||

               ((arr[0][0] == 'O') && (arr[1][0] == 'O') && (arr[2][0] == 'O')) ||
               ((arr[0][1] == 'O') && (arr[1][1] == 'O') && (arr[2][1] == 'O')) ||
               ((arr[0][2] == 'O') && (arr[1][2] == 'O') && (arr[2][2] == 'O')) ||

               ((arr[0][0] == 'O') && (arr[1][1] == 'O') && (arr[2][2] == 'O')) ||
               ((arr[2][0] == 'O') && (arr[1][1] == 'O') && (arr[0][2] == 'O'))){
                std::cout << "Player 2 won" << std::endl;
                return true;
      }
      else {
        // std::cout << "Draw" << std::endl;
        return false;
      }
    }    
  }
}

void print(char arrShow[3][3]){
   for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      std::cout << arrShow[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void player(){
  while (!winner(field))  {
    std::cout << "Player's turn: 1" << std::endl;
    std::cin >> coordinates_1;
    std::cin >> coordinates_2;
    if(field[coordinates_1][coordinates_2] != 'X' && 
       field[coordinates_1][coordinates_2] != 'O'){
          field[coordinates_1][coordinates_2] = player_1;
          print(field);
          if(winner(field) == true){
            break;
          }
    }else{
      std::cout << "This cell is occupied" << std::endl;
      // bFaild = true;
      // player();
      break;
    }
      std::cout << "Player's turn: 2" << std::endl;
      std::cin >> coordinates_1;
      std::cin >> coordinates_2;
      if(field[coordinates_1][coordinates_2] != 'X' && 
        field[coordinates_1][coordinates_2] != 'O'){
        field[coordinates_1][coordinates_2] = player_2;
        print(field);
        if(winner(field) == true){
          break;
        }
      }else {
        std::cout << "This cell is occupied" << std::endl;
      // bFaild = true;
      // player();
      break;
      }
    }
  }

int main(){
  std::cout << "Tic-tac-toe_v.2" << std::endl;
  player();
  // if(bFaild){
  //   player();
  //   bFaild = false;
  // } 
  
  return 0;
}


// Крестики-нолики

// Старинная-добрая игра на страницах всех школьных тетрадей. 
// Поле размером 3х3 представлено в виде двумерного массива 
// с типом элементов char. Помните тот символьный тип из 
// предыдущего модуля? Теперь он нам и пригодится. 
// Участвуют два игрока, которые ходят по очереди и ставят 
// в указанные ими в стандартном вводе координаты свой 
// символ - ‘X’ или ‘O’ (буквы латинского алфавита). 
// Как только у одного из игроков будет установлено 
// подряд три крестика или три нолика - он побеждает. 
// Если свободных клеток не осталось, а трёх совпадающих 
// элементов не найдено - объявляется ничья. 
// Для простоты, мы не будем рассматривать диагональные 
// совпадения, а только строго вертикальные 
// либо строго горизонтальные.

// Изначально всё поле инициализируется символом 
// пробела - ‘ ‘. Это можно сделать сразу при объявлении, 
// либо с помощью вложенного цикла. На каждом ходе, при занятой клетке 
// или при неверных координатах этой клетки должно быть выведено 
// сообщение и игрок должен указать координаты клетки повторно. 
// После каждого хода надо выводить в консоль текущее состояние 
// всего игрового поля, для наглядности.

// Сделаю ещё одну небольшую подсказку. Проверку на победу игрока, 
// которую надо осуществлять после каждого хода, можно сделать 
// с помощью вложенного цикла, сразу проверяя и вертикаль и 
// горизонталь а как именно - попробуйте догадаться сами.
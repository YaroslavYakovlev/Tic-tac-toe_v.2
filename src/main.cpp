#include <iostream>
#include <vector>

char player_1 = 'X';
char player_2 = 'O';
int coordinates_1;
int coordinates_2;
int countStep = 0;
bool bWon = false;
char field[3][3] = {{'.','.','.'}, 
                    {'.','.','.'},
                    {'.','.','.'}};

// bool isWinner(char arr[3][3], char ch, int countStep){
//   if(countStep == 9){
//     std::cout << "Draw" << std::endl;
//     return true;
//   }
//   for(int i = 0; i < 3; i++){
//     for(int j = 0; j < 3; j++){
//       if(((arr[i][0] == ch) && (arr[i][1] == ch) && (arr[i][2] == ch)) || 
//         //  ((arr[1][0] == ch) && (arr[1][1] == ch) && (arr[1][2] == ch)) ||
//         //  ((arr[2][0] == ch) && (arr[2][1] == ch) && (arr[2][2] == ch)) ||
 
//          ((arr[0][j] == ch) && (arr[1][j] == ch) && (arr[2][j] == ch)) ||
//         //  ((arr[0][1] == ch) && (arr[1][1] == ch) && (arr[2][1] == ch)) ||
//         //  ((arr[0][2] == ch) && (arr[1][2] == ch) && (arr[2][2] == ch)) ||

//          ((arr[0][0] == ch) && (arr[1][1] == ch) && (arr[2][2] == ch)) ||
//          ((arr[2][0] == ch) && (arr[1][1] == ch) && (arr[0][2] == ch))){
//            if(ch == 'X'){
//             std::cout << "Player 1 won" << std::endl;
//             bWon = true;
//             return true;
//            }else {
//              std::cout << "Player 2 won" << std::endl;
//              bWon = true;
//              return true;
//            }
//       }else {
//         return false;
//       }
//     }    
//   }
// }

bool isWinner(char ch, int countStep){
  if(countStep == 9){
    std::cout << "Draw" << std::endl;
    return true;
  }
  for (int i = 0; i < 3; ++i) {
    bool all_match_horizontal = true;
    bool all_match_vertical = true;
    for (int j = 0; j < 3; ++j) {
      if (field[i][j] != ch)
        all_match_horizontal = false;
      if (field[j][i] != ch)
        all_match_vertical = false;
    }
    if (all_match_horizontal || all_match_vertical) {
      std::cout << "YOU WIN!" << std::endl;
      return true;
    }else return false;
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

bool stepPlayer(char ch){
   do {
    std::cin >> coordinates_1;
    std::cin >> coordinates_2;
    }while(((coordinates_1 > 2 || coordinates_1 < 0) || 
      (coordinates_2 > 2 || coordinates_2 < 0)) || 
       (field[coordinates_1][coordinates_2] == 'X' 
        && (field[coordinates_1][coordinates_2] == 'O')));
    // if(field[coordinates_1][coordinates_2] != 'X' && 
    //    field[coordinates_1][coordinates_2] != 'O'){
        countStep++;
        field[coordinates_1][coordinates_2] = ch;
        print(field);
        if(isWinner(ch, countStep)){
          return true;
        }
      // }else{
      //   std::cout << "This cell is occupied" << std::endl;
      // }
}

int main(){
  std::cout << "Tic-tac-toe_v.2" << std::endl;
  while(true){
    std::cout << "Player's turn: 1" << std::endl;
    if(stepPlayer(player_1)){
      break;
    } 
    std::cout << "Player's turn: 2 " << std::endl;
    if(stepPlayer(player_2)){
      break;
    } 
  }
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
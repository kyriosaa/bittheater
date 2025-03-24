#include <Arduino.h>
#include "ASCIISymbols.h"

// "Konnichiwa" symbols (コンニチハ!)
byte konnichiwaSymbols[6] = {
  0xBA, // コ
  0xDD, // ン
  0xC6, // ニ
  0xC1, // チ
  0xCA, // ハ
  0x21, // !
};

// "Genki desu ka" symbols (オゲンキデスカ?)
byte genkiSymbols[10] = {
  0xB5, // オ
  0xB9, // ケ
  0xDE, // ゛
  0xDD, // ン
  0xB7, // キ
  0xC3, // テ
  0xDE, // ゛
  0xBD, // ス
  0xB6, // カ
  0x3F, // ?
};

// "Watashi wa ramen o" symbols (ワタシハラーメンヲ)
byte ramenSymbols[9] = {
  0xDC, // ワ
  0xC0, // タ
  0xBC, // シ
  0xCA, // ハ
  0xD7, // ラ
  0xB0, // ー
  0xD2, // メ
  0xDD, // ン
  0xA6, // ヲ
};

// "Taberu no ga sukidesu" symbols (タベルノガスキデス)
byte sukidesuSymbols[12] = {
  0xC0, // タ
  0xCD, // ヘ
  0xDE, // ゛
  0xD9, // ル
  0xC9, // ノ
  0xB6, // カ
  0xDE, // ゛
  0xBD, // ス
  0xB7, // キ
  0xC3, // テ
  0xDE, // ゛
  0xBD, // ス
};
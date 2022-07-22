// inputに入力データ全体が入る
function Main(input) {
// 1行目がinput[0], 2行目がinput[1], …に入る
  x = Number(input);
  m = 100;
  y = 0;
  while(m < x){
    m = Math.floor(m * 1.01);
    y++
  }
  console.log(y);
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

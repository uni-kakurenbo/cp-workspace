// inputに入力データ全体が入る
function Main(input) {
// 1行目がinput[0], 2行目がinput[1], …に入る
　input = input.split("\n");
  k = ~~input[0]
　a = ~~input[1].split(" ")[0];
  b = ~~input[1].split(" ")[1];
  let i=k;
  while (i <= b){
    if(i >= a && i <= b ){
      console.log("OK");
      return;
    }
    i += k;
  }
  console.log("NG")
  return;
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

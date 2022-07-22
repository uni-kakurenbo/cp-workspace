// inputに入力データ全体が入る
function Main(input) {
  　input = Number(input)
    var num = 1000000007
    var P = 1;
    for(var i = 1; i <= input; i++){
      P *= Number(i)
      P %= num
    }
    console.log(P)
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

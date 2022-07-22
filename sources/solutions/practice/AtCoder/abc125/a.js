// inputに入力データ全体が入る
function Main(input) {
	input = input.split("\n");
  	input = input[0].split(" ");
    var A = Number(input[0])
    var B = Number(input[1])
    var T = Number(input[2])
    var time = 1;
    var sum = 0;
	for(var i=0; i<=(T+0.5); i++ ){
      if(i == time*A){
         sum += B;
         time++;
      }
    }
    console.log(sum)
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

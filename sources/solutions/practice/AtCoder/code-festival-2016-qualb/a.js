// inputに入力データ全体が入る
function Main(input) {
    var str = "CODEFESTIVAL2016"
	input = input.split("\n");
  	input = input[0].split("");
  	str = str.split("\n");
    str = str[0].split("");
    var index = 0;
    var sum=0;
    for(l of input){
      if(l != str[index]){
        sum++;
      }
      index++;
    }
	console.log(sum);
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

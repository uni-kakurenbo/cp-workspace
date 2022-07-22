// inputに入力データ全体が入る
function Main(_inputStr) {
  const input = _inputStr
    .trim().split("\n")
    .map(_row => {
      return _row.trim().split("")
        .map(_item => {const _num = Number(_item); return isNaN(_num) ? _item : _num})
    })
  //console.log(input)
  let [X] = input;
  if(new Set(X).size === 1) return console.log("Weak")
  let c = 0;
  for(let i = 0; i < 3; i++) {
    //console.log(X[i], X[i + 1] % 9 + 1)
    if(X[i + 1] === (X[i] + 1) % 10) c++;
  }
  //console.log(c)
  if(c >= 3) return console.log("Weak")
  else console.log("Strong")
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

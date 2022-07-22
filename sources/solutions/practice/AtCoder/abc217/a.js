// inputに入力データ全体が入る
function Main(_inputStr) {
  const input = _inputStr
    .trim().split("\n")
    .map(_row => {
      return _row.trim().split(/\s+/)
        .map(_item => {const _num = Number(_item); return isNaN(_num) ? _item : _num})
    })
  //console.log(input)
  let [[S, T]] = input;
  const A = [S, T]
  //console.log(A)
  if(S === A.sort()[0]) console.log("Yes")
  else console.log("No")
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

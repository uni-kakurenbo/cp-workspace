// inputに入力データ全体が入る
function Main(_inputStr) {
  const input = _inputStr
    .trim().split("\n")
    .map(_row => {
      return _row.trim().split(/\s+/)
        .map(_item => {const _num = Number(_item); return isNaN(_num) ? _item : _num})
    })
  //console.log(input)
  let [[N]] = input;
  if(N < 126) console.log("4")
  else if(N < 212) console.log("6")
  else console.log("8")
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

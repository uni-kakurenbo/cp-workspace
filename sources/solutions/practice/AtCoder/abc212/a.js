// inputに入力データ全体が入る
function Main(_inputStr) {
  const input = _inputStr
    .trim().split("\n")
    .map(_row => {
      return _row.trim().split(/\s+/)
        .map(_item => {const _num = Number(_item); return isNaN(_num) ? _item : _num})
    })
  //console.log(input)
  let [[A, B]] = input;
  if(0 < A && B === 0) console.log("Gold")
  else if (A === 0 && 0 < B) console.log("Silver")
  else console.log("Alloy")
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

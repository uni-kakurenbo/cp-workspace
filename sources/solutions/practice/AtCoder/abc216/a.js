// inputに入力データ全体が入る
function Main(_inputStr) {
  const input = _inputStr
    .trim().split("\n")
    .map(_row => {
      return _row.trim().split(".")
        .map(_item => {const _num = Number(_item); return isNaN(_num) ? _item : _num})
    })
  //console.log(input)
  let [[X, Y]] = input;
  if(Y <= 2) {
    console.log(String(X)+"-")
  } else if (3 <= Y && Y <= 6) {
    console.log(X)
  } else {
    console.log(String(X)+"+")
  }
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

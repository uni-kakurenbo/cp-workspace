// inputに入力データ全体が入る
function Main(_inputStr) {
  const input = _inputStr
    .trim().split("\n")
    .map(_row => {
      return _row.trim().split(/\s+/)
        .map(_item => {const _num = Number(_item); return isNaN(_num) ? _item : _num})
    })
  //console.log(input)
  let [[A, B, C]] = input;
  let ans = null;
  for(i = Math.floor(A/C); C * i <= B; i++) {
    const x = i * C;
    if(A <= x && x <= B) {
      ans = x;
      break;
    }
  }
  if(ans) console.log(ans);
  else console.log("-1")
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

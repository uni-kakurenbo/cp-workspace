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
  let ans = 0;
  [...Array(S + 1)].forEach((_, _a) => {
    [...Array(S - _a + 1)].forEach((_, _b) => {
      [...Array(S - _a - _b + 1)].forEach((_, _c) => {
        if(_a * _b * _c <= T) {ans++; return false}
        else return true;
      })
    })
  })
  console.log(ans)
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

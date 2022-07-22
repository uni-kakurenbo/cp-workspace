// inputに入力データ全体が入る
function Main(_inputStr) {
  const input = _inputStr
    .trim().split("\n")
    .map(_row => {
      return _row.trim().split(/\s+/)
        .map(_item => {const _num = Number(_item); return isNaN(_num) ? _item : _num})
    })
  //console.log(input)
  let [[N, M], A, B] = input;
  let index_A = 0, index_B = 0;
  const L = M + N;
  let C = A.concat(B)
  C.sort((a, b) => a - b);
  console.log(C.join("\n"))
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

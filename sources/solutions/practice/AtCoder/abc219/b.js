// inputに入力データ全体が入る
function Main(_inputStr) {
  const input = _inputStr
    .trim().split("\n")
    .map(_row => {
      return _row.trim().split(/\s+/)
        //.map(_item => {const _num = Number(_item); return isNaN(_num) ? _item : _num})
    })
  //console.log(input)
  let [[S1], [S2], [S3], [T]] = input;
  S = [S1, S2, S3];
  let ans = "";
  [...T].forEach(_t => {
    ans += S[Number(_t - 1)]
  })
  console.log(ans)
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
